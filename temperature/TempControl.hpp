#ifndef MY_TEMPCONTROL_HPP
#define MY_TEMPCONTROL_HPP

/*
 * RTI connext and PrismTech OpenSplice generate different file names from the IDL description.
 * Thus we need to distinguish and select the correct include file.
 */

#ifdef DDS_IMPLEMENTATION_connext
    #include <gen/TempControl.hpp>
#else
    #ifdef DDS_IMPLEMENTATION_opensplice
        #include <gen/TempControl_DCPS.hpp>
    #else
        #error DDS_IMPLEMENTATION_ not set.
    #endif
#endif

#endif //MY_TEMPCONTROL_HPP