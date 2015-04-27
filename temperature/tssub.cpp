// -- Std C/C++ Include
#include <iostream>

#include "TempControl.hpp"

#include <thread>         // std::thread, std::this_thread::sleep_for

#include "util.hpp"
#include <dds/sub/Subscriber.hpp>
#include <dds/sub/DataReader.hpp>


int main(int argc, char *argv[]) {

    dds::domain::qos::DomainParticipantQos qos;
#ifdef DDS_IMPLEMENTATION_connext
    //Disable shared memory
    qos->transport_builtin.mask = DDS_TRANSPORTBUILTIN_UDPv4;
#endif

    dds::domain::DomainParticipant dp(0, qos);
    dds::topic::Topic<tutorial::TempSensorType> topic(dp, "TTempSensor");
    dds::sub::Subscriber sub(dp);
    dds::sub::DataReader<tutorial::TempSensorType> dr(sub, topic);


    while (true) {
        auto samples = dr.read();
        std::for_each(samples.begin(),
                      samples.end(),
                      [](const dds::sub::Sample<tutorial::TempSensorType> &s) {
                          std::cout << s.data() << std::endl;
                      });
        std::cout << "---" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}

