#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "tryphon.h"

int checkPacketIntegrity(struct Packet *packet, struct Payload *payload)
{
    payload->length = packet->length - sizeof(CheckSum) / sizeof(Byte);
    payload->content = malloc(payload->length * sizeof(char));

    for (unsigned short i = 0; i < payload->length; i++)
        payload->content[i] = packet->content[i];

    union bytechecksum check_sum;
    unsigned short i, j;
    for (i = payload->length, j = 0; i < packet->length; i++, j++)
        check_sum.b[j] = packet->content[i];

    int result = checkSum(payload) == check_sum.c;
    if (!result)
        free(payload->content);
    return result;
}

int encodePacket(struct Packet *packet, struct Payload *payload)
{
    size_t allocation_size = payload->length * sizeof(char) + sizeof(CheckSum);
    packet->content = malloc(allocation_size);
    packet->length = allocation_size / (sizeof(Byte));

    // Put payload in packet
    for (unsigned short i = 0; i < payload->length; i++)
        packet->content[i] = payload->content[i];

    // Put checksum in packet
    union bytechecksum check_sum;
    check_sum.c = checkSum(payload);

    unsigned short i, j;
    for (i = payload->length, j = 0; i < packet->length; i++, j++)
        packet->content[i] = check_sum.b[j];

    return true;
}

int decodePacket(struct Packet *packet, struct Payload *payload)
{
    return checkPacketIntegrity(packet, payload);
}

CheckSum checkSum(struct Payload *payload)
{
    CheckSum checksum = 0;
    for (unsigned short i = 0; i < payload->length; i++)
        checksum = (checksum + payload->content[i]) % CHECKSUM_MAX;
    return checksum;
}