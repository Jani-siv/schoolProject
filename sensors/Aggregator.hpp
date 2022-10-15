#pragma once
#include <memory>
#include "debug/Debug.hpp"
#include "communication/Command.hpp"
#include "AirQuality.hpp"
#include "Gps.hpp"
#include "dataStructure.hpp"

namespace sensors {

class Aggregator {
public:
    Aggregator();
    ~Aggregator();
    data_msg GetDataFromSensors();
    void StopReading();
private:
    void StartSensorsCommunication() ;
    std::shared_ptr<communication::Command> command_;
    std::shared_ptr<Debug> debugger_;
    std::shared_ptr<sensors::Gps> gpsSensor_;
    std::shared_ptr<sensors::AirQuality> airQuality_;
    bool running = true;
};

}// namespace sensors
