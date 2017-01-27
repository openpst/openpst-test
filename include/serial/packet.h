/**
* LICENSE PLACEHOLDER
*
* @file packet.h
* @package openpst/libopenpst
* @brief Represents a packet to be sent over serial that 
*   allows for some dynamic packet creation
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <fstream>
#include <iterator>
#include <sstream>

namespace OpenPST {
    namespace Serial {
        
        enum PacketEndianess{
            kPacketEndianessLittle,
            kPacketEndianessBig,
            kPacketEndianessLast      // last entry, equal or over is invalid
        };

        enum PacketTargetArch{
            kPacketTargetArchUnknown,
            kPacketTargetArchX86,
            kPacketTargetArchX86_64,
            kPacketTargetArchArm,
            kPacketTargetArchAArch64,
            kPacketTargetArchLast      // last entry, equal or over is invalid
        };

        enum PacketFieldType {
            kPacketFieldTypePrimitive, // a primitive type
            kPacketFieldTypeArray,    // a byte type
            kPacketFieldTypeVariant,  // a variable length type
            kPacketFieldTypeLast     // last entry, equal or over is invalid
        };

        struct PacketFieldMeta {
            PacketFieldType type;
            std::string name;
            size_t size;
        };

        class Packet
        {
            protected:
                /* @var Endianess of target device */
                PacketEndianess endianT = kPacketEndianessLittle;

                /* @var Endianess of host device */
                PacketEndianess endianH = kPacketEndianessLittle;
                
                /* @var Architecture of the target device */
                PacketTargetArch archT = kPacketTargetArchUnknown;
                
                /* @var The maximum size the data occupy */
                size_t maxDataSize    = 0;

                /* @var If this packet expects a response or not */
                bool responseExpected = true;

                /* @var The resulting response, if available */
                Packet* response = nullptr;

                std::vector<PacketFieldMeta> fieldMeta;

                /* @var The underlying data of the packet to be sent */
                std::vector<uint8_t> data;
            public:
                /**
                * @brief Constructor
                */
                Packet(size_t maxDataSize);
                
                /**
                * @brief Destructor
                */
                ~Packet();
                
                /**
                * @brief Set the target endianess
                *
                * @param PacketEndianess e
                * @return void
                */
                void setTargetEndianess(PacketEndianess e);

                /**
                * @brief Get the target endianess
                *
                * @return PacketEndianess
                */
                PacketEndianess getTargetEndianess();

                /**
                * @brief Set the host endianess
                *
                * @param PacketEndianess e
                * @return void
                */
                void setHostEndianess(PacketEndianess e);

                /**
                * @brief Get the host endianess
                *
                * @return PacketEndianess
                */
                PacketEndianess getHostEndianess();

                /**
                * @brief Get the target architecture
                *
                * @return PacketTargetArch
                */
                PacketTargetArch getTargetArch();

                /**
                * @brief Set the target architecture
                * @param PacketTargetArch arch
                * @return void
                */
                void setTargetArch(PacketTargetArch arch);

                /**
                * @brief Get the flag that this packet will require a response
                * @return bool
                */
                bool isResponseExpected();

                /**
                * @brief Set the flag that this packet will require a response
                * @param bool 
                * @return void
                */
                void setResponseExpected(bool v);

                /**
                * @brief Get the response packet, if it has been unpacked
                */
                Packet* getResponse();

                /**
                * @brief Get the max data size this packet can be
                * @return size_t
                */
                virtual size_t getMaxDataSize();

                /**
                * @brief Add a field to the packet
                * @param const std::string& name
                * @param PacketFieldType type
                * @param size_t size
                * @return void
                */
                void addField(const std::string& name, PacketFieldType type, size_t size);
                
                /**
                * @brief Add a field to the packet
                * @param PacketFieldMeta field
                * @return void
                */
                void addField(PacketFieldMeta field);

                /**
                * @brief Check if a field exists by name
                * @param const std::string& name
                * @return bool
                */
                bool hasField(const std::string& name);

                /**
                * @brief Check if a field exists by index
                * @param const std::string& name
                * @return bool
                */
                bool hasField(int index);

                /**
                * @brief Get a declared field meta information by name
                * @param const std::string& name
                * @throws std::invalid_argument
                * @return const PacketFieldMeta*
                */
                PacketFieldMeta* getField(const std::string& name);
                
                /**
                * @brief Get a declared field meta information by zero based index
                * @param int index
                * @throws std::invalid_argument
                * @return const PacketFieldMeta*
                */
                PacketFieldMeta* getField(int index);

                /**
                * @brief Get all declared field meta information.
                * @param const std::string& name
                * @throws std::invalid_argument
                * @return const std::vector<PacketFieldMeta>&
                */
                const std::vector<PacketFieldMeta>& getFields();

                /**
                * @brief Returns the current size of the data in the packet
                * @return size_t
                */
                size_t size();

                /**
                * @brief Get the total size of the packet based on field meta data
                * @return size_t
                */
                size_t getFieldMetaSize();

                /**
                * @brief Get a reference to the underlying data buffer
                * @return const std::vector<uint8_t>&
                */
                std::vector<uint8_t>& getData();

                /**
                * @brief Validate the data in the packet buffer
                */
                virtual void validate() {}

                /**
                * @brief Prepare the packet before sending, making and final adjustments, for example crc
                */
                virtual void prepare() {}

                /**
                * @brief Prepare the response packet before unpacking into the response packet
                */
                virtual void prepareResponse() {}

                /**
                * @brief Unpack a buffer into the packet
                */
                virtual void unpack(std::vector<uint8_t>& data) = 0;

            protected:
                /**
                * @brief Read primitive type T from the data buffer at offset
                * @param off_t offset
                * @throws std::out_of_range 
                * @return T
                */
                template <class T> inline T read(off_t offset) 
                {
                    assert(std::is_fundamental<T>::value);

                    if ((offset + sizeof(T)) > data.size()) {
                        throw std::out_of_range("Attempted to read outside of the packet data buffer");
                    }

                    T* p = reinterpret_cast<T*>(&data[offset]);
                    
                    if (sizeof(T) != sizeof(uint8_t) && getTargetEndianess() != getHostEndianess()) {
                        return swap<T>(*p);
                    }

                    return *p;
                }

                /**
                * @brief Read string from the data buffer at offset until 0x00 or end of buffer
                * @param off_t offset
                * @throws std::out_of_range 
                * @return T
                */
                inline std::string read(size_t size, off_t offset) 
                {
                    if ((offset + size) > data.size()) {
                        throw std::out_of_range("Attempted to read outside of the packet data buffer");
                    }

                    std::string ret( data.begin() + offset, data.begin() + offset + size );

                    return ret;
                }

                /**
                * @brief Write primitive type T into the data buffer at offset
                * @param const T& value
                * @param off_t offset
                * @return void
                */
                template <class T> inline void write(const std::string& fieldName, const T& value)
                {
                    assert(std::is_fundamental<T>::value);
                    
                    auto field = getField(fieldName);

                    if (field->type != kPacketFieldTypeVariant && field->size > sizeof(T)) {
                        throw std::invalid_argument("Write data is larger than static field size");
                    }
                    
                    T* p = reinterpret_cast<T*>(&data[getFieldOffset(field->name)]);

                    if (sizeof(T) != sizeof(uint8_t) && getTargetEndianess() != getHostEndianess()) {
                        *p = swap<T>(value);
                    } else {
                        *p = value;
                    }
                }

                /**
                * @brief Write string in the data buffer at offset
                * @return void
                */
                inline void write(const std::string& fieldName, const std::string& str)
                {   
                    auto field = getField(fieldName);

                    if (field->type != kPacketFieldTypeVariant && field->size > str.size()) {
                        throw std::invalid_argument("Write data is larger than static field size");
                    } else if(field->type == kPacketFieldTypeVariant && field->size != str.size()) {
                        resizeField(field, str.size());
                    }

                    std::copy(str.begin(), str.end(), data.begin() + getFieldOffset(fieldName));
                }

                /**
                * @brief Write specified size of bytes from src into the data buffer at offset
                * @return void
                */
                inline void write(const std::string& fieldName, uint8_t* src, size_t size)
                {
                    auto field = getField(fieldName);
                    
                    if (field->type != kPacketFieldTypeVariant && field->size > size) {
                        throw std::invalid_argument("Write data is larger than static field size");
                    } else if(field->type == kPacketFieldTypeVariant && field->size != size) {
                        resizeField(field, size);
                    }

                    std::copy(src, src + size, data.begin() + getFieldOffset(fieldName));
                }

                /**
                * @brief Write file content in the data buffer at offset
                * @param std::ifstream&
                * @param size_t
                * @param off_t
                * @return void
                */
                inline void write(const std::string& fieldName, std::ifstream& file, size_t size)
                {   
                    auto field = getField(fieldName);
                    
                    if (field->type != kPacketFieldTypeVariant && field->size > size) {
                        throw std::invalid_argument("Write data is larger than static field size");
                    }

                    auto cur = file.cur;
                    
                    file.seekg(cur, file.end);

                    off_t end = file.tellg();

                    file.seekg(cur, file.beg);

                    if (end < size) {
                        throw std::overflow_error("Requested size exceeds file size from its current position in the stream");
                    }     
                    
                    if(field->type == kPacketFieldTypeVariant && field->size != size) {
                        resizeField(field, size);
                    }

                    if (!file.read(reinterpret_cast<char*>(&data[getFieldOffset(fieldName)]), size)) {
                        std::stringstream ss;
                        ss << "Error reading from file. Expected " << size << " but read " << file.gcount();
                        throw std::runtime_error(ss.str());
                    }
                }

                /**
                * @brief Resize a field in the data buffer, for kPacketFieldTypeVariant fields only
                * @param size_t size
                * @param const std::string& fieldName The field requiring size increase
                * @throws std::overflow_error when size is over the declared max size (unless max size is 0)
                * @return void
                */
                inline void resizeField(const std::string& fieldName, size_t size) {
                    return resizeField(getField(fieldName), size);
                }

                inline void resizeField(PacketFieldMeta* field, size_t size) {
                    if (field->type != kPacketFieldTypeVariant) {
                        throw std::overflow_error("Field resize only for kPacketFieldTypeVariant type");
                    } else if (getMaxDataSize() > 0 && ((data.size() - field->size) + size) > getMaxDataSize()) {
                        throw std::overflow_error("Field resize exceeds max allowed size");
                    }

                    off_t offset = getFieldOffset(field->name);

                    if (field->size > size) {
                        size_t diff = field->size - size;
                        data.erase(data.begin() + offset + diff, data.begin() + offset + field->size);
                    } else {
                        size_t diff = size - field->size;
                        data.insert(data.begin() + offset + field->size, diff, 0x00);
                    }

                    field->size = size;
                }

                /**
                * @brief Get a fields starting offset in the packet data buffer
                */
                inline off_t getFieldOffset(const std::string& name) 
                {
                    int ret = 0;

                    if (!hasField(name)) {
                        throw std::invalid_argument("Field does not exist");
                    }

                    PacketFieldMeta* field = getField(name);

                    for (auto &f : getFields()) {       
                        if (f.name.compare(field->name) == 0) {
                            break;
                        }
                        ret += f.size;
                    }

                    return ret;
                }

                /**
                * @brief Get a fields starting offset in the packet data buffer by field zero-based index
                */
                inline off_t getFieldOffset(int index) 
                {
                    off_t ret = 0;

                    if (!hasField(index)) {
                        throw std::invalid_argument("Field does not exist");
                    }

                    auto field = getField(index);

                    int i = 0;

                    for (auto &f : getFields()) {       
                        if (i == index) {
                            break;
                        }
                        ret += f.size;
                        i++;
                    }

                    return ret;
                }

                /**
                * @brief 
                */
                inline size_t getFieldSize(int index) 
                {
                    PacketFieldMeta* field = getField(index);

                    int i = 0;

                    for (auto &f : getFields()) {       
                        if (i == index) {
                            return field->size;
                        }
                        i++;
                    }

                    throw std::invalid_argument("Field does not exist");
                }

                /**
                * @brief 
                */
                inline size_t getFieldSize(const std::string& name) 
                {

                    PacketFieldMeta* field = getField(name);

                    for (auto &f : getFields()) {       
                        if (f.name.compare(field->name) == 0) {
                            return field->size;
                        }
                    }

                    throw std::invalid_argument("Field does not exist");
                }

                /**
                * @brief Byte swap primititve type T
                * @return T
                */
                template <class T> inline T swap(T i)
                {
                    assert(std::is_fundamental<T>::value);
                    
                    T ret = i;        

                    std::reverse(
                        reinterpret_cast<unsigned char*>(&ret), 
                        reinterpret_cast<unsigned char*>(&ret) + sizeof(T)
                    );

                    return ret;
                }
        };
    }
}
