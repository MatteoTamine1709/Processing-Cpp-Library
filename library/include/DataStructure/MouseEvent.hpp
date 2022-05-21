#ifndef MOUSEEVENT_HPP
#define MOUSEEVENT_HPP

#include <SFML/Graphics.hpp>

typedef struct MouseEvent_s {
  double x, y;
  double delta;
  MouseEvent_s(const sf::Event::MouseWheelScrollEvent &event, double count) {
    x = event.x;
    y = event.y;
    delta = count;
  }

  double getCount() {
    return delta;
  }
} MouseEvent;


#endif