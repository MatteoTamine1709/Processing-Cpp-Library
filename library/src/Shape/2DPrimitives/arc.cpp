#include "Engine.hpp"

void Engine::_arc(const double &a, const double &b, const double &c, const double &d, const double &start, const double &stop, const int &mode) {
  double radiusX = c / 2;
  double radiusY = d / 2;
  if (m_fillColor.a != 0) {
    sf::VertexArray fillArc;
    for (double i = start; i < stop; i += 0.1f) {
      double angle = i;
      if (mode == CENTER || mode == PIE)
        fillArc.append(sf::Vertex(sf::Vector2f(a, b), sf::Color(m_fillColor.r, m_fillColor.g, m_fillColor.b, m_fillColor.a)));
      double xPos = a + cos(angle) * radiusX;
      double yPos = b + sin(angle) * radiusY;
      fillArc.append(sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color(m_fillColor.r, m_fillColor.g, m_fillColor.b, m_fillColor.a)));
      angle += 0.1f;
      angle = std::min(angle, stop);
      xPos = a + cos(angle) * radiusX;
      yPos = b + sin(angle) * radiusY;
      fillArc.append(sf::Vertex(sf::Vector2f(xPos, yPos), sf::Color(m_fillColor.r, m_fillColor.g, m_fillColor.b, m_fillColor.a)));
    }
    if (mode == CENTER || mode == PIE)
      fillArc.setPrimitiveType(sf::Triangles);
    else if (mode == OPEN || mode == CHORD)
      fillArc.setPrimitiveType(sf::TriangleFan);
    m_window->draw(fillArc);
  }

  sf::VertexArray arc(sf::TriangleStrip);
  double prevX = a + cos(start) * radiusX;
  double prevY = b + sin(start) * radiusY;
  for (double i = start + 0.1f; i < stop; i += 0.1f) {
    double angle = i;
    double xPos = a + cos(angle) * radiusX;
    double yPos = b + sin(angle) * radiusY;
    auto line = getLine(sf::Vector2f(prevX, prevY), sf::Vector2f(xPos, yPos));
    arc.append(line[0]);
    arc.append(line[1]);
    arc.append(line[3]);
    arc.append(line[2]);
    prevX = xPos;
    prevY = yPos;
  }
  double xPos = a + cos(stop) * radiusX;
  double yPos = b + sin(stop) * radiusY;
  auto line = getLine(sf::Vector2f(prevX, prevY), sf::Vector2f(xPos, yPos));
  arc.append(line[0]);
  arc.append(line[1]);
  arc.append(line[3]);
  arc.append(line[2]);
  prevX = xPos;
  prevY = yPos;
  if (mode == PIE) {
    auto line = getLine(sf::Vector2f(prevX, prevY), sf::Vector2f(a, b));
    arc.append(line[0]);
    arc.append(line[1]);
    arc.append(line[3]);
    arc.append(line[2]);
    prevX = a;
    prevY = b;
  }
  if (mode == CHORD || mode == PIE) {
    xPos = a + cos(start) * radiusX;
    yPos = b + sin(start) * radiusY;
    auto line = getLine(sf::Vector2f(prevX, prevY), sf::Vector2f(xPos, yPos));
    arc.append(line[0]);
    arc.append(line[1]);
    arc.append(line[3]);
    arc.append(line[2]);
  }


  m_window->draw(arc);
}