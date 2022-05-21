#include "Engine.hpp"

void Engine::_background(const double &gray) {
  auto c = color(gray);
  if (m_colorMode == HSB) {
    c = map(c, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c = HsvToRgb(c);
  }
  m_window->clear(sf::Color(c.r, c.g, c.b, c.a));
}

void Engine::_background(const double &v1, const double &v2, const double &v3) {
  auto c = color(v1, v2, v3);
  if (m_colorMode == HSB) {
    c = map(c, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c = HsvToRgb(c);
  }
  m_window->clear(sf::Color(c.r, c.g, c.b, c.a));
}

void Engine::_background(const color &c) {
  auto c2 = color(c);
  if (m_colorMode == HSB) {
    c2 = map(c2, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c2 = HsvToRgb(c2);
  }
  m_window->clear(sf::Color(c2.r, c2.g, c2.b, c2.a));
}