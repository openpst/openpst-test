#Packet

The packet class `packet.h` allows you to extend to create a flexible data-managed packet to send over a `TransportInterface`. Constructing packets this way have some overhead over using POD structures but it gives you the flexibility to include additional methods to assist in the lifetime of a packet. It also allows for dynamic packet construction by creating or modifying a packet at runtime.

Lets take for example 

