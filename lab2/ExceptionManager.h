#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ConfigLoader.h"
#include "Exceptions.h"
#include "Server.h"

class IManager {
   public:
    virtual bool processException(const Exception& e) = 0;
};

class ExceptionManager : public IManager {
   public:
    ExceptionManager() = delete;
    ExceptionManager(const std::shared_ptr<ILoader> &configLoader);

    virtual bool processException(const Exception& e) override;

    int getCriticalCount() const;

    int getNonCriticalCount() const;

    int getRequestFailedCount() const;

    void setServer(const std::shared_ptr<IServer> &server);

   private:
    int m_criticalCount;
    int m_nonCriticalCount;
    int m_requestFailedCount;
    std::shared_ptr<IServer> m_server;
    std::shared_ptr<ILoader> m_configLoader;
    std::vector<std::string> m_criticalExceptions;
};
