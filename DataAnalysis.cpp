#include <limits>
#include <memory>
#include "DataAnalysis.hpp"

namespace analysis {

std::vector<double> DataAnalysis::StartAnalysis(size_t samples)
{
    for (size_t i = 0; i < samples; i++)
    {
        data_.push_back(agg.GetDataFromSensors());
    }
    return analyse();
}
std::vector<double> DataAnalysis::analyse()
{
    double maxSensorValue=0;
    double minSensorValue=std::numeric_limits<double>::max();
    double avgSensorValue=0;
    for(auto&i : data_)
    {
        if (i.sensorValue > maxSensorValue) { maxSensorValue = i.sensorValue;}
        if (i.sensorValue < minSensorValue) { minSensorValue = i.sensorValue;}
        avgSensorValue += i.sensorValue;
    }
    avgSensorValue /= data_.size();
    //Todo Debug data to uart or file
    debugger->DebugMsg(std::to_string(maxSensorValue));
    debugger->DebugMsg(std::to_string(minSensorValue));
    debugger->DebugMsg(std::to_string(avgSensorValue));
    std::vector<double> data;
    data.push_back(maxSensorValue);
    data.push_back(minSensorValue);
    data.push_back(avgSensorValue);
    return data;
}
DataAnalysis::DataAnalysis()
{
    std::shared_ptr<communication::Command> command = std::make_shared<communication::Command>();
    debugger = std::make_shared<Debug>(command);
}

} // namespace analysis
