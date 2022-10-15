#include <filesystem>
#include <fstream>
#include <iostream>
#include "AirQualityInterface.hpp"

namespace communication {

std::string AirQualityInteface::GetAirQuality()
{
    std::string dummy = "";
    return dummy;
}
std::string AirQualityInteface::Execute(std::string type)
{
    std::string data;
    if (type == "recvAirFileMock") {
        if (!isDataGetFromFile_) {
            std::string projectName = "schoolProject";
            std::string path = std::filesystem::current_path();
            path = path.substr(0,path.find(projectName)+projectName.length());
            path += "/communication/mock/airData.txt";
            std::ifstream fd(path, std::ios_base::in);
            std::string line;
            if (fd.is_open())
            {
                while(!fd.eof())
                {
                    std::getline(fd,line);
                    dataPoints_.push_back(line);
                }
            }
            fd.close();
            isDataGetFromFile_ = true;
            data = dataPoints_.at(currentDataPoint_);
            currentDataPoint_++;
            return data;
        }
        else
        {
            if (currentDataPoint_ < dataPoints_.size())
            {
                data = dataPoints_.at(currentDataPoint_);
                currentDataPoint_++;
                return data;
            }
            else
            {
                currentDataPoint_ = 1;
                return dataPoints_.at(0);
            }
        }
    }
    else {
        return GetAirQuality();
    }
}
} // namespace communication
