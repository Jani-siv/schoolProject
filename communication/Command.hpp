#pragma once

#include <vector>
#include "CommandBase.hpp"

namespace communication {

class Command : public CommandBase {
public:
    Command() = default;
    virtual ~Command() = default;
    std::string Execute(std::string type) override;
    void setUartMessage(std::string type, std::string message);
private:
    std::string gpsMessage_;
    std::string debugMessage_;
    std::string GpsFileMock();
    std::string AirFileMock();
    std::string DebugFileMock();
    std::vector<std::string> unitTesting;
    std::vector<std::string> dataPoints_;
    size_t currentDataPoint_ = 0;
};

} // namespace communication
