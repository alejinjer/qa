#pragma once

class Exception {
public:
    Exception() = default;
    virtual ~Exception() = default;

    bool isCritical() const {
        return m_isCritical;
    }

protected:
    bool m_isCritical = true;
};

class Critical1 : public Exception {
public:
    Critical1() : Exception() {
        m_isCritical = true;
    }
};

class Critical2 : public Exception {
public:
    Critical2() : Exception() {
        m_isCritical = true;
    }
};

class NonCritical : public Exception {
public:
    NonCritical() : Exception() {
        m_isCritical = false;
    }
};
