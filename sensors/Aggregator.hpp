#pragma once
#include <memory>
#include "debug/Debug.hpp"
#include "communication/Command.hpp"
#include "AirQuality.hpp"
#include "Gps.hpp"
#include "dataStructure.hpp"

namespace sensors {

extern communication::Command command;
static sensors::Gps gpsSensor(command);
static sensors::AirQuality airQuality(command);

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
