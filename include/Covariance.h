/**
 * Covariance.h
 * @Author: Parker Barrett
 * @Overview: This class contains the Kalman filter covariance data and utility
 * functions.
 */

#ifndef COVARIANCE_H
#define COVARIANCE_H

#include <Eigen/Dense>

namespace KalmanFilter {

template <typename T, int Size>
class Covariance {
 public:
  /**
   * Default c'tor
   *
   * Note: The default covariance matrix is identity.
   */
  Covariance() : mCovarianceMatrix(Eigen::Matrix<T, Size, Size>::Identity()) {}

  /**
   * c'tor with C++ array
   *
   * @param CovarianceArray C++ array of values to initialize the Covariance
   * with
   */
  Covariance(const T CovarianceArray[Size][Size])
      : mCovarianceMatrix(Eigen::Matrix<T, Size, Size>::Zero()) {
    for (int i = 0; i < Size; i++) {
      for (int j = 0; j < Size; j++) {
        mCovarianceMatrix(i, j) = CovarianceArray[i][j];
      }
    }
  }

  /**
   * c'tor with C++ std::vector<std::vector>
   *
   * @param CovarianceMatrix C++ nested std::vector of values to initialize the
   * Covariance with Note: The outer vector corresponds to the row index, while
   * the inner vector corresponds to the column index. If the vectors have less
   * elements than the covariance matrix, the rows/columns respectively will be
   * left as zero. If the vectors have more elemnts than the covariance matrix,
   * extra values will be ignored.
   */
  Covariance(const std::vector<std::vector<T>>& CovarianceMatrix)
      : mCovarianceMatrix(Eigen::Matrix<T, Size, Size>::Zero()) {
    for (int i = 0; i < CovarianceMatrix.size(); i++) {
      if (i >= Size) {
        continue;
      }
      for (int j = 0; j < CovarianceMatrix[i].size(); j++) {
        if (j >= Size) {
          continue;
        }
        mCovarianceMatrix(i, j) = CovarianceMatrix[i][j];
      }
    }
  }

  /**
   * c'tor with C++ Eigen::Matrix
   *
   * @param CovarianceMatrix C++ Eigen::Matrix of values to initialize the
   * Covariance with
   */
  Covariance(const Eigen::Matrix<T, Size, Size>& CovarianceMatrix)
      : mCovarianceMatrix(CovarianceMatrix) {}

  /**
   * Get Size of Covariance
   *
   * @return An integer denoting the number of rows/columns in the Covariance
   * matrix.
   */
  int size() const { return mCovarianceMatrix.cols(); }

  /**
   * Get the value of the Covariance at a specifix index (0->Size-1)
   *
   * @param idxI The row index to query the underlying data
   * @param idxJ The column index to query the underlying data
   * @return The value at the index. If the index is invalid, the value zero is
   * returned.
   */
  T operator()(const int idxI, const int idxJ) const {
    if (idxI < 0 || idxI >= mCovarianceMatrix.rows()) {
      return 0;
    }
    if (idxJ < 0 || idxJ >= mCovarianceMatrix.cols()) {
      return 0;
    }
    return mCovarianceMatrix(idxI, idxJ);
  }

 private:
  // Underlying Covariance Matrix
  Eigen::Matrix<T, Size, Size> mCovarianceMatrix;
};
}  // namespace KalmanFilter

#endif  // COVARIANCE_H