#!/bin/bash

cd /work/head2head && \

rm -rf head2head.abi && \

rm -rf head2head.wasm && \

rm -rf head2head.wast && \

eosiocpp -o head2head.wast head2head.cpp && \

echo "Web Assembly Genrated"

eosiocpp -g head2head.abi head2head.cpp && \

echo "ABI Generated" && \

exit


