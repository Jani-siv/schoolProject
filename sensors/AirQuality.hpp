#pragma once

#include <string>
#include "communication/Command.hpp"
#include "dataStructure.hpp"

namespace sensors {

class AirQuality {
public:
    AirQuality(communication::Command& command);
    ~AirQuality() = default;
    bool ReadAirQuality();
    std::string GetAirQuality();
private:
    bool AccessData = false;
    std::string incomingMessage;
    communication::Command* command_;
};

}// namespace sensors
