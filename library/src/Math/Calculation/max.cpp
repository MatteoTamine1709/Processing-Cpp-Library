#include "Engine.hpp"

double Engine::_max(const double &value1, const double &value2) {
  return (value1 > value2) ? value1 : value2;
}

double Engine::_max(const double &value1, const double &value2, const double &value3) {
  return (value1 > value2) ? ((value1 > value3) ? value1 : value3) : ((value2 > value3) ? value2 : value3);
}

double Engine::_max(const std::vector<double> &values) {
  double max = values[0];
  for (size_t i = 1; i < values.size(); i++)
    if (values[i] > max)
      max = values[i];
  return max;
}