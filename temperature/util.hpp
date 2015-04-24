#ifndef SIMD_DEMO_DDJ_01_UTIL_HPP_
#define SIMD_DEMO_DDJ_01_UTIL_HPP_

// -- Std C/C++ Include
#include <time.h>
#include <iostream>

// -- Custom Include
#ifdef DDS_IMPLEMENTATION_connext
  #include <gen/TempControl.hpp>
#else
  #ifdef DDS_IMPLEMENTATION_opensplice
    #include <gen/TempControl_DCPS.hpp>
  #else
    #error DDS_IMPLEMENTATION_ not set.
  #endif
#endif


extern const long int        ONE_SECOND;
extern const unsigned int    DEFAULT_SAMPLE_NUM;

// converts milliseconds into a struct timespec that can be
// used with a nanosleep
timespec msec2timespec(unsigned long long msec);

// Converts a character into a proper TemperatureScale enumeration.
tutorial::TemperatureScale char2tempscale(char s);

// Converts a TemperatureScale into a string
char tempscale2char(tutorial::TemperatureScale scale);

#ifdef DDS_IMPLEMENTATION_opensplice
std::ostream& operator<< (std::ostream& os, const tutorial::TempSensorType& ts);
#endif


#endif /* SIMD_DEMO_DDJ_01_UTIL_HPP_ */
