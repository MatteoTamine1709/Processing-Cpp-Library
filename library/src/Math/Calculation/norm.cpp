#include "Engine.hpp"

double Engine::_norm(const double &value, const double &min, const double &max) {
  return (value - min) / (max - min);
}