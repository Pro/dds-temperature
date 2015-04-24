# dds-temperature
Code for testing code portability between different DDS implementations.

The same code should be compiles using either RTI Connext or PrismTech OpenSplice.

The tutorial code is based on: https://github.com/PrismTech/dds-tutorial-cpp-ex

## How to build

First make sure your RTI Connext and PrismTech OpenSplice is setup correctly and the environment variables are set.

Then execute:

    mkdir build
    cd build
    cmake ..
    make
