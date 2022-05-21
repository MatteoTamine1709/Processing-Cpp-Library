#ifndef COLOR_HPP
#define COLOR_HPP

#include <ostream>

#define RGB 0
#define HSB 1

typedef struct color_s {
  double r;
  double g;
  double b;
  double a;

  color_s();

  color_s(double v);
  color_s(double v, double a);

  color_s(double r, double g, double b);
  color_s(double r, double g, double b, double a);

  friend std::ostream& operator<<(std::ostream &out, const color_s& v);
} color;

#endif