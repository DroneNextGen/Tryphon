import os
from ctypes import (CDLL, POINTER, Structure, c_bool, c_char_p, c_ubyte,
                    c_ushort, pointer, string_at)
from typing import List

module_path = os.path.abspath(__file__)
dir_path = os.path.dirname(module_path)
tryphon_api = CDLL(os.path.join(dir_path, "tryphonlib.so"))

c_ubyte_p = POINTER(c_ubyte)


class Packet(Structure):
    _fields_ = [("content", c_ubyte_p), ("length", c_ushort)]


class Payload(Structure):
    _fields_ = [("content", c_char_p), ("length", c_ushort)]


class CodingException(Exception):
    pass


class Tryphon:
    @staticmethod
    def encode(payload: str) -> bytearray:
        try:
            packet_c = Packet(None, 0)
            encoded_payload = payload.encode("ascii")
            payload_c = Payload(encoded_payload, len(encoded_payload))

            encode_c = tryphon_api.encodePacket
            encode_c.restype = c_bool
            encode_c.argtypes = [POINTER(Packet), POINTER(Payload)]
            encode_c(pointer(packet_c), pointer(payload_c))
            return bytearray(string_at(packet_c.content, packet_c.length))
        except Exception as e:
            raise CodingException(f"Problem with loading/calling encode: {e}")

    @staticmethod
    def decode(message: bytearray) -> str:
        try:
            c_marray = c_ubyte * len(message)
            c_message = c_marray.from_buffer(message)
            packet_c = Packet(c_message, len(message))
            payload_c = Payload(None, 0)

            decode_c = tryphon_api.decodePacket
            decode_c.restype = c_bool
            decode_c.argtypes = [POINTER(Packet), POINTER(Payload)]
            decode_c(pointer(packet_c), pointer(payload_c))
            return payload_c.content[:payload_c.length].decode("ascii")
            # TODO: check why returned object is bigger than expected
            # Note: extra bytes are not deterministic

        except Exception as e:
            raise CodingException(f"Problem with loading/calling decode: {e}")
