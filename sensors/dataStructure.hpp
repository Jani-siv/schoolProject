#pragma once
namespace sensors{

struct data_msg{
    double timestamp{};
    double longitude{};
    double latitude{};
    double sensorValue{};
};

} // sensors