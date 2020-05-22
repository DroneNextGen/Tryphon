#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../tryphon.h"

#include <gtest/gtest.h>

namespace my
{
    namespace project
    {
        namespace
        {

            // The fixture for testing class Foo.
            class E2eTest : public ::testing::Test
            {
            protected:

                E2eTest()
                {
                }

                ~E2eTest() override
                {
                }

                void SetUp() override
                {
                }

                void TearDown() override
                {
                }

            };

            TEST_F(E2eTest, MethodBarDoesAbc)
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
                ASSERT_TRUE(decodePacket(&packet, &extracted_payload));

                ASSERT_STREQ(extracted_payload.content, payload.content);

                free(payload.content);
                free(packet.content);
            }
        } // namespace
    }     // namespace project
} // namespace my

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}