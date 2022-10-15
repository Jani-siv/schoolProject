#pragma once
#include <memory>
#include "debug/Debug.hpp"
#include "sensors/Aggregator.hpp"
#include "sensors/dataStructure.hpp"

namespace analysis {

class DataAnalysis
{
public:
    DataAnalysis() = default;
    ~DataAnalysis() = default;
    std::vector<double> StartAnalysis(size_t samples);
private:
    sensors::Aggregator agg;
    std::vector<sensors::data_msg> data_;
    std::vector<double> analyse();
};

} // namespace analysis