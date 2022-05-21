#include "Engine.hpp"

double Engine::_lerp(const double &v1, const double &v2, const double &amt) {
  return v1 + (v2 - v1) * amt;
}