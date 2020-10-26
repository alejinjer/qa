#pragma once

#include <string>
#include <vector>

class ILoader {
   public:
    virtual std::vector<std::string> loadFile() = 0;
};
