#pragma once
#include "communication/Command.hpp"
#include <iostream>

class Debug {
public:
    Debug(communication::Command& command)
    {
        command_ = &command;
    }
    ~Debug() = default;
    void DebugMsg(std::string msg)
    {
        command_->setUartMessage("debugSend",msg);
        command_->Execute("debugFileMock");
    }
private:
    communication::Command* command_;
};