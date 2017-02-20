#!/usr/local/bin/python2.7

import dpkt
import struct
import binascii

filename='restore.pcap'
# 26 bytes before data
def dump(d): return reduce(lambda x,y:x+y+" ", map(lambda p:("0" if ord(p)<=0xf else "")+hex(ord(p))[2:],d), "")

def test():
	a = []
	aIdx = 0
	for ts, pkt in dpkt.pcap.Reader(open(filename,'r')):
		p=dpkt.ppp.PPP(pkt) 
		#result = bytearray.fromhex(p.data)
		#print dump(p.data)
		index = 0
		i = 0
		data = p.data
		dataLength = len(data)
		for b in data:
			b = ord(b)
			if (b == 0x7E):
				if ord(data[dataLength - 1]) != 0x7E:
					i += 1
					continue
				index = i
				entry = []
				entry.append(dataLength)
				#print "Match on index %d" % index
				if dataLength > 128:
					entry.append(data[index:index+60])
				else:
					entry.append(data[index:index + 10]) 
				aIdx += 1  
				a.append(entry)		
				break
			else:
				i += 1
	return a

a = test()

for t in a:
	command = ord(t[1][1])

	if command == 7:
		addr = struct.unpack('<L', t[1][2:6])
		print "Packet Size: %lu" % int(t[0])
		print "Write at Address %08X" % addr
	elif command == 8:
		addr = struct.unpack('<L', t[1][2:6])
		print "Wrote Address %08X\n" % addr
	else:
		print "Command %d" % command
		print dump(t[1])
		print "\n\n"
	#address = struct.pack('<BLLLL', 0x01, addr, bus_clk_khz, lsb, msb)
	#print "\n\n"