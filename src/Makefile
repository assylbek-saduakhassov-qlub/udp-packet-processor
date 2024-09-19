CC=gcc
CFLAGS=-Wall

all: pcap_reader

pcap_reader: pcap_reader.o udp_processor.o
	$(CC) -o pcap_reader pcap_reader.o udp_processor.o -lpcap

pcap_reader.o: pcap_reader.c udp_processor.h
	$(CC) $(CFLAGS) -c pcap_reader.c

udp_processor.o: udp_processor.c udp_processor.h
	$(CC) $(CFLAGS) -c udp_processor.c

clean:
	rm -f *.o pcap_reader
