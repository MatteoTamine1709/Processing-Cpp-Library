#include "Engine.hpp"

void Engine::_line(const double &x1, const double &y1, const double &x2, const double &y2) {
  auto line = getLine({(float)x1, (float)y1}, {(float)x2, (float)y2});

  m_window->draw(line);
}