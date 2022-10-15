#pragma once
#include <string>
#include <vector>
#include <memory>
#include "communication/Command.hpp"
#include "dataStructure.hpp"
#include "debug/Debug.hpp"

namespace sensors {

class Gps {
public:
    Gps(communication::Command& command);
    ~Gps() = default;
    bool readUart();
    data_msg GetGpsData();
private:
    bool AccessData = false;
    void parseMessage();
    void GenerateStruct();
    void ValidateData();
    std::vector<std::string> data_;
    std::string incomingMessage_;
    data_msg structure_;
    communication::Command* command_;
};

}// namespace sensors

extern std::shared_ptr<Debug> debugger;
