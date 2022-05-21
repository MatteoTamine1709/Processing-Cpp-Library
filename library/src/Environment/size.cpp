#include "Engine.hpp"

void Engine::_size(const int &w, const int &h, const int &renderer) {
  if (renderer == SFML) {
    Engine::m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w, h), "ProcessingCpp");
  }
}