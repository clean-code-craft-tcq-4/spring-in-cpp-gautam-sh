#ifndef STATS_H
#define STATS_H

#pragma GCC system_header
// #include "real_3rd_party_header.h"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

namespace Statistics {

class Stats {
public:
  double min, max, average;
};

Stats ComputeStatistics(const std::vector<double> &);
} // namespace Statistics

class IAlerter {
public:
  bool emailSent = false;
  bool ledGlows = false;
};

class EmailAlert : public IAlerter {
public:
  bool emailSent;
};

class LEDAlert : public IAlerter {
public:
  bool ledGlows;
};

class StatsAlerter {
public:
  StatsAlerter() = default;
  StatsAlerter(const float maxThreshold, std::vector<IAlerter *> &alerters) {
    maxThreshold_ = maxThreshold;
    alerters_ = alerters;
  }

  float maxThreshold_;
  std::vector<IAlerter *> alerters_;

  void checkAndAlert(const std::vector<double> &);
};

#endif