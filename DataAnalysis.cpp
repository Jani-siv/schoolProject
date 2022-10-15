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
    std::cout<<"maxSensorValue: "<<maxSensorValue<<std::endl;
    std::cout<<"minSensorValue: "<<minSensorValue<<std::endl;
    std::cout<<"avgSensorValue: "<<avgSensorValue<<std::endl;
    std::vector<double> data;
    data.push_back(maxSensorValue);
    data.push_back(minSensorValue);
    data.push_back(avgSensorValue);
    return data;
}

} // namespace analysis
