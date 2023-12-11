#!/bin/bash
wget -P /tmp https://raw.github.com/fidelcom/alx-low_level_programming/master/0x18-dynamic_libraries/libcrack.so
export LD_PRELOAD=/tmp/libcrack.so
