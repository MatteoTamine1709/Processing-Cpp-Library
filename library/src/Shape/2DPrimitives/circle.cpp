#include "Engine.hpp"

void Engine::_circle(const double &x, const double &y, const double &radius) {
  double r = radius / 2;
  double posX = x;
  double posY = y;
  if (m_ellipseMode == RADIUS) {
    r = radius;
  } else if (m_ellipseMode == CORNER) {
    posX += r;
    posY += r;
  } else if (m_ellipseMode == CORNERS) {
    r /= 2;
    posX += r;
    posY += r;
  }
  sf::CircleShape shape(r);
  shape.setFillColor(m_fillColor);
  shape.setOutlineColor(m_strokeColor);
  shape.setOutlineThickness(m_strokeWeight);
  shape.setPosition(posX - r, posY - r);
  m_window->draw(shape);
}