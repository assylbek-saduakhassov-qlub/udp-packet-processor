#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include "udp_processor.h"

int main(int argc, char *argv[]) {
    // Ensure the program is called with the correct arguments
    if (argc != 2) {
        fprintf(stderr, "Error: argument (pcap file) is missing\n");
        return 1;
    }

    // Open the specified PCAP file for offline processing
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_offline(argv[1], errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening file: %s\n", errbuf);
        return 2;
    }

    // Loop through all packets in the PCAP file
    struct pcap_pkthdr header;
    const u_char *packet;
    printf("-----------------------------\n");
    while ((packet = pcap_next(handle, &header)) != NULL) {
        process_udp_packet(packet, header); // Process each packet
    }

    // Close the PCAP file after processing all packets
    pcap_close(handle);
    return 0;
}
