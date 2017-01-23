#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <cassert>

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
            kPacketTargetArchX8664,
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

                /* @var If this packet requires a response or not */
                bool responseExpected = true;

                /* @var The resulting response, if available */
                Packet* response = nullptr;

                std::vector<PacketFieldMeta> fieldMeta;
            public:
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
                bool getResponseExpected();

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
                * @brief Get a declared field meta information
                * @param const std::string& name
                * @throws std::invalid_argument
                * @return const PacketFieldMeta*
                */
                PacketFieldMeta* getField(const std::string& name);

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
                * @brief Get the underlying data buffer
                * @return const std::vector<uint8_t>&
                */
                const std::vector<uint8_t>& getData();

                /**
                * @brief Validate the data in the packet buffer
                */
                //virtual void validate();

                /**
                * @brief Prepare the data before sending, making and final adjustments, for example crc
                */
                virtual void prepare() {}

                /**
                * @brief Unpack the response buffer into a response Packet
                */
                //virtual void unpack(std::vector<uint8_t>& data) = 0;

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

                    if (offset > data.size() || offset + sizeof(T) > data.size()) {
                        throw std::out_of_range("Attempted to read outside of the packet data buffer");
                    }

                    return reinterpret_cast<T>(*(&data[offset]));
                }

                inline std::string readstd::ofstream& file, off_t offset) 

                /**
                * @brief Read string from the data buffer at offset until 0x00
                * @param off_t offset
                * @throws std::out_of_range 
                * @return T
                */
                inline std::string read(size_t amount, off_t offset) 
                {
                    std::string ret = "";

                    if (offset > data.size() || offset + amount > data.size()) {
                        throw std::out_of_range("Attempted to read outside of the packet data buffer");
                    }

                    for (int i = 0; i < amount; i++) {
                        if (i == 0x00) {    
                            std::count << "AYE" << std::endl;
                            break;
                        } else {
                            std::count << "AYE2" << std::endl;
                        }
                        ret.append(reinterpret_cast<char *>(&data[offset + i]));
                    //TODO problemos here mi amigo

                    /*std::copy(
                        data.begin() + offset, 
                        data.begin() + offset + amount, 
                        &ret[0]
                    );
*/
                    return ret;
                }

                /**
                * @brief Write primitive type T into the data buffer at offset
                * @param const T& value
                * @param off_t offset
                * @return void
                */
                template <class T> inline void write(const T& value, off_t offset)
                {
                    assert(std::is_fundamental<T>::value);
                    
                    if (data.size() < offset + sizeof(T)) {
                        data.resize(data.size() + (data.size() - offset) + sizeof(T));
                    }
                    
                    std::copy(&value, ((&value) + sizeof(T)), data.begin() + offset);
                }

                /**
                * @brief Write string in the data buffer at offset
                * @return void
                */
                inline void write(const std::string& str, off_t offset)
                {   
                    if (data.size() < offset + str.size()) {
                        data.resize(data.size() + (data.size() - offset) + str.size());
                    }
                    
                    std::copy(str.begin(), str.end(), data.begin() + offset);
                }

                /**
                * @brief Write specified amount of bytes from src into the data buffer at offset
                * @return void
                */
                inline void write(uint8_t* src, size_t amount, off_t offset)
                {
                    if (data.size() < offset + amount) {
                        data.resize(data.size() + (data.size() - offset) + amount);
                    }

                    std::copy(src, src + amount, data.begin() + offset);
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
