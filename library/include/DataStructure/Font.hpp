#ifndef FONT_HPP
#define FONT_HPP

#include <SFML/Graphics.hpp>

typedef struct font_s {
  std::string filename;
  sf::Font font;

  font_s();
  font_s(const std::string &filename);
  
  operator sf::Font *() {
    return &this->font;
  }
} font;

#endif