#include "Engine.hpp"

double Engine::_blue(const color &c) {
  std::cout << c << ", " << m_colorsMax[m_colorMode] << std::endl;
  return map(c.b, 0, 255, 0, m_colorsMax[m_colorMode].b);
}