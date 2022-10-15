#include <thread>
#include "Aggregator.hpp"

namespace sensors {

data_msg Aggregator::GetDataFromSensors()
{
    std::string air;
    StartSensorsCommunication();
    air = airQuality_->GetAirQuality();
    data_msg data = gpsSensor_->GetGpsData();
    data.sensorValue = std::stod(air);
    return data;
}

void Aggregator::StartSensorsCommunication()
{
    gpsSensor_->readUart();
    airQuality_->ReadAirQuality();
}

void Aggregator::StopReading()
{
    running = false;
}
Aggregator::~Aggregator()
{
    command_.reset();
    debugger_.reset();
    gpsSensor_.reset();
    airQuality_.reset();
}
Aggregator::Aggregator()
{
    command_ = std::make_shared<communication::Command>();
    debugger_ = std::make_shared<Debug>(command_);
    gpsSensor_ = std::make_shared<sensors::Gps>(command_,debugger_);
    airQuality_ = std::make_shared<sensors::AirQuality>(command_);
}
}// namespace sensors
