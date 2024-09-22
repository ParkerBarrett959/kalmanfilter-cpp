/**
 * StateTest.cpp
 * @Author: Parker Barrett
 * @Overview: This file contains the state class unit tests
 */

// Include Statements
#include "State.h"
#include "gtest/gtest.h"

using namespace KalmanFilter;

// State Default
TEST(State, DefaultConstructor) {
  // Create State Objects
  State<int, 1> stateInt;
  State<float, 2> stateFloat;
  State<double, 3> stateDouble;

  // Check Size and Values
  EXPECT_EQ(stateInt.size(), 1);
  EXPECT_EQ(stateInt(0), 0);
  EXPECT_EQ(stateFloat.size(), 2);
  EXPECT_EQ(stateFloat(0), 0);
  EXPECT_EQ(stateFloat(1), 0);
  EXPECT_EQ(stateDouble.size(), 3);
  EXPECT_EQ(stateDouble(0), 0);
  EXPECT_EQ(stateDouble(1), 0);
  EXPECT_EQ(stateDouble(2), 0);

  // Test Index Operator outside bounds of state size
  EXPECT_EQ(stateDouble(-1), 0);
  EXPECT_EQ(stateDouble(3), 0);
}

// Array Constructor
TEST(State, ArrayConstructor) {
  // Create Arrays
  int arrayInt[1] = {1};
  float arrayFloat[2] = {1.0, 2.0};
  double arrayDouble[3] = {1.0, 2.0, 3.0};

  // Create State Objects
  State<int, 1> stateInt(arrayInt);
  State<float, 2> stateFloat(arrayFloat);
  State<double, 3> stateDouble(arrayDouble);

  // Check Size and Values
  EXPECT_EQ(stateInt.size(), 1);
  EXPECT_EQ(stateInt(0), 1);
  EXPECT_EQ(stateFloat.size(), 2);
  EXPECT_EQ(stateFloat(0), 1.0);
  EXPECT_EQ(stateFloat(1), 2.0);
  EXPECT_EQ(stateDouble.size(), 3);
  EXPECT_EQ(stateDouble(0), 1.0);
  EXPECT_EQ(stateDouble(1), 2.0);
  EXPECT_EQ(stateDouble(2), 3.0);
}

// Std::Vector Constructor
TEST(State, StdVectorConstructor) {
  // Create Arrays
  std::vector<int> intVec{1};
  std::vector<float> floatVec{1.0, 2.0};
  std::vector<double> doubleVec{1.0, 2.0, 3.0};

  // Create State Objects
  State<int, 1> stateInt(intVec);
  State<float, 2> stateFloat(floatVec);
  State<double, 3> stateDouble(doubleVec);

  // Check Size and Values
  EXPECT_EQ(stateInt.size(), 1);
  EXPECT_EQ(stateInt(0), 1);
  EXPECT_EQ(stateFloat.size(), 2);
  EXPECT_EQ(stateFloat(0), 1.0);
  EXPECT_EQ(stateFloat(1), 2.0);
  EXPECT_EQ(stateDouble.size(), 3);
  EXPECT_EQ(stateDouble(0), 1.0);
  EXPECT_EQ(stateDouble(1), 2.0);
  EXPECT_EQ(stateDouble(2), 3.0);

  // Check for Vector Size Mismatch
  State<double, 2> stateDoubleTooSmall(doubleVec);
  EXPECT_EQ(stateDoubleTooSmall(0), 1.0);
  EXPECT_EQ(stateDoubleTooSmall(1), 2.0);
  State<double, 4> stateDoubleTooBig(doubleVec);
  EXPECT_EQ(stateDoubleTooBig(0), 1.0);
  EXPECT_EQ(stateDoubleTooBig(1), 2.0);
  EXPECT_EQ(stateDoubleTooBig(2), 3.0);
  EXPECT_EQ(stateDoubleTooBig(3), 0.0);
}

// Eigen::Vector Constructor
TEST(State, EigenVectorConstructor) {
  // Create Arrays
  Eigen::Vector<int, 1> vectorInt(1);
  Eigen::Vector<float, 2> vectorFloat(1.0, 2.0);
  Eigen::Vector<double, 3> vectorDouble(1.0, 2.0, 3.0);

  // Create State Objects
  State<int, 1> stateInt(vectorInt);
  State<float, 2> stateFloat(vectorFloat);
  State<double, 3> stateDouble(vectorDouble);

  // Check Size and Values
  EXPECT_EQ(stateInt.size(), 1);
  EXPECT_EQ(stateInt(0), 1);
  EXPECT_EQ(stateFloat.size(), 2);
  EXPECT_EQ(stateFloat(0), 1.0);
  EXPECT_EQ(stateFloat(1), 2.0);
  EXPECT_EQ(stateDouble.size(), 3);
  EXPECT_EQ(stateDouble(0), 1.0);
  EXPECT_EQ(stateDouble(1), 2.0);
  EXPECT_EQ(stateDouble(2), 3.0);
}