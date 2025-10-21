

#include "UnitTests.h"
#include "GameManager.h"

// main file to run the tests for player class
int main() {
  UnitTests UnitTest;
  UnitTest.runNormalOperationTests();
  UnitTest.runEdgeCaseTests();

  // GameManager game;

  return 0;
}
