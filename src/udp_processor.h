#ifndef UDP_PROCESSOR_H
#define UDP_PROCESSOR_H

#include <pcap.h>

// Function to process and display information about a single UDP packet
void process_udp_packet(const u_char *packet, struct pcap_pkthdr header);

#endif
