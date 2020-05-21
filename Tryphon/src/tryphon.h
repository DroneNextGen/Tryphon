#ifndef TRYPHON
#define TRYPHON

#include "limits.h"
#define CHECKSUM_MAX UINT_MAX

#define true 1
#define false 0

typedef unsigned char Byte;
typedef unsigned int CheckSum;

struct Payload
{
    char *content;
    unsigned short length;
};

struct Packet
{
    Byte *content;
    unsigned short length;
};

union bytechecksum {
    Byte b[sizeof(CheckSum)];
    CheckSum c;
};

int encodePacket(struct Packet *packet, struct Payload *payload);
int decodePacket(struct Packet *packet, struct Payload *payload);
int checkPacketIntegrity(struct Packet *packet, struct Payload *payload);
CheckSum checkSum(struct Payload *payload);

#endif