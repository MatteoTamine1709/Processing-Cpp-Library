#include "Engine.hpp"

bool Engine::_mousePressed() {
  return sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Middle);
}