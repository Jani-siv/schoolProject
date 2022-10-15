#pragma once
#include <memory>
#include "debug/Debug.hpp"
#include "sensors/Aggregator.hpp"
#include "sensors/dataStructure.hpp"

namespace analysis {

class DataAnalysis
{
public:
    DataAnalysis();
    ~DataAnalysis() = default;
    std::vector<double> StartAnalysis(size_t samples);
private:
    sensors::Aggregator agg;
    std::vector<sensors::data_msg> data_;
    std::vector<double> analyse();
    std::shared_ptr<Debug> debugger;
};

} // namespace analysis