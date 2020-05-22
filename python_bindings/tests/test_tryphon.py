from .. import Tryphon, CodingException
from copy import deepcopy
import pytest

TEST_STRING = "test message"

def test_encode_decode():
    encoded = Tryphon.encode(deepcopy(TEST_STRING))
    decoded = Tryphon.decode(encoded)

    assert decoded == TEST_STRING

def test_encode_decode_failure():
    with pytest.raises(CodingException):
        encoded = Tryphon.encode(deepcopy(TEST_STRING))
        encoded[0] = encoded[0] + 0x01
        _ = Tryphon.decode(encoded)
