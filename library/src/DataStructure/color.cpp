#include "DataStructure/Color.hpp"
#include "Engine.hpp"

color_s::color_s() {
  r = 0;
  g = 0;
  b = 0;
  a = 255;
}

color_s::color_s(double v) {
  this->r = Engine::_map(v, 0, Engine::m_colorsMax[Engine::m_colorMode].r, 0, 255);
  this->g = Engine::_map(v, 0, Engine::m_colorsMax[Engine::m_colorMode].g, 0, 255);
  this->b = Engine::_map(v, 0, Engine::m_colorsMax[Engine::m_colorMode].b, 0, 255);
  this->a = 255;
}

color_s::color_s(double v, double a) {
  this->r = Engine::_map(v, 0, Engine::m_colorsMax[Engine::m_colorMode].r, 0, 255);
  this->g = Engine::_map(v, 0, Engine::m_colorsMax[Engine::m_colorMode].g, 0, 255);
  this->b = Engine::_map(v, 0, Engine::m_colorsMax[Engine::m_colorMode].b, 0, 255);
  this->a = Engine::_map(a, 0, Engine::m_colorsMax[Engine::m_colorMode].a, 0, 255);
}

color_s::color_s(double r, double g, double b) {
  this->r = Engine::_map(r, 0, Engine::m_colorsMax[Engine::m_colorMode].r, 0, 255);
  this->g = Engine::_map(g, 0, Engine::m_colorsMax[Engine::m_colorMode].g, 0, 255);
  this->b = Engine::_map(b, 0, Engine::m_colorsMax[Engine::m_colorMode].b, 0, 255);
  this->a = 255;
}

color_s::color_s(double r, double g, double b, double a) {
  this->r = Engine::_map(r, 0, Engine::m_colorsMax[Engine::m_colorMode].r, 0, 255);
  this->g = Engine::_map(g, 0, Engine::m_colorsMax[Engine::m_colorMode].g, 0, 255);
  this->b = Engine::_map(b, 0, Engine::m_colorsMax[Engine::m_colorMode].b, 0, 255);
  this->a = Engine::_map(a, 0, Engine::m_colorsMax[Engine::m_colorMode].a, 0, 255);
}


std::ostream& operator<<(std::ostream& os, const color& c) {
  os << "color(" << c.r << ", " << c.g << ", " << c.b << ", " << c.a << ")";
  return os;
}