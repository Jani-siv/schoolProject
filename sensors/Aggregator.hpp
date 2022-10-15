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
    ~Aggregator() = default;
    data_msg GetDataFromSensors();
    static void StartSensorsCommunication() ;
    void StopReading();
private:
    bool running = true;
};

}// namespace sensors
