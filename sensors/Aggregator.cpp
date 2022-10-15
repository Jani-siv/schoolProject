#include <thread>
#include "Aggregator.hpp"

namespace sensors {

std::shared_ptr<communication::Command> g_command = std::make_shared<communication::Command>();
std::shared_ptr<Debug> g_debugger = std::make_shared<Debug>(g_command);
std::shared_ptr<sensors::Gps> gpsSensor = std::make_shared<sensors::Gps>(g_command,g_debugger);
std::shared_ptr<sensors::AirQuality> airQuality = std::make_shared<sensors::AirQuality>(g_command);

data_msg Aggregator::GetDataFromSensors()
{
    std::string air;
    while (air.length() == 0) {
        airQuality->ReadAirQuality();
        air = airQuality->GetAirQuality();
    }
    gpsSensor->readUart();
    data_msg data = gpsSensor->GetGpsData();
    data.sensorValue = std::stod(air);
    return data;
}

void Aggregator::StartSensorsCommunication()
{
    gpsSensor->readUart();
    airQuality->ReadAirQuality();
}

void Aggregator::StopReading()
{
    running = false;
}
Aggregator::Aggregator()
{

}
}// namespace sensors
