#pragma once
#include <string>
namespace communication {

class CommandBase {
public:
    virtual std::string Execute(std::string type)=0;
    CommandBase() = default;
};

} // namespace communication
