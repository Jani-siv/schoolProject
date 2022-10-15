#include "Command.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>
#include "Uart.hpp"
#include "AirQualityInterface.hpp"

namespace communication {
//commands send recv uart msg
std::string Command::Execute(std::string type)
{
    static Uart gpsUart;
    static Uart debugUart;
    static AirQualityInteface airQuality;
    std::string err = "Communication not found";

    if (type.find("gpsRecv") == 0) {
        return gpsUart.Execute("gpsRecv");
    }
    else if (type.find("gpsSend") == 0) {
        gpsUart.SetMessageToSend(gpsMessage_);
        gpsMessage_.clear();
        return gpsUart.Execute("gpsSend");
    }
    else if (type.find("debugSend") == 0) {
        debugUart.SetMessageToSend(debugMessage_);
        debugMessage_.clear();
        return debugUart.Execute("debugSend");
    }
    else if (type.find("debugRecv") == 0) {
        return debugUart.Execute("debugRecv");
    }
    else if (type.find("gpsFileMock") == 0) {
        return GpsFileMock();
    }
    else if (type.find("debugFileMock") == 0)
    {
        DebugFileMock();
    }
    else if (type.find("recvAirFileMock") == 0)
    {
        return airQuality.Execute("recvAirFileMock");
    }
    else {
        return err;
    }
}

std::string Command::GpsFileMock() {
    std::string path = std::filesystem::current_path();
    path = path.substr(0,path.find("cmake-build-debug"));
    path += "communication/mock/gpsCoordinates.txt";
    if (unitTesting.empty()) {
        std::fstream fd(path.c_str(), std::ios_base::in);
        if (fd.is_open()) {
            while(!fd.eof()) {
                std::string line;
                std::getline(fd, line);
                unitTesting.push_back(line);
            }
            fd.close();
            return unitTesting.at(0);
        }
    }
    return unitTesting.at(1);
}

void Command::setUartMessage(std::string type, std::string message) {
    if (type.find("gpsSend") == 0)
    {
        gpsMessage_ = message;
    }
    else
    {
        debugMessage_ = message;
    }

}
std::string Command::DebugFileMock()
{
    std::fstream fd("/tmp/unit_test",std::ios_base::app);
    if(fd.is_open())
    {
        fd.write(debugMessage_.c_str(),debugMessage_.length());
        debugMessage_="";
        fd.close();
    }
    return debugMessage_;
}

} // namespace communication
