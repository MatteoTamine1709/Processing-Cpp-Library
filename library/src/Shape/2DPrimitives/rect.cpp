#include "Engine.hpp"

void Engine::_rect(const double &a, const double &b, const double &c, const double &d) {
  double posX = a;
  double posY = b;
  double width = c;
  double height = d;
  if (m_rectMode == CORNERS) {
    width -= a;
    height -= b;
  } else if (m_rectMode == RADIUS) {
    posX -= width;
    posY -= height;
    width *= 2;
    height *= 2;
  } else if (m_rectMode == CENTER) {
    posX -= width / 2;
    posY -= height / 2;
  }
  auto shape = sf::RectangleShape(sf::Vector2f(width, height));
  shape.setPosition(posX, posY);
  shape.setFillColor(m_fillColor);
  shape.setOutlineColor(m_strokeColor);
  shape.setOutlineThickness(m_strokeWeight);
  m_window->draw(shape);
}

void Engine::_rect(const double &a, const double &b, const double &c, const double &d, const double &r) {
  double posX = a;
  double posY = b;
  double width = c;
  double height = d;
  if (m_rectMode == CORNERS) {
    width -= a;
    height -= b;
  } else if (m_rectMode == RADIUS) {
    posX -= width;
    posY -= height;
    width *= 2;
    height *= 2;
  } else if (m_rectMode == CENTER) {
    posX -= width / 2;
    posY -= height / 2;
  }
  sf::ConvexShape shape;
  shape.setFillColor(m_fillColor);
  shape.setOutlineColor(m_strokeColor);
  shape.setOutlineThickness(m_strokeWeight);

  sf::Vector2f currentCorner(width - r, height - r);
  sf::Vector2f radialVec(r, 0.f);

  const std::size_t nbSegmentsPerCorner = 20;
  const double difference = 90.f / nbSegmentsPerCorner;

  // right lower rounded corner
  for (; radialVec.y < 90.f; radialVec.y += difference)
    addPoint(shape, currentCorner + sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f)));

  // left lower rounded corner
  currentCorner.x = r;
  for (radialVec.y = 90.f; radialVec.y < 180.f; radialVec.y += difference)
    addPoint(shape, currentCorner + sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f)));

  // left upper rounded corner
  currentCorner.y = r;
  for (radialVec.y = 180.f; radialVec.y < 270.f; radialVec.y += difference)
    addPoint(shape, currentCorner + sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f)));

  // right upper rounded corner
  currentCorner.x = width - r;
  for (radialVec.y = 270.f; radialVec.y < 360.f; radialVec.y += difference)
    addPoint(shape, currentCorner + sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f)));

  shape.setPosition(posX, posY);
  m_window->draw(shape);
}

void Engine::_rect(const double &a, const double &b, const double &c, const double &d, const double &tl, const double &tr, const double &br, const double &bl) {
  double posX = a;
  double posY = b;
  double width = c;
  double height = d;
  if (m_rectMode == CORNERS) {
    width -= a;
    height -= b;
  } else if (m_rectMode == RADIUS) {
    posX -= width;
    posY -= height;
    width *= 2;
    height *= 2;
  } else if (m_rectMode == CENTER) {
    posX -= width / 2;
    posY -= height / 2;
  }
  sf::ConvexShape shape;
  shape.setFillColor(m_fillColor);
  shape.setOutlineColor(m_strokeColor);
  shape.setOutlineThickness(m_strokeWeight);

  const std::size_t nbSegmentsPerCorner = 20;
  const double difference = 90.f / nbSegmentsPerCorner;

  sf::Vector2f currentCorner(width - br, height - br);
  sf::Vector2f radialVec(br, 0.f);
  for (; radialVec.y < 90.f; radialVec.y += difference) {
    auto val = currentCorner +
      sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f));
    addPoint(shape, val);
  }

  radialVec.x = bl;
  currentCorner.x = bl;
  currentCorner.y = height - bl;
  for (radialVec.y = 90.f; radialVec.y < 180.f; radialVec.y += difference) {
    auto val = currentCorner +
      sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f));
    addPoint(shape, val);
  }


  radialVec.x = tl;
  currentCorner.x = tl;
  currentCorner.y = tl;
  for (radialVec.y = 180.f; radialVec.y < 270.f; radialVec.y += difference) {
    auto val = currentCorner +
      sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f));
    addPoint(shape, val);
  }

  radialVec.x = tr;
  currentCorner.x = width - tr;
  currentCorner.y = tr;
  for (radialVec.y = 270.f; radialVec.y < 360.f; radialVec.y += difference) {
    auto val = currentCorner +
      sf::Vector2f(radialVec.x * cos(radialVec.y * M_PI / 180.f), radialVec.x * sin(radialVec.y * M_PI / 180.f));
    addPoint(shape, val);
  }
  shape.setPosition(posX, posY);
  m_window->draw(shape);
}