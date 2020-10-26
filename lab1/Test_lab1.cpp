#include <gtest/gtest.h>
#include "ExceptionManager.h"

TEST(ExceptionManagerTest, isCritical_true) {
    ExceptionManager manager;
    Critical1 e1;
    Critical2 e2;

    EXPECT_TRUE(manager.processException(e1));
    EXPECT_TRUE(manager.processException(e2));
}

TEST(ExceptionManagerTest, isCritical_false) {
    ExceptionManager manager;
    NonCritical e;

    EXPECT_FALSE(manager.processException(e));
}

TEST(ExceptionManagerTest, exceptionsCounters) {
    ExceptionManager manager;
    Critical1 crit1;
    Critical2 crit2;
    NonCritical nonCrit;

    manager.processException(crit1);
    manager.processException(crit2);
    manager.processException(nonCrit);

    EXPECT_EQ(manager.getCriticalCount(), 2);
    EXPECT_EQ(manager.getNonCriticalCount(), 1);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
