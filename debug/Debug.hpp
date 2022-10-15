#pragma once
#include "communication/Command.hpp"
#include <iostream>

class Debug {
public:
    Debug(std::shared_ptr<communication::Command>& command)
    {
        command_ = command;
    }
    ~Debug()
    {
        remove("/tmp/unit_test");
    }
    void DebugMsg(std::string msg)
    {
        command_->setUartMessage("debugSend",msg);
        command_->Execute("debugFileMock");
    }
private:
    std::shared_ptr<communication::Command> command_;
};