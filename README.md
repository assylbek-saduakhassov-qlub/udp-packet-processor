
# UDP Packet Processor
A C-based tool to process and analyze UDP packets from PCAP files. Extracts and displays UDP header information, such as source and destination ports, packet length, and checksum, along with the actual packet data. Ideal for network traffic analysis and debugging.

## Overview
This project processes UDP packets from a provided PCAP file. The program extracts and displays the source and destination ports, UDP packet length, checksum, and the actual packet data in ASCII format.

## Features
- Reads packets from a PCAP file.
- Extracts and prints UDP header information (source port, destination port, etc.).
- Prints the actual data from the UDP packet in an ASCII format, replacing non-printable characters with '.'.
- Modular code structure for ease of understanding and future enhancements.

## Requirements
- C compiler (e.g., `gcc`)
- `libpcap` library for packet capture

## Build
To build the project, run the following command from the `src/` directory:

```bash
make
