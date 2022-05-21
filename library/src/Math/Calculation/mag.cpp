#include "Engine.hpp"

double Engine::_mag(const double &x, const double &y) {
  return sqrt(x * x + y * y);
}

double Engine::_mag(const double &x, const double &y, const double &z) {
  return sqrt(x * x + y * y + z * z);
}