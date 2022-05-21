#ifndef PROCESSINGCPP_HPP
#define PROCESSINGCPP_HPP

#include <cmath>
#include <array>
#include <vector>
#include <iostream>

#include "DataStructure/Color.hpp"
#include "DataStructure/PVector.hpp"
#include "DataStructure/MouseEvent.hpp"

#define PI M_PI
#define HALF_PI (M_PI / 2)
#define QUARTER_PI (M_PI / 4)
#define TWO_PI (M_PI * 2)

#define SFML 0

#define CENTER 0
#define OPEN 1
#define CHORD 2
#define PIE 3

#define CORNER 4
#define CORNERS 5
#define RADIUS 6

#define NONE 7
#define LEFT 8
#define RIGHT 9

class Engine {
  public:
    static void _preload();
    static void _setup();
    static void _draw();
};

class ProcessingCpp {
public:
  static void run() {
    Engine::_preload();
    Engine::_setup();
    Engine::_draw();
  }
};

/* STRUCURE */
void exit();


/* COLOR */
/* Setting */
void background(const double &gray);
void background(const double &v1, const double &v2, const double &v3);
void background(const color &c);

void noFill();

void fill(const double &gray);
void fill(const double &gray, const double &alpha);
void fill(const double &v1, const double &v2, const double &v3);
void fill(const double &v1, const double &v2, const double &v3, const double &a);
void fill(const color &c);
void fill(const color &c, const double &alpha);

void noStroke();

void colorMode(const int &mode);
void colorMode(const int &mode, const double &max);
void colorMode(const int &mode, const double &max1, const double &max2, const double &max3);
void colorMode(const int &mode, const double &max1, const double &max2, const double &max3, const double &maxA);

void stroke(const double &gray);
void stroke(const double &gray, const double &a);
void stroke(const double &v1, const double &v2, const double &v3);
void stroke(const double &v1, const double &v2, const double &v3, const double &a);
void stroke(const color &c);
void stroke(const color &c, const double &a);

/* CreatingAndReading */
double alpha(const color &c);
double blue(const color &c);
double brightness(const color &c);
double green(const color &c);
double hue(const color &c);
double red(const color &c);
double staturation(const color &c);

/* ENVIRONMENT */
void size(const int &w, const int &h);
void size(const int &w, const int &h, const int &renderer);

int width();
int height();

/* INPUT */
/* Mouse */
int mouseX();
int mouseY();
int pmouseX();
int pmouseY();
int mouseButton();
bool mousePressed();

/* OUTPUT */
/* TextArea */
void print();
template<typename T>
void print(T value) {
  std::cout << value;
}
template<typename T, typename... Args>
void print(T value, Args... args) {
  std::cout << value;
  print(args...);
}

void println();
template<typename T>
void println(T value) {
  std::cout << value << std::endl;
}
template<typename T, typename... Args>
void println(T value, Args... args) {
  std::cout << value;
  println(args...);
}

/* MATH */
/* Calculation */
double abs(const double &value);

double constrain(const double &value, const double &min, const double &max);

double dist(const double &x1, const double &y1, const double &x2, const double &y2);
double dist(const double &x1, const double &y1, const double &z1, const double &x2, const double &y2, const double &z2);

double map(const double &value, const double &start1, const double &stop1, const double &start2, const double &stop2);

double lerp(const double &start, const double &stop, const double &amt);

double mag(const double &x, const double &y);
double mag(const double &x, const double &y, const double &z);

double max(const double &value1, const double &value2);
double max(const double &value1, const double &value2, const double &value3);
double max(const std::vector<double> &values);

double min(const double &value1, const double &value2);
double min(const double &value1, const double &value2, const double &value3);
double min(const std::vector<double> &values);

double norm(const double &value, const double &start, const double &stop);

double sq(const double &value);

/* Trigonometry */

double degrees(const double &radians);
double radians(const double &degrees);

/* SHAPE */
/* 2DPrimitives */
void square(const double &x, const double &y, const double &w);

void rect(const double &a, const double &b, const double &c, const double &d);
void rect(const double &a, const double &b, const double &c, const double &d, const double &r);
void rect(const double &a, const double &b, const double &c, const double &d, const double &tl, const double &tr, const double &br, const double &bl);

void quad(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3, const double &x4, const double &y4);

void triangle(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3);

void point(const double &x, const double &y);

void line(const double &x1, const double &y1, const double &x2, const double &y2);

void ellipse(const double &x, const double &y, const double &w, const double &h);

void circle(const double &x, const double &y, const double &r);

void arc(const double &a, const double &b, const double &c, const double &d, const double &start, const double &stop);
void arc(const double &a, const double &b, const double &c, const double &d, const double &start, const double &stop, const int &mode);

/* Attributes */
void strokeWeight(const double &w);

void rectMode(const int &mode);

void ellipseMode(const int &mode);

#endif