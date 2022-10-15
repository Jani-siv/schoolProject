#pragma once

#include "CommandBase.hpp"
namespace communication {

class AirQualityInteface : public CommandBase{
public:
    AirQualityInteface() = default;
    ~AirQualityInteface() = default;
    std::string Execute(std::string type) override {return "";}

};

} // namespace communication
