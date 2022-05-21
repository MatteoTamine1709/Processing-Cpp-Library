#include "Engine.hpp"

double Engine::_map(const double &value, const double &start1, const double &stop1, const double &start2, const double &stop2) {
  return start2 + (stop2 - start2) * ((value - start1) / ((stop1 - start1) == 0 ? 1 : stop1 - start1));
}