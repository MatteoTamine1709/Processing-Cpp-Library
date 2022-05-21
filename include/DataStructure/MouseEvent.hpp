#ifndef MOUSEEVENT_HPP
#define MOUSEEVENT_HPP

#include <SFML/Graphics.hpp>

typedef struct MouseEvent_s {
  double x, y;
  double delta;
  MouseEvent_s(const sf::Event::MouseWheelScrollEvent &event) {
    x = event.x;
    y = event.y;
    delta = event.delta;
  }

  double getCount() {
    return delta;
  }
} MouseEvent;


#endif