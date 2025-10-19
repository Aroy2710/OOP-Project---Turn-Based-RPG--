

#include "UnitTests.h"
// main file to run the tests for player class
int main() {
  UnitTests UnitTest;
  UnitTest.runNormalOperationTests();
  UnitTest.runEdgeCaseTests();
  UnitTest.testBattleManager();
  return 0;
}
