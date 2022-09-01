#include "Engine.hpp"

void Engine::_text(const char &c, const double &x, const double &y) {
  Engine::_text(std::string(1, c), x, y);
}

void Engine::_text(const std::string &text, const int &start, const int &stop, const double &x, const double &y) {
  Engine::_text(text.substr(start, stop - start), x, y);
}

void Engine::_text(const std::string &text, const double &x, const double &y) {
  sf::Text t(text, *m_textFont, m_textSize);
  t.setFillColor(m_fillColor);
  t.setPosition(x, y);
  m_window->draw(t);
}

void Engine::_text(const std::string &text, const double &x, const double &y, const double &w, const double &h) {
  sf::Text t(text, *m_textFont, m_textSize);
  t.setFillColor(m_fillColor);
  t.setPosition(x, y);
  t.setScale(w / t.getLocalBounds().width, h / t.getLocalBounds().height);
  m_window->draw(t);
}

void Engine::_text(const double &num, const double &x, const double &y) {
  Engine::_text(std::to_string(num), x, y);
}