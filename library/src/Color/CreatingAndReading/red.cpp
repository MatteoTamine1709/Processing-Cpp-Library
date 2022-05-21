#include "Engine.hpp"

double Engine::_red(const color &c) {
  return map(c.r, 0, 255, 0, m_colorsMax[m_colorMode].r);
}