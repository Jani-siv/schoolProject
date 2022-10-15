#pragma once

#include <string>
#include <memory>
#include "communication/Command.hpp"
#include "dataStructure.hpp"

namespace sensors {

class AirQuality {
public:
    AirQuality(std::shared_ptr<communication::Command>& command);
    ~AirQuality() = default;
    bool ReadAirQuality();
    std::string GetAirQuality();
private:
    bool AccessData = false;
    std::string incomingMessage;
    std::shared_ptr<communication::Command> command_;
};

}// namespace sensors
