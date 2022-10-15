#include <thread>
#include "Aggregator.hpp"

namespace sensors {

data_msg Aggregator::GetDataFromSensors()
{
    std::string air;
    while (air.length() == 0) {
        airQuality.ReadAirQuality();
        air = airQuality.GetAirQuality();
    }
    gpsSensor.readUart();
    data_msg data = gpsSensor.GetGpsData();
    data.sensorValue = std::stod(air);
    return data;
}

void Aggregator::StartSensorsCommunication()
{
    gpsSensor.readUart();
    airQuality.ReadAirQuality();
}

void Aggregator::StopReading()
{
    running = false;
}
Aggregator::Aggregator()
{

}
}// namespace sensors
