#include "ExceptionManager.h"

#include <cxxabi.h>

#include <algorithm>

ExceptionManager::ExceptionManager(const std::shared_ptr<ILoader> &configLoader)
    : m_criticalCount(0)
    , m_nonCriticalCount(0)
    , m_requestFailedCount(0)
    , m_configLoader(configLoader)
    , m_criticalExceptions(std::move(m_configLoader->loadFile())) {}

bool ExceptionManager::processException(const Exception &e) {
    auto exceptionName = abi::__cxa_demangle(typeid(e).name(), 0, 0, 0);
    auto result = std::find_if(m_criticalExceptions.cbegin(), m_criticalExceptions.cend(), [&](const auto &s) {
                      return s == exceptionName;
                  }) != m_criticalExceptions.cend();

    if (result) {
        ++m_criticalCount;

        if (!m_server.get() || !(m_server.get()->processRequest(exceptionName))) {
            ++m_requestFailedCount;
        }
    } else {
        ++m_nonCriticalCount;
    }
    
    return result;
}

int ExceptionManager::getRequestFailedCount() const {
    return m_requestFailedCount;
}

void ExceptionManager::setServer(const std::shared_ptr<IServer> &server) {
    m_server = server;
}

int ExceptionManager::getCriticalCount() const {
    return m_criticalCount;
}

int ExceptionManager::getNonCriticalCount() const {
    return m_nonCriticalCount;
}
