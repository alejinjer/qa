#include "Exceptions.h"

class IManager {
public:
    virtual bool processException(const Exception& e) = 0;
};
