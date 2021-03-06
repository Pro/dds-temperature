# dds-temperature
Code for testing code portability between different DDS implementations.

The same C++ code compiles using either RTI Connext or PrismTech OpenSplice.
RTI's C++11 implementation is currently only available in the Early Access Release (contact support for that).

The tutorial code is based on: https://github.com/PrismTech/dds-tutorial-cpp-ex

**License:**
This code isn't bound to any license and can be freely used ([Public domain](https://wiki.creativecommons.org/Public_domain))

## How to build

First make sure your RTI Connext and PrismTech OpenSplice is setup correctly and the environment variables are set.

Then execute:

    mkdir build
    cd build
    cmake ..
    make

## How to execute

The executable files will be generated within the build directory.
You will get the following files:

    build/connext/connext_temp_pub
    build/connext/connext_temp_sub
    build/connext/opensplice_temp_pub
    build/connext/opensplice_temp_sub
    
First start both subscribers in two different terminals by executing `build/connext/opensplice_temp_sub` and `build/connext/connext_temp_sub`.

Now you can start one of the publishers and check if both subscribers receive data. Use `build/connext/connext_temp_pub 42` or `build/connext/opensplice_temp_pub 42`.
The additional parameter (42) is just a number identifying the sensor. You can use any number here.
