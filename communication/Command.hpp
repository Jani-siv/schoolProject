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
    std::string DebugFileMock();
    std::vector<std::string> unitTesting;
};

} // namespace communication
