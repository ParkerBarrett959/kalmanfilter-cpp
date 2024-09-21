/**
 * CovarianceTest.h
 */

// Include Statements
#include "Covariance.h"
#include "gtest/gtest.h"

using namespace KalmanFilter;

// Covariance Default
TEST(Covariance, DefaultConstructor) {
  // Create Covariance Objects
  Covariance<int, 1> CovarianceInt;
  Covariance<float, 2> CovarianceFloat;
  Covariance<double, 2> CovarianceDouble;

  // Check Size and Values
  EXPECT_EQ(CovarianceInt.size(), 1);
  EXPECT_EQ(CovarianceInt(0, 0), 0);
  EXPECT_EQ(CovarianceFloat.size(), 2);
  EXPECT_EQ(CovarianceFloat(0, 0), 0);
  EXPECT_EQ(CovarianceFloat(0, 1), 0);
  EXPECT_EQ(CovarianceFloat(1, 0), 0);
  EXPECT_EQ(CovarianceFloat(1, 1), 0);
  EXPECT_EQ(CovarianceDouble.size(), 2);
  EXPECT_EQ(CovarianceDouble(0, 0), 0);
  EXPECT_EQ(CovarianceDouble(0, 1), 0);
  EXPECT_EQ(CovarianceDouble(1, 0), 0);
  EXPECT_EQ(CovarianceDouble(1, 1), 0);

  // Test Index Operator outside bounds of Covariance size
  EXPECT_EQ(CovarianceDouble(-1, 0), 0);
  EXPECT_EQ(CovarianceDouble(2, 0), 0);
  EXPECT_EQ(CovarianceDouble(0, -1), 0);
  EXPECT_EQ(CovarianceDouble(0, 2), 0);
}

// Array Constructor
TEST(Covariance, ArrayConstructor) {
  // Create Arrays
  int arrayInt[1][1] = {{1}};
  float arrayFloat[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
  double arrayDouble[2][2] = {{1.0, 2.0}, {3.0, 4.0}};

  // Create Covariance Objects
  Covariance<int, 1> CovarianceInt(arrayInt);
  Covariance<float, 2> CovarianceFloat(arrayFloat);
  Covariance<double, 2> CovarianceDouble(arrayDouble);

  // Check Size and Values
  EXPECT_EQ(CovarianceInt.size(), 1);
  EXPECT_EQ(CovarianceInt(0, 0), 1);
  EXPECT_EQ(CovarianceFloat.size(), 2);
  EXPECT_EQ(CovarianceFloat(0, 0), 1.0);
  EXPECT_EQ(CovarianceFloat(0, 1), 2.0);
  EXPECT_EQ(CovarianceFloat(1, 0), 3.0);
  EXPECT_EQ(CovarianceFloat(1, 1), 4.0);
  EXPECT_EQ(CovarianceDouble.size(), 2);
  EXPECT_EQ(CovarianceDouble(0, 0), 1.0);
  EXPECT_EQ(CovarianceDouble(0, 1), 2.0);
  EXPECT_EQ(CovarianceDouble(1, 0), 3.0);
  EXPECT_EQ(CovarianceDouble(1, 1), 4.0);
}

// Std::Vector Constructor
TEST(Covariance, StdVectorConstructor) {
  // Create Arrays
  std::vector<std::vector<int>> intVec{{1}};
  std::vector<std::vector<float>> floatVec{{1.0, 2.0}, {3.0, 4.0}};
  std::vector<std::vector<double>> doubleVec{{1.0, 2.0}, {3.0, 4.0}};

  // Create Covariance Objects
  Covariance<int, 1> CovarianceInt(intVec);
  Covariance<float, 2> CovarianceFloat(floatVec);
  Covariance<double, 2> CovarianceDouble(doubleVec);

  // Check Size and Values
  EXPECT_EQ(CovarianceInt.size(), 1);
  EXPECT_EQ(CovarianceInt(0, 0), 1);
  EXPECT_EQ(CovarianceFloat.size(), 2);
  EXPECT_EQ(CovarianceFloat(0, 0), 1.0);
  EXPECT_EQ(CovarianceFloat(0, 1), 2.0);
  EXPECT_EQ(CovarianceFloat(1, 0), 3.0);
  EXPECT_EQ(CovarianceFloat(1, 1), 4.0);
  EXPECT_EQ(CovarianceDouble.size(), 2);
  EXPECT_EQ(CovarianceDouble(0, 0), 1.0);
  EXPECT_EQ(CovarianceDouble(0, 1), 2.0);
  EXPECT_EQ(CovarianceDouble(1, 0), 3.0);
  EXPECT_EQ(CovarianceDouble(1, 1), 4.0);
}

// Eigen::Matrix Constructor
TEST(Covariance, EigenMatrixConstructor) {
  // Create Arrays
  Eigen::Matrix<int, 1, 1> matrixInt;
  matrixInt << 1;
  Eigen::Matrix<float, 2, 2> matrixFloat;
  matrixFloat << 1.0, 2.0, 3.0, 4.0;
  Eigen::Matrix<double, 2, 2> matrixDouble;
  matrixDouble << 1.0, 2.0, 3.0, 4.0;

  // Create Covariance Objects
  Covariance<int, 1> CovarianceInt(matrixInt);
  Covariance<float, 2> CovarianceFloat(matrixFloat);
  Covariance<double, 2> CovarianceDouble(matrixDouble);

  // Check Size and Values
  EXPECT_EQ(CovarianceInt.size(), 1);
  EXPECT_EQ(CovarianceInt(0, 0), 1);
  EXPECT_EQ(CovarianceFloat.size(), 2);
  EXPECT_EQ(CovarianceFloat(0, 0), 1.0);
  EXPECT_EQ(CovarianceFloat(0, 1), 2.0);
  EXPECT_EQ(CovarianceFloat(1, 0), 3.0);
  EXPECT_EQ(CovarianceFloat(1, 1), 4.0);
  EXPECT_EQ(CovarianceDouble.size(), 2);
  EXPECT_EQ(CovarianceDouble(0, 0), 1.0);
  EXPECT_EQ(CovarianceDouble(0, 1), 2.0);
  EXPECT_EQ(CovarianceDouble(1, 0), 3.0);
  EXPECT_EQ(CovarianceDouble(1, 1), 4.0);
}