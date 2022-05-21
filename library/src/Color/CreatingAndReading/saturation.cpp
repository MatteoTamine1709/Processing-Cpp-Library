#include "Engine.hpp"

double Engine::_saturation(const color &c) {
  return map(c.g, 0, 255, 0, m_colorsMax[m_colorMode].g);
}