#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>

typedef struct ptext_s {
  sf::Text text;
  double z;

  ptext_s() {}

  ptext_s(sf::Text text) : text(text) {
    this->z = 0;
  }

  ptext_s(sf::Text text, double z) : text(text), z(z) {}
  
  operator sf::Text() {
    return this->text;
  }
} ptext;

#endif