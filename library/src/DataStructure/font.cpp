#include "DataStructure/Font.hpp"
#include "Engine.hpp"

font_s::font_s() {
  filename = Engine::m_defaultFontFilename;
  std::cout << "Loading font: " << filename << std::endl;
  if (!font.loadFromFile(Engine::m_defaultFontFilename))
    throw std::runtime_error("Could not load font: ./library/ressources/fonts/arial.ttf");
}

font_s::font_s(const std::string &filename) {
  this->filename = filename;
  std::cout << "Loading font: " << filename << std::endl;
  if (!font.loadFromFile(filename)) {
    std::cout << "Error loading font: " << filename << std::endl;
    std::cout << "Defaulting to: " << Engine::m_defaultFontFilename << std::endl;
    this->filename = Engine::m_defaultFontFilename;
    font.loadFromFile(Engine::m_defaultFontFilename);
  }
}