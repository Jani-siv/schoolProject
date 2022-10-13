#pragma once

#include <memory>
#include "CommandBase.hpp"
#include "debug/Debug.hpp"

namespace communication {

class Uart : public CommandBase {
public:
    Uart() = default;
    ~Uart() = default;
    std::string Execute(std::string type) override;
    void SetMessageToSend(std::string message) { message_ = message; }
private:
    std::string message_;
};

} // namespace communication

extern std::shared_ptr<Debug> debugger;
