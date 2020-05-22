Tryphon
===

A lightweight and robust communication protocol
---

![Test Python package][test-python-ci-badge]
![Test c library][test-c-ci-badge]

# Install

## Python

### Prerequisites

* Python 3.7

### Steps

``` bash
pip install git+https://github.com/DroneNextGen/Tryphon
```

# Use

## Python

``` python
from tryphon import Tryphon

message = "test message"

encoded = Tryphon.encode(message)
print(encoded)

decoded = Tryphon.decode(encoded)
print(decoded)
```

[test-python-ci-badge]: https://github.com/DroneNextGen/Tryphon/workflows/Test%20Python%20package/badge.svg
[test-c-ci-badge]: https://github.com/DroneNextGen/Tryphon/workflows/Test%20c%20library/badge.svg
