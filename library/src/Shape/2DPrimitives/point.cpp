#include "Engine.hpp"

void Engine::_point(const double &x, const double &y) {
  auto point = sf::Vertex(sf::Vector2f(x, y), m_strokeColor);
  m_window->draw(&point, 1, sf::Points);
}