#include "Engine.hpp"

void Engine::_textFont(const font &f) {
  m_textFont = f;
}

void Engine::_textFont(const font &f, const double &size) {
  m_textFont = f;
  Engine::_textSize(size);
}