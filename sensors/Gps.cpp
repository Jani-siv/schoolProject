#include <cstring>
#include "Gps.hpp"

namespace sensors {

bool Gps::readUart()
{
    while(AccessData) {}
    AccessData = true;
    incomingMessage_ = command_->Execute("gpsFileMock");
    AccessData = false;
    return true;
}
void Gps::parseMessage()
{
    std::string::size_type end(std::string::npos);
    std::string::size_type start(0);
    std::string delim = ",";
    while( (end = incomingMessage_.find(delim,start)) != std::string::npos)
    {
        data_.push_back(incomingMessage_.substr(start,end - start));
        start = end + delim.length();
    }
    data_.push_back(incomingMessage_.substr(incomingMessage_.length()-1,1));

}
void Gps::GenerateStruct()
{
    memset(&structure_,0,sizeof(structure_));
    if (!data_.empty())
    {
        ValidateData();
        structure_.timestamp = std::stod(data_.at(1));
        structure_.latitude = std::stod(data_.at(2));
        structure_.longitude = std::stod(data_.at(4));
        data_.clear();
    }
    else
    {
        debug_->DebugMsg("Empty packet");
    }
}
data_msg Gps::GetGpsData()
{
    while(AccessData) {}
    AccessData = true;
    parseMessage();
    AccessData = false;
    GenerateStruct();
    return structure_;
}
void Gps::ValidateData()
{
    if(data_.at(0).find("$GPGGA",0) != 0)
    {
        debug_->DebugMsg("1");
    }
    double testable = std::stod(data_.at(1));
    if(testable == 0)
    {
        debug_->DebugMsg("2");
    }
    testable = std::stod(data_.at(2));
    testable /= 100;
    if (testable > 90)
    {
        debug_->DebugMsg("3");
    }
    if(data_.at(3).find("N",0) != 0)
    {
        debug_->DebugMsg("4");
    }
    testable = std::stod(data_.at(4))/100;
    if (testable > 180)
    {
        debug_->DebugMsg("5");
    }
    if(data_.at(5).find("E",0) != 0)
    {
        debug_->DebugMsg("6");
    }
}
Gps::Gps(std::shared_ptr<communication::Command>& command,
         std::shared_ptr<Debug>& debugger)
{
    debug_ = debugger;
    command_ =  command;
}

}// namespace sensors
