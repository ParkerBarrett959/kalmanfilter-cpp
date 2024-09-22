/**
 * Filter.h
 * @Author: Parker Barrett
 * @Overview: This class contains the Kalman filter implementation
 */

#ifndef FILTER_H
#define FILTER_H

#include "Covariance.h"
#include "State.h"

namespace KalmanFilter {

template <typename T, int Size>
class Filter {
 public:
  /**
   * Default c'tor
   *
   * Note: The default state vector is zeros, and the default covariance is
   * identity.
   */
  Filter()
      : mState(Eigen::Vector<T, Size>::Zero()),
        mCovariance(Eigen::Matrix<T, Size, Size>::Identity()) {}

  /**
   * Get the filter size
   *
   * @return The size (number of states) of the filter
   */
  int size() const { return Size; }

  /**
   * Get the underlying filter state
   *
   * @return A mutable copy of the filter state
   */
  State<T, Size> getFilterState() const { return mState; }

  /**
   * Get the underlying filter covariance
   *
   * @return A mutable copy of the filter covariance
   */
  Covariance<T, Size> getFilterCovariance() const { return mCovariance; }

 private:
  // Filter State
  State<T, Size> mState;

  // Filter Covariance
  Covariance<T, Size> mCovariance;
};
}  // namespace KalmanFilter

#endif  // FILTER_H