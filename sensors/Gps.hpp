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
    Gps(std::shared_ptr<communication::Command>& command,
        std::shared_ptr<Debug>& debugger);
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
    std::shared_ptr<communication::Command> command_;
    std::shared_ptr<Debug> debug_;
};

}// namespace sensors

