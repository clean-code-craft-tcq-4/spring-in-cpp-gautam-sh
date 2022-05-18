#include "stats.h"

Statistics::Stats
Statistics::ComputeStatistics(const std::vector<double> &number) {
  Statistics::Stats stats;
  std::vector<double> numbers = number;

  if (!numbers.size()) {
    stats.average = std::numeric_limits<double>::quiet_NaN();
    stats.max = std::numeric_limits<double>::quiet_NaN();
    stats.min = std::numeric_limits<double>::quiet_NaN();

    return stats;
  }
  stats.min = *std::min_element(number.begin(), number.end());
  stats.max = *std::max_element(number.begin(), number.end());
  stats.average =
      std::accumulate(number.begin(), number.end(), 0.000) / number.size();

  return stats;
}

void StatsAlerter::checkAndAlert(const std::vector<double> &input) {
  if (*std::max_element(input.begin(), input.end()) >
      StatsAlerter::maxThreshold_) {
    alerters_[0]->emailSent = true;
    alerters_[1]->ledGlows = true;
    return;
  }
  alerters_[0]->emailSent = false;
  alerters_[1]->ledGlows = false;
  return;
}
