#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string.h>
#include <unity.h>
#include <stdlib.h>

#include "tryphon.h"

void testEncodingThenDecoding(void)
{
    const char *test_string = "coucoucou";
    const unsigned short len_test_string = 9;

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

