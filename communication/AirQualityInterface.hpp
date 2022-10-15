#pragma once

#include <vector>
#include "CommandBase.hpp"
namespace communication {

class AirQualityInteface : public CommandBase{
public:
    AirQualityInteface() = default;
    ~AirQualityInteface() = default;
    std::string Execute(std::string type) override;
    std::string GetAirQuality();
private:
    std::vector<std::string> dataPoints_ {};
    size_t currentDataPoint_ = 0;
    bool isDataGetFromFile_ = false;
};

} // namespace communication
