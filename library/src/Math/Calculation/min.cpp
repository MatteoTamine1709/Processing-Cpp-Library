#include "Engine.hpp"

double Engine::_min(const double &value1, const double &value2) {
  return (value1 < value2) ? value1 : value2;
}

double Engine::_min(const double &value1, const double &value2, const double &value3) {
  return (value1 < value2) ? ((value1 < value3) ? value1 : value3) : ((value2 < value3) ? value2 : value3);
}

double Engine::_min(const std::vector<double> &values) {
  double min = values[0];
  for (size_t i = 1; i < values.size(); i++)
    if (values[i] < min)
      min = values[i];
  return min;
}