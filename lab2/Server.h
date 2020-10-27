#pragma once

#include <string>

class IServer {
   public:
    virtual bool processRequest(const std::string&) = 0;
};
