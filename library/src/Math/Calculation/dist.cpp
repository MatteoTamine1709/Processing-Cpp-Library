#include "Engine.hpp"

double Engine::_dist(const double &x1, const double &y1, const double &x2, const double &y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double Engine::_dist(const double &x1, const double &y1, const double &z1, const double &x2, const double &y2, const double &z2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}