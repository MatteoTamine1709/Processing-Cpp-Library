#include "Engine.hpp"

void Engine::_square(const double &x, const double &y, const double &w) {
  double posX = x;
  double posY = y;
  double width = w;
  if (m_rectMode == CORNERS) {
    width -= x;
  } else if (m_rectMode == RADIUS) {
    posX -= width;
    posY -= width;
    width *= 2;
  } else if (m_rectMode == CENTER) {
    posX -= width / 2;
    posY -= width / 2;
  }
  auto shape = sf::RectangleShape(sf::Vector2f(width, width));
  shape.setPosition(posX, posY);
  shape.setFillColor(m_fillColor);
  shape.setOutlineColor(m_strokeColor);
  shape.setOutlineThickness(m_strokeWeight);
  m_window->draw(shape);
}