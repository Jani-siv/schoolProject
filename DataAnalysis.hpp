#pragma once
#include <memory>
#include "debug/Debug.hpp"

std::shared_ptr<Debug> debugger = std::make_shared<Debug>();

class DataAnalysis {

public:
    DataAnalysis() = default;
    ~DataAnalysis() = default;
};