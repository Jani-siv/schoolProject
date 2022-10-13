#include "Uart.hpp"

namespace communication {


std::string Uart::Execute([[maybe_unused]] std::string type)
{
    if (type.find("gpsRecv") == 0)
    {
        //read data
        return "recv";
    }
    else if (type.find("gpsSend") == 0)
    {
        return message_;
    }
    else if (type.find("debugSend")== 0)
    {
        return message_;
    }
    else if (type.find("debugRecv") == 0)
    {
        return "recv";
    }
    return "Error";
}
} // namespace communication