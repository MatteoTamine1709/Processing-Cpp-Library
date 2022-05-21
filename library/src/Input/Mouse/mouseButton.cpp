#include "Engine.hpp"

int Engine::_mouseButton() {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    return LEFT;
  else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    return RIGHT;
  else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
    return CENTER;
  else
    return NONE;
}