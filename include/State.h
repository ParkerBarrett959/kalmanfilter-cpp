/**
 * State.h
 * @Author: Parker Barrett
 * @Overview: This class contains the Kalman filter state data and utility
 * functions.
 */

#ifndef STATE_H
#define STATE_H

#include <Eigen/Dense>

namespace KalmanFilter {

template <typename T, int Size>
class State {
 public:
  /**
   * Default c'tor
   */
  State() : mStateVector(Eigen::Vector<T, Size>::Zero()) {}

  /**
   * c'tor with C++ array
   *
   * @param stateArray C++ array of values to initialize the state with
   */
  State(const T stateArray[Size])
      : mStateVector(Eigen::Vector<T, Size>::Zero()) {
    for (int i = 0; i < Size; i++) {
      mStateVector(i) = stateArray[i];
    }
  }

  /**
   * c'tor with C++ std::vector
   *
   * @param stateVector C++ std::vector of values to initialize the state with
   * Note: If you provide a vector with less elements than the state, the
   * trailing elements will be left as zero. If you provide a vector with more
   * elements than the state, the extra elements will be ignored.
   */
  State(const std::vector<T>& stateVector)
      : mStateVector(Eigen::Vector<T, Size>::Zero()) {
    for (int i = 0; i < stateVector.size(); i++) {
      if (i >= Size) {
        continue;
      }
      mStateVector(i) = stateVector[i];
    }
  }

  /**
   * c'tor with C++ Eigen::Vector
   *
   * @param stateVector C++ Eigen::Vector of values to initialize the state with
   */
  State(const Eigen::Vector<T, Size>& stateVector)
      : mStateVector(stateVector) {}

  /**
   * Get Size of State
   *
   * @return An integer denoting the number of states in the state vector.
   */
  int size() const { return mStateVector.size(); }

  /**
   * Get the value of the state at a specifix index (0->Size-1)
   *
   * @param idx The index to query the underlying data
   * @return The value at the index. If the index is invalid, the value zero is
   * returned.
   */
  T operator()(const int idx) const {
    if (idx < 0 || idx >= mStateVector.size()) {
      return 0;
    }
    return mStateVector(idx);
  }

 private:
  // Underlying state data
  Eigen::Vector<T, Size> mStateVector;
};
}  // namespace KalmanFilter

#endif  // STATE_H