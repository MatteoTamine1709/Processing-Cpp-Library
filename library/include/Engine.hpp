#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "DataStructure/Color.hpp"
#include "DataStructure/PVector.hpp"
#include "DataStructure/MouseEvent.hpp"

void preload();
void setup();
void draw();
void onMousePressed();
void onMouseReleased();
void onMouseWheel(MouseEvent event);

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

typedef struct color_s color;

class Engine {
  public:
    static bool m_isRunning;
    static std::unique_ptr<sf::RenderWindow> m_window;
    static sf::Event m_event;
    static int m_exitCode;

    static int m_mouseX;
    static int m_mouseY;
    static int m_pmouseX;
    static int m_pmouseY;

    static color m_fillColor;
    static color m_strokeColor;
    static double m_strokeWeight;

    static int m_rectMode;
    static int m_ellipseMode;

    static int m_colorMode;
    static std::unordered_map<int, color> m_colorsMax;


    template <class Shape>
    static void addPoint(Shape& shape, sf::Vector2f point) {
      const std::size_t size = shape.getPointCount();

      shape.setPointCount(size + 1);
      shape.setPoint(size, point);
    }

    static sf::VertexArray getLine(const sf::Vector2f &point1, const sf::Vector2f &point2);
    static color HsvToRgb(color hsv);
    static color RgbToHsv(color rgb);

    static color map(color value, color min, color max, color min2, color max2);
    static double map(double value, double start1, double stop1, double start2, double stop2);



    static void _preload();
    static void _setup();
    static void _draw();

    /* STRUCTURE */
    static void _exit();

    /* COLOR */
    /* Setting */
    static void _background(const double &gray);
    static void _background(const double &v1, const double &v2, const double &v3);
    static void _background(const color &c);

    static void _noFill();

    static void _fill(const double &gray);
    static void _fill(const double &gray, const double &alpha);
    static void _fill(const double &v1, const double &v2, const double &v3);
    static void _fill(const double &v1, const double &v2, const double &v3, const double &a);
    static void _fill(const color &c);
    static void _fill(const color &c, const double &alpha);

    static void _noStroke();

    static void _colorMode(const int &mode);
    static void _colorMode(const int &mode, const double &max);
    static void _colorMode(const int &mode, const double &max1, const double &max2, const double &max3);
    static void _colorMode(const int &mode, const double &max1, const double &max2, const double &max3, const double &maxA);

    static void _stroke(const double &gray);
    static void _stroke(const double &gray, const double &a);
    static void _stroke(const double &v1, const double &v2, const double &v3);
    static void _stroke(const double &v1, const double &v2, const double &v3, const double &a);
    static void _stroke(const color &c);
    static void _stroke(const color &c, const double &a);

    /* CreatingAndReading */
    static double _alpha(const color &c);
    static double _blue(const color &c);
    static double _brightness(const color &c);
    static double _green(const color &c);
    static double _hue(const color &c);
    static double _red(const color &c);
    static double _saturation(const color &c);

    /* ENVIORNMENT */
    static void _size(const int &w, const int &h, const int &renderer = SFML);

    static int _width();
    static int _height();

    /* INPUT */
    /* Mouse */
    static int _mouseX();
    static int _mouseY();
    static int _pmouseX();
    static int _pmouseY();
    static int _mouseButton();
    static bool _mousePressed();

    /* OUTPUT */
    /* TextArea */
    static void _print();
    template<typename T>
    static void _print(T value);
    template<typename T, typename... Args>
    static void _print(T value, Args... args);

    static void _println();
    template<typename T>
    static void _println(T value);
    template<typename T, typename... Args>
    static void _println(T value, Args... args);

    /* MATH */
    /* Calculation */

    static double _abs(const double &value);

    static double _constrain(const double &value, const double &min, const double &max);

    static double _dist(const double &x1, const double &y1, const double &x2, const double &y2);
    static double _dist(const double &x1, const double &y1, const double &z1, const double &x2, const double &y2, const double &z2);

    static double _map(const double &value, const double &start1, const double &stop1, const double &start2, const double &stop2);

    static double _lerp(const double &start, const double &stop, const double &amt);

    static double _mag(const double &x, const double &y);
    static double _mag(const double &x, const double &y, const double &z);

    static double _max(const double &value1, const double &value2);
    static double _max(const double &value1, const double &value2, const double &value3);
    static double _max(const std::vector<double> &values);

    static double _min(const double &value1, const double &value2);
    static double _min(const double &value1, const double &value2, const double &value3);
    static double _min(const std::vector<double> &values);

    static double _norm(const double &value, const double &start, const double &stop);

    static double _sq(const double &value);

    /* Trigonometry */

    static double _degrees(const double &radians);
    static double _radians(const double &degrees);

    /* SHAPE */
    /* 2DPrimitives */
    static void _square(const double &x, const double &y, const double &w);
    static void _rect(const double &a, const double &b, const double &c, const double &d);
    static void _rect(const double &a, const double &b, const double &c, const double &d, const double &r);
    static void _rect(const double &a, const double &b, const double &c, const double &d, const double &tl, const double &tr, const double &br, const double &bl);
    static void _quad(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3, const double &x4, const double &y4);
    static void _triangle(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3);
    static void _point(const double &x, const double &y);
    static void _line(const double &x1, const double &y1, const double &x2, const double &y2);
    static void _ellipse(const double &x, const double &y, const double &w, const double &h);
    static void _circle(const double &x, const double &y, const double &r);
    static void _arc(const double &a, const double &b, const double &c, const double &d, const double &start, const double &stop, const int &mode = CENTER);

    /* Attributes */
    static void _strokeWeight(const double &weight);
    static void _rectMode(const int &mode);
    static void _ellipseMode(const int &mode);

};

#endif