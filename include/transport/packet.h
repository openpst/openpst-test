/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file packet.h
* @package openpst/libopenpst
* @brief Represents a packet of data to be read or written from a TransportInterface
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
#include "transport/transport_interface.h"

namespace OpenPST {
    namespace Transport {
        
        // forward declaration required here cause Packet and TransportInterface depend on eachother
        class TransportInterface; 

        enum PacketEndianess{
            kPacketEndianessUnknown,
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
            kPacketFieldTypePrimitive, // a primitive type (byte, short, word, qword)
            kPacketFieldTypeArray,    // a byte array type
            kPacketFieldTypeVariant,  // a variable length type
            kPacketFieldTypeLast     // last entry, equal or over is invalid
        };

        struct PacketFieldMeta {
            PacketFieldType type;
            std::string name;
            size_t size;
        };

        /**
        * @brief PacketError
        */
		class PacketError : public std::exception
		{
			private:
				const PacketError& operator=(PacketError);
				std::string _what;
			public:
				PacketError(std::string message) : _what(message)  { }
				PacketError(const PacketError& second) : _what(second._what) {}
				virtual ~PacketError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};

        /**
        * @brief PacketInvalidArgument
        */
		class PacketInvalidArgument : public std::invalid_argument
		{
			private:
				const PacketInvalidArgument& operator=(PacketInvalidArgument);
				std::string _what;
			public:
				PacketInvalidArgument(std::string message) : 
					_what(message), std::invalid_argument(message)  { }
				PacketInvalidArgument(const PacketInvalidArgument& second) : 
					_what(second._what), std::invalid_argument(second._what) {}
				virtual ~PacketInvalidArgument() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};

        /**
        * @brief PacketOutOfRange
        */
		class PacketOutOfRange : public std::out_of_range
		{
			private:
				const PacketOutOfRange& operator=(PacketOutOfRange);
				std::string _what;
			public:
				PacketOutOfRange(std::string message) : 
					_what(message), std::out_of_range(message) { }
				PacketOutOfRange(const PacketOutOfRange& second) : 
					_what(second._what), std::out_of_range(second._what) {}
				virtual ~PacketOutOfRange() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};

        /**
        * @brief Packet
        */
        class Packet
        {
            protected:
                /** @var Endianess of target device */
                PacketEndianess endianT = kPacketEndianessLittle;
                
                /** @var Architecture of the target device */
                PacketTargetArch archT = kPacketTargetArchUnknown;
                
                /** @var If this packet expects a response or not */
                bool responseExpected = true;

                /** @var The max size the data may occupy */
                size_t maxDataSize = 0;

                /** @var The resulting response, if available */
                Packet* response = nullptr;

                /** @var Field defitions for the packet */
                std::vector<PacketFieldMeta> fieldMeta;

                /* @var The underlying data of the packet to be sent */
                std::vector<uint8_t> data;
            public:
                /**
                * @brief Constructor
                * @param size_t
                * @return Packet
                */
                Packet(size_t maxDataSize);
                
                /**
                * @brief Constructor
                * @param PacketEndianess
                * @param size_t
                * @return Packet
                */
                Packet(PacketEndianess targetEndianess, size_t maxDataSize);

                /**
                * @brief Destructor
                */
                ~Packet();
            private:
                    // no copy
                  Packet(const Packet&);

            public:
                
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
                * @brief Get the response packet, if it has been prepared/unpacked
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
                virtual void unpack(std::vector<uint8_t>& data, TransportInterface* transport) = 0;

                /**
                * @brief Get a fields starting offset in the packet data buffer
                */
                inline off_t getFieldOffset(const std::string& name) 
                {
                    int ret = 0;

                    if (!hasField(name)) {
                        throw PacketInvalidArgument("Field does not exist");
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
                        throw PacketInvalidArgument("Field does not exist");
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
                * @brief Get a field size based of field meta, from zero-based field index
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

                    throw PacketInvalidArgument("Field does not exist");
                }

                /**
                * @brief  Get a field size based of field meta, from field name
                */
                inline size_t getFieldSize(const std::string& name) 
                {

                    PacketFieldMeta* field = getField(name);

                    for (auto &f : getFields()) {       
                        if (f.name.compare(field->name) == 0) {
                            return field->size;
                        }
                    }

                    throw PacketInvalidArgument("Field does not exist");
                }

            protected:

                /**
                * @brief Read primitive type T from the data buffer at offset
                * @param off_t offset
                * @throws PacketOutOfRange 
                * @return T
                */
                template <class T> inline T read(off_t offset) 
                {
                    return read<T>(data, offset);
                }

                /**
                * @brief Read primitive type T from a vector buffer at offset
                * @param std::vector<uint8_t>& buffer
                * @param off_t offset
                * @throws PacketOutOfRange 
                * @return T
                */
                template <class T> inline T read(std::vector<uint8_t>& buffer, off_t offset) 
                {
                    assert(std::is_fundamental<T>::value);
        
                    if ((offset + sizeof(T)) > buffer.size()) {
                        std::stringstream ss;
                        ss << "Attempted to read outside buffer. Requested offset " << offset << " but max data is " << buffer.size() << std::endl;
                        throw PacketOutOfRange(ss.str());
                    }

                    T* p = reinterpret_cast<T*>(&buffer[offset]);
                    
                    if (sizeof(T) != sizeof(uint8_t) && getTargetEndianess() != getHostEndianess()) {
                        return swap<T>(*p);
                    }

                    return *p;
                }

                /**
                * @brief Read string from the data buffer at offset until 0x00 or end of buffer
                * @param size_t size
                * @param off_t offset
                * @throws PacketOutOfRange 
                * @return std::string
                */
                inline std::string getString(size_t size, off_t offset) 
                {
                    if ((offset + size) > data.size()) {
                        throw PacketOutOfRange("Attempted to read outside of the packet data buffer");
                    }

                    std::string ret( data.begin() + offset, data.begin() + offset + size );

                    return ret;
                }

                /**
                * @brief Read string from the data buffer at offset
                * @param size_t size
                * @param off_t offset
                * @throws PacketOutOfRange 
                * @return std::vector<uint8_t>
                */
                inline std::vector<uint8_t> read(size_t size, off_t offset) 
                {
                    if ((offset + size) > data.size()) {
                        throw PacketOutOfRange("Attempted to read outside of the packet data buffer");
                    }

                    std::vector<uint8_t> ret;

                    ret.reserve(size);

                    ret.insert( ret.begin(), data.begin() + offset, data.begin() + offset + size );

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
                        throw PacketInvalidArgument("Write data is larger than static field size");
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
                        throw PacketInvalidArgument("Write data is larger than static field size");
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
                        throw PacketInvalidArgument("Write data is larger than static field size");
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
                        throw PacketInvalidArgument("Write data is larger than static field size");
                    }

                    off_t current = static_cast<off_t>(file.tellg());

                    file.seekg(0, file.end);

                    off_t end = static_cast<off_t>(file.tellg());

                    file.seekg(current, file.beg);

                    std::cout << current << " - " << end << " - " << file.tellg() << std::endl;

                    if (end < size) {
                        throw PacketOutOfRange("Requested size exceeds file size from its current position in the stream");
                    }
                    
                    
                    if(field->type == kPacketFieldTypeVariant && field->size != size) {
                        resizeField(field, size);
                    }

                   // std::cout << getFieldOffset(fieldName) << " - " << field->size << " - " << current << std::endl;

                    if (!file.read(reinterpret_cast<char*>(&data[getFieldOffset(fieldName)]), size)) {
                        std::stringstream ss;
                        ss << "Error reading from file. Expected " << size << " but read " << file.gcount();
                        throw std::runtime_error(ss.str());
                    }
                }

                /**
                * @brief Resize a field in the data buffer, for kPacketFieldTypeVariant fields only
                *                
                * @param const std::string& fieldName The field requiring size increase
                * @param size_t size
                * @throws std::overflow_error when size is over the declared max size (unless max size is 0)
                * @return void
                */
                inline void resizeField(const std::string& fieldName, size_t size) {
                    return resizeField(getField(fieldName), size);
                }

                /**
                * @brief Resize a field in the data buffer, for kPacketFieldTypeVariant fields only
                *
                * @param PacketFieldMeta* field
                * @param size_t size
                * @throws std::overflow_error when size is over the declared max size (unless max size is 0)
                * @return void
                */
                inline void resizeField(PacketFieldMeta* field, size_t size) {
                    if (field->type != kPacketFieldTypeVariant) {
                        throw PacketOutOfRange("Field resize only for kPacketFieldTypeVariant type");
                    } else if (getMaxDataSize() > 0 && ((data.size() - field->size) + size) > getMaxDataSize()) {
                        throw PacketOutOfRange("Field resize exceeds max allowed size");
                    }

                    off_t offset = getFieldOffset(field->name);

                    if (field->size > size) {
                        size_t diff = field->size - size;
                        
                        data.erase(
                        	data.begin() + offset + field->size - diff, 
                        	data.begin() + offset + field->size
                        );

                    } else if (field->size < size) {
                        size_t diff = size - field->size;

                        data.insert(
                        	data.begin() + offset + field->size, 
                        	diff, 
                        	0x00
                        );
                    }

                    field->size = size;
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
