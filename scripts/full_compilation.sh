###
 # @Description:
 # @Author: stone
 # @Date: 2020-02-01 08:44:51
 # @LastEditTime: 2020-05-23 14:02:42
 # @LastEditors: stone
 ###
#!/bin/bash
if [ ! -d "build" ]; then
    mkdir build
else
    rm -rf build/*
fi
cd build
Local_Dir=$(cd "$(dirname "$0")"; pwd)
echo "Now work at Dir:$Local_Dir"
cmake ..
if [ $? -eq 0 ]; then
     echo "succeed"
else
     echo "failed"
fi
make
cd ..
./main.out
