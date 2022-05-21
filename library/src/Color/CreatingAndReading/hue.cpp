#include "Engine.hpp"

double Engine::_hue(const color &c) {
  return map(c.r, 0, 255, 0, m_colorsMax[m_colorMode].r);
}