/**
 * Main Testing Executable
 */

// Include Headersr
#include <gtest/gtest.h>

// Main Function
int main(int argc, char **argv) {
  // Initialize Google Test
  testing::InitGoogleTest(&argc, argv);

  // Run Tests
  return RUN_ALL_TESTS();
}
