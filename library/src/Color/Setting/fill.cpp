#include "Engine.hpp"

void Engine::_fill(const double &gray) {
  auto c = color(gray);
  if (m_colorMode == HSB) {
    c = map(c, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c = HsvToRgb(c);
  }
  m_fillColor = color(c.r, c.g, c.b, c.a);
}

void Engine::_fill(const double &gray, const double &alpha) {
  auto c = color(gray, alpha);
  if (m_colorMode == HSB) {
    c = map(c, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c = HsvToRgb(c);
  }
  m_fillColor = color(c.r, c.g, c.b, c.a);
}

void Engine::_fill(const double &v1, const double &v2, const double &v3) {
  auto c = color(v1, v2, v3);
  if (m_colorMode == HSB) {
    c = map(c, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c = HsvToRgb(c);
  }
  m_fillColor = color(c.r, c.g, c.b, c.a);
}

void Engine::_fill(const double &v1, const double &v2, const double &v3, const double &a) {
  auto c = color(v1, v2, v3, a);
  if (m_colorMode == HSB) {
    c = map(c, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c = HsvToRgb(c);
  }
  m_fillColor = color(c.r, c.g, c.b, c.a);
}

void Engine::_fill(const color &c) {
  auto c2 = color(c);
  if (m_colorMode == HSB) {
    c2 = map(c2, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c2 = HsvToRgb(c2);
  }
  m_fillColor = color(c2.r, c2.g, c2.b, c2.a);
}

void Engine::_fill(const color &c, const double &alpha) {
  auto c2 = color(c.r, c.g, c.b, alpha);
  if (m_colorMode == HSB) {
    c2 = map(c2, color(0, 0, 0, 0), color(255, 255, 255, 255), color(0, 0, 0, 0), color(360, 100, 100));
    c2 = HsvToRgb(c2);
  }
  m_fillColor = color(c2.r, c2.g, c2.b, c2.a);
}