#include "Engine.hpp"

void Engine::_ellipse(const double &x, const double &y, const double &width, const double &height) {
  double radiusX = width / 2;
  double radiusY = height / 2;
  double posX = x;
  double posY = y;
  if (m_ellipseMode == RADIUS) {
    radiusX = width;
    radiusY = height;
  } else if (m_ellipseMode == CORNER) {
    posX += radiusX;
    posY += radiusY;
  } else if (m_ellipseMode == CORNERS) {
    radiusX /= 2;
    radiusY /= 2;
    posX += radiusX;
    posY += radiusY;
  }
  sf::ConvexShape shape;
  shape.setFillColor(m_fillColor);
  shape.setOutlineColor(m_strokeColor);
  shape.setOutlineThickness(m_strokeWeight);

  for (double i = 0; i < 360.f; i++) {
    double angle = i * M_PI / 180.f;
    double xPos = posX + cos(angle) * radiusX;
    double yPos = posY + sin(angle) * radiusY;
    addPoint(shape, sf::Vector2f(xPos, yPos));
  }

  m_window->draw(shape);
}