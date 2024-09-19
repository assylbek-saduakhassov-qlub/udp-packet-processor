#include <stdio.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include "udp_processor.h"

// Function to process and display information about a single UDP packet
void process_udp_packet(const u_char *packet, struct pcap_pkthdr header) {
    // Calculate the starting point of the UDP header
    struct udphdr *udp_header = (struct udphdr *)(packet + 34); 

    // Convert source and destination port numbers from network byte order to host byte order
    int src_port = ntohs(udp_header->uh_sport);     // Source Port
    int dst_port = ntohs(udp_header->uh_dport);     // Destination Port
    int udp_length = ntohs(udp_header->uh_ulen);    // Length of the UDP packet
    int checksum = ntohs(udp_header->uh_sum);       // UDP checksum value

    // Print UDP header information
    printf("Src Port: %d\n", src_port);
    printf("Dst Port: %d\n", dst_port);
    printf("UDP Packet Length: %d\n", udp_length);
    printf("Checksum: 0x%x\n", checksum);

    // Calculate the starting point of the UDP data
    const u_char *udp_data = (const u_char *)(packet + 14 + 20 + 8);

    int data_length = udp_length - 8;   // Subtracting the UDP header length

    // Print the UDP data in ASCII, replace non-printable characters with '.'
    for (int i = 0; i < data_length; i++) {
        if (udp_data[i] >= 32 && udp_data[i] <= 126) {
            printf("%c", udp_data[i]);
        } else {
            printf(".");
        }
    }
    printf("\n");
    printf("-----------------------------\n");
}
