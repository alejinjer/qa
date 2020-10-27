#include "ExceptionManager.h"

ExceptionManager::ExceptionManager()
    : m_criticalCount(0), m_nonCriticalCount(0) {}

bool ExceptionManager::processException(const Exception &e) {
    bool result;

    if (e.isCritical()) {
        ++m_criticalCount;
        result = true;
    } else {
        ++m_nonCriticalCount;
        result = false;
    }
    return result;
}

int ExceptionManager::getCriticalCount() const {
    return m_criticalCount;
}

int ExceptionManager::getNonCriticalCount() const {
    return m_nonCriticalCount;
}
