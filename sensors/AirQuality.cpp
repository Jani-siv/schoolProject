#include "AirQuality.hpp"

namespace sensors {

AirQuality::AirQuality(std::shared_ptr<communication::Command> &command)
{
    command_ = command;
}

std::string AirQuality::GetAirQuality()
{
    while (AccessData) {}
    AccessData = true;
    std::string data = incomingMessage;
    incomingMessage="";
    AccessData = false;
    return data;
}
bool AirQuality::ReadAirQuality()
{
    while(AccessData) {}
    AccessData = true;
    incomingMessage = command_->Execute("recvAirFileMock");
    AccessData = false;
    return true;
}

}// namespace sensors
