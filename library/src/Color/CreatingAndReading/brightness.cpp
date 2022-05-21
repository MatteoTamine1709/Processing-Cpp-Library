#include "Engine.hpp"

double Engine::_brightness(const color &c) {
  return map(c.b, 0, 255, 0, m_colorsMax[m_colorMode].b);
}