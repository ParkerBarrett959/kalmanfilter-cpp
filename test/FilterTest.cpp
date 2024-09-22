/**
 * FilterTest.cpp
 * @Author: Parker Barrett
 * @Overview: This file contains the filter class unit tests
 */

// Include Statements
#include "Filter.h"
#include "gtest/gtest.h"

using namespace KalmanFilter;

// Filter Constructor Default
TEST(Filter, DefaultConstructor) {
  // Create Kalman Filter Objects
  Filter<int, 1> kfInt;
  Filter<float, 2> kfFloat;
  Filter<double, 2> kfDouble;

  // Check Size of Filter
  EXPECT_EQ(kfInt.size(), 1);
  EXPECT_EQ(kfFloat.size(), 2);
  EXPECT_EQ(kfDouble.size(), 2);

  // Extract State and Covariance
  State<int, 1> intState = kfInt.getFilterState();
  Covariance<int, 1> intCovariance = kfInt.getFilterCovariance();
  State<float, 2> floatState = kfFloat.getFilterState();
  Covariance<float, 2> floatCovariance = kfFloat.getFilterCovariance();
  State<double, 2> doubleState = kfDouble.getFilterState();
  Covariance<double, 2> doubleCovariance = kfDouble.getFilterCovariance();

  // Check Values
  EXPECT_EQ(intState(0), 0);
  EXPECT_EQ(intCovariance(0, 0), 1);
  EXPECT_EQ(floatState(0), 0);
  EXPECT_EQ(floatState(1), 0);
  EXPECT_EQ(floatCovariance(0, 0), 1);
  EXPECT_EQ(floatCovariance(0, 1), 0);
  EXPECT_EQ(floatCovariance(1, 0), 0);
  EXPECT_EQ(floatCovariance(1, 1), 1);
  EXPECT_EQ(doubleState(0), 0);
  EXPECT_EQ(doubleState(1), 0);
  EXPECT_EQ(doubleCovariance(0, 0), 1);
  EXPECT_EQ(doubleCovariance(0, 1), 0);
  EXPECT_EQ(doubleCovariance(1, 0), 0);
  EXPECT_EQ(doubleCovariance(1, 1), 1);
}