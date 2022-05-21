#include "Engine.hpp"

void Engine::_colorMode(const int &mode) {
  m_colorMode = mode;
}

void Engine::_colorMode(const int &mode, const double &max) {
  m_colorMode = mode;
  m_colorsMax[mode].r = max;
  m_colorsMax[mode].g = max;
  m_colorsMax[mode].b = max;
  m_colorsMax[mode].a = max;
}

void Engine::_colorMode(const int &mode, const double &max1, const double &max2, const double &max3) {
  m_colorMode = mode;
  m_colorsMax[mode].r = max1;
  m_colorsMax[mode].g = max2;
  m_colorsMax[mode].b = max3;
  m_colorsMax[mode].a = 255;
}

void Engine::_colorMode(const int &mode, const double &max1, const double &max2, const double &max3, const double &maxA) {
  m_colorMode = mode;
  m_colorsMax[mode].r = max1;
  m_colorsMax[mode].g = max2;
  m_colorsMax[mode].b = max3;
  m_colorsMax[mode].a = maxA;
}