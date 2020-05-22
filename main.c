#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "src/tryphon.h"

int main(int argc, char const *argv[])
{
    const char * test_string = "coucoucou";
    const unsigned short len_test_string = 9;

    struct Payload payload;
    payload.content = malloc(len_test_string * sizeof(char));
    strcpy(payload.content, test_string);
    payload.length = len_test_string;

    struct Packet packet;
    encodePacket(&packet, &payload);

    printf("Functionnal test - success case: ");

    struct Payload extracted_payload;
    if (!decodePacket(&packet, &extracted_payload))
    {
        printf("Failed to decode packet\n");
        return -1;
    }
    
    if(strcmp(extracted_payload.content, payload.content) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    struct Payload wrong_payload;
    wrong_payload.content = malloc(len_test_string * sizeof(char));
    strcpy(wrong_payload.content, payload.content);
    wrong_payload.content[3] = 'k';

    printf("Functionnal test - failure case: ");

    if(strcmp(extracted_payload.content, wrong_payload.content) == 0)
        printf("FAIL\n");
    else
        printf("SUCCESS\n");

    free(payload.content);
    free(wrong_payload.content);

    return 0;
}
