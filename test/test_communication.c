#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string.h>
#include <unity.h>
#include <stdlib.h>

#include "tryphon.h"

void testEncodingThenDecoding(void)
{
    const char *test_string = "test string";
    const unsigned short len_test_string = 11;

    struct Payload payload;
    payload.content = (char*)malloc(len_test_string * sizeof(char));
    strcpy(payload.content, test_string);
    payload.length = len_test_string;

    struct Packet packet;
    encodePacket(&packet, &payload);

    struct Payload extracted_payload;
    TEST_ASSERT_TRUE(decodePacket(&packet, &extracted_payload));

    TEST_ASSERT_TRUE(strcmp(extracted_payload.content, payload.content) == 0);

    free(payload.content);
    free(packet.content);
}

void testEncodingThenDecodingWithFailure(void)
{
    const char *test_string = "test string";
    const unsigned short len_test_string = 11;

    struct Payload payload;
    payload.content = (char*)malloc(len_test_string * sizeof(char));
    strcpy(payload.content, test_string);
    payload.length = len_test_string;

    struct Packet packet;
    encodePacket(&packet, &payload);

    struct Packet errored_packet;
    errored_packet.content = malloc(packet.length * sizeof(char));
    strcpy(errored_packet.content, packet.content);
    errored_packet.content[3] = 0x01;

    struct Payload extracted_payload;
    TEST_ASSERT_FALSE(decodePacket(&errored_packet, &extracted_payload));

    free(payload.content);
    free(packet.content);
    free(errored_packet.content);
}

