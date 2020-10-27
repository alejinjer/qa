#pragma once

#include "Exceptions.h"
#include "IManager.h"

class ExceptionManager : public IManager {
public:
    ExceptionManager();

    virtual bool processException(const Exception& e) override;

    int getCriticalCount() const;

    int getNonCriticalCount() const;

private:
    int m_criticalCount;
    int m_nonCriticalCount;
};
