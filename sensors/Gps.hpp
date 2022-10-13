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
    Gps() = default;
    ~Gps() = default;
    bool readUart();
    data_msg GetMessage();
private:
    bool AccessData = false;
    void parseMessage();
    void GenerateStruct();
    void ValidateData();
    std::vector<std::string> data_;
    std::string incomingMessage_;
    communication::Command command_;
    data_msg structure_;
};

}// namespace sensors

extern std::shared_ptr<Debug> debugger;
