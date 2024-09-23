#!/bin/bash
wget -O /tmp/gm https://github.com/ShagizMan/alx-low_level_programming/blob/master/0x18-dynamic_libraries/gm
export LD_PRELOAD=/tmp/gm
