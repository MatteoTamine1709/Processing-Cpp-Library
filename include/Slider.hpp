#include "ProcessingCpp.hpp"


class Slider {
  double _min;
  double _max;
  double _value;
  double _inc;

public:
  Slider(double min, double max, double incr, double initialValue)
    : _min(min), _max(max), _inc(incr), _value(initialValue) {}
  ~Slider() {}


  void draw(int x, int y, int w, int h) {
    fill(0);
    stroke(0);
    rect(x, y, w, h);
    fill(255, 50);
    stroke(0);
    rect(x, y, w * (_value - _min) / (_max - _min), h);
    fill(255);
    textSize(12);
    text(std::to_string(_value), x + w / 2, y + h / 2);
  }

  

};