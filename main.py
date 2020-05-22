# /usr/bin/env python3
# coding: utf-8

#%% Import lib
from python_bindings import Tryphon

#%% encode message
b = Tryphon.encode("test message")
print(f"encoded message: {b}")

#%% decode message
c = Tryphon.decode(b)
print(f"decoded message: {c}")