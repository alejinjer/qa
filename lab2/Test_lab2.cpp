#include <gtest/gtest.h>

#include "ExceptionManager.h"
#include "Server.h"

class FakeLoader : public ILoader {
   public:
    std::vector<std::string> loadFile() override {
        return std::vector<std::string>{"Critical1", "Critical2"};
    }
};

class FakeServer : public IServer {
    public:
        virtual bool processRequest(const std::string& s) override {
        return true;
    }
};

class TestExceptionManager : public ::testing::Test {
   protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    ExceptionManager getManager() {
        return ExceptionManager(std::make_shared<FakeLoader>());
    }
};

TEST_F(TestExceptionManager, isCritical_true) {
    ExceptionManager manager = getManager();
    Critical1 e1;
    Critical2 e2;

    EXPECT_TRUE(manager.processException(e1));
    EXPECT_TRUE(manager.processException(e2));
}

TEST_F(TestExceptionManager, isCritical_false) {
    ExceptionManager manager = getManager();
    NonCritical e;

    EXPECT_FALSE(manager.processException(e));
}

TEST_F(TestExceptionManager, test_getCriticalCount) {
    ExceptionManager manager = getManager();
    Critical1 crit1;
    NonCritical nonCrit;

    manager.processException(crit1);
    manager.processException(nonCrit);

    EXPECT_EQ(manager.getCriticalCount(), 1);
}

TEST_F(TestExceptionManager, test_getNonCriticalCount) {
    ExceptionManager manager = getManager();
    Critical1 crit1;
    NonCritical nonCrit;

    manager.processException(crit1);
    manager.processException(nonCrit);

    EXPECT_EQ(manager.getNonCriticalCount(), 1);
}

TEST_F(TestExceptionManager, test_getRequestFailedCount) {
    ExceptionManager manager = getManager();
    Critical1 crit1;

    manager.processException(crit1);
    EXPECT_EQ(manager.getRequestFailedCount(), 1);

    manager.setServer(std::make_shared<FakeServer>());

    manager.processException(crit1);
    EXPECT_EQ(manager.getRequestFailedCount(), 1);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
