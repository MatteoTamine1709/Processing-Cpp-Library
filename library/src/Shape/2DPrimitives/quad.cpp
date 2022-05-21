#include "Engine.hpp"

void Engine::_quad(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3, const double &x4, const double &y4) {
  sf::ConvexShape shape;
  shape.setFillColor(m_fillColor);
  shape.setOutlineColor(m_strokeColor);
  shape.setOutlineThickness(m_strokeWeight);

  addPoint(shape, sf::Vector2f(x1, y1));
  addPoint(shape, sf::Vector2f(x2, y2));
  addPoint(shape, sf::Vector2f(x3, y3));
  addPoint(shape, sf::Vector2f(x4, y4));

  m_window->draw(shape);
}