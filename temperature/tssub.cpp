// -- Std C/C++ Include
#include <iostream>
#ifdef DDS_IMPLEMENTATION_connext
  #include <gen/TempControl.hpp>
#else
  #ifdef DDS_IMPLEMENTATION_opensplice
    #include <gen/TempControl_DCPS.hpp>
  #else
    #error DDS_IMPLEMENTATION_ not set.
  #endif
#endif
#include <thread>         // std::thread, std::this_thread::sleep_for

#include <dds/sub/Subscriber.hpp>
#include <dds/sub/DataReader.hpp>


int main(int argc, char* argv[]) {

  dds::domain::DomainParticipant dp(0);
  dds::topic::Topic<tutorial::TempSensorType> topic(dp, "TTempSensor");
  dds::sub::Subscriber sub(dp);
  dds::sub::DataReader<tutorial::TempSensorType> dr(sub, topic);


  while (true) {
    auto samples = dr.read();
    std::for_each(samples.begin(),
		  samples.end(),
		  [](const dds::sub::Sample<tutorial::TempSensorType>& s) {
		    std::cout << s.data() << std::endl;
		  });
    std::cout << "---" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}

