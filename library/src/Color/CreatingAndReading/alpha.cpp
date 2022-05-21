#include "Engine.hpp"

double Engine::_alpha(const color &c) {
  return map(c.a, 0, 255, 0, m_colorsMax[m_colorMode].a);
}