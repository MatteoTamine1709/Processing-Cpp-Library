#include "Engine.hpp"

bool Engine::m_isRunning = false;
std::unique_ptr<sf::RenderWindow> Engine::m_window = nullptr;
sf::Event Engine::m_event;

int Engine::m_colorMode = RGB;
std::unordered_map<int, color> Engine::m_colorsMax = {};

color Engine::m_fillColor;
color Engine::m_strokeColor;
double Engine::m_strokeWeight = 1.0f;

int Engine::m_mouseX;
int Engine::m_mouseY;
int Engine::m_pmouseX;
int Engine::m_pmouseY;

int Engine::m_rectMode = CORNER;
int Engine::m_ellipseMode = CENTER;

std::string Engine::m_defaultFontFilename = "./library/ressources/fonts/arial.ttf";
font Engine::m_textFont;
double Engine::m_textSize = 24.0f;

color Engine::HsvToRgb(color hsv) {
  hsv.g /= 100.f;
  hsv.b /= 100.f;

  auto k = [&](double n){ return fmod(n + hsv.r / 60.f, 6.f); };
  auto f = [&](double n){ return hsv.b * (1.f - hsv.g * std::max((double)0, std::min(std::min(k(n), 4 - k(n)), (double)1))); };
  return color(255 * f(5), 255 * f(3), 255 * f(1));
}

color Engine::RgbToHsv(color rgb) {
  rgb.r /= 255;
  rgb.g /= 255;
  rgb.b /= 255;
  auto v = std::max(std::max(rgb.r, rgb.g), rgb.b);
  auto n = v - std::min(std::min(rgb.r, rgb.g), rgb.b);
  auto h = n == 0 ? 0 : n && v == rgb.r ? (rgb.g - rgb.b) / n : v == rgb.g ? 2 + (rgb.b - rgb.r) / n : 4 + (rgb.r - rgb.g) / n;
  return color(60 * (h < 0 ? h + 6 : h), v == 0 ? 0 : (n / v) * 100, v * 100);
}

color Engine::map(color c, color min1, color max1, color min2, color max2) {
  return color(
    map(c.r, min1.r, max1.r, min2.r, max2.r),
    map(c.g, min1.g, max1.g, min2.g, max2.g),
    map(c.b, min1.b, max1.b, min2.b, max2.b),
    map(c.a, min1.a, max1.a, min2.a, max2.a)
  );
}

double Engine::map(double value, double start1, double stop1, double start2, double stop2) {
  return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1 == 0 ? 1 : stop1 - start1));
}

sf::VertexArray Engine::getLine(const sf::Vector2f &point1, const sf::Vector2f &point2) {
  sf::VertexArray vertices(sf::Quads, 4);
  sf::Vector2f direction = point2 - point1;
  sf::Vector2f unitDirection = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
  sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

  sf::Vector2f offset = (float)(m_strokeWeight / 2.0) * unitPerpendicular;

  vertices[0] = sf::Vertex(point1 + offset, sf::Color(m_strokeColor.r, m_strokeColor.g, m_strokeColor.b, m_strokeColor.a));
  vertices[1] = sf::Vertex(point2 + offset, sf::Color(m_strokeColor.r, m_strokeColor.g, m_strokeColor.b, m_strokeColor.a));
  vertices[2] = sf::Vertex(point2 - offset, sf::Color(m_strokeColor.r, m_strokeColor.g, m_strokeColor.b, m_strokeColor.a));
  vertices[3] = sf::Vertex(point1 - offset, sf::Color(m_strokeColor.r, m_strokeColor.g, m_strokeColor.b, m_strokeColor.a));
  return vertices;
}

void Engine::_preload() {
  std::cout << "Engine::preload()" << std::endl;
  m_colorsMax[RGB].r = 255;
  m_colorsMax[RGB].g = 255;
  m_colorsMax[RGB].b = 255;
  m_colorsMax[RGB].a = 255;

  m_colorsMax[HSB].r = 360;
  m_colorsMax[HSB].g = 100;
  m_colorsMax[HSB].b = 100;
  m_colorsMax[HSB].a = 255;

  m_fillColor = color(255);
  m_strokeColor = color(0);

  preload();
}

void Engine::_setup() {
  std::cout << "Engine::setup()" << std::endl;
  srand(time(NULL));
  setup();
  m_isRunning = true;
}

void Engine::_draw() {
  std::cout << "Engine::draw()" << std::endl;
  m_window->setFramerateLimit(60);
  while (m_isRunning) {
    float mouseWheelCount = 0;
    while (m_window->pollEvent(Engine::m_event)) {
      if (Engine::m_event.type == sf::Event::Closed) {
        m_isRunning = false;
        return;
      }
      if (Engine::m_event.type == sf::Event::MouseButtonPressed) {
        onMousePressed();
      }
      if (Engine::m_event.type == sf::Event::MouseButtonReleased) {
        onMouseReleased();
      }
      if (Engine::m_event.type == sf::Event::MouseWheelScrolled) {
        mouseWheelCount += Engine::m_event.mouseWheelScroll.delta;
      }
    }
    if (mouseWheelCount)
      onMouseWheel(MouseEvent(Engine::m_event.mouseWheelScroll, mouseWheelCount));
    m_pmouseX = m_mouseX;
    m_pmouseY = m_mouseY;
    m_mouseX = sf::Mouse::getPosition(*m_window).x;
    m_mouseY = sf::Mouse::getPosition(*m_window).y;
    draw();
    m_window->display();
  }
}

/* STRUCTURE */
void exit() {
  Engine::_exit();
}

/* COLOR */
/* Setting */
void background(const double &gray) {
  Engine::_background(gray);
}
void background(const double &v1, const double &v2, const double &v3) {
  Engine::_background(v1, v2, v3);
}
void background(const color &c) {
  Engine::_background(c);
}

void noFill() {
  Engine::_noFill();
}

void fill(const double &gray) {
  Engine::_fill(gray);
}
void fill(const double &gray, const double &alpha) {
  Engine::_fill(gray, alpha);
}
void fill(const double &v1, const double &v2, const double &v3) {
  Engine::_fill(v1, v2, v3);
}
void fill(const double &v1, const double &v2, const double &v3, const double &a) {
  Engine::_fill(v1, v2, v3, a);
}
void fill(const color &c) {
  Engine::_fill(c);
}
void fill(const color &c, const double &alpha) {
  Engine::_fill(c, alpha);
}

void noStroke() {
  Engine::_noStroke();
}

void colorMode(const int &mode) {
  Engine::_colorMode(mode);
}
void colorMode(const int &mode, const double &max) {
  Engine::_colorMode(mode, max);
}
void colorMode(const int &mode, const double &max1, const double &max2, const double &max3) {
  Engine::_colorMode(mode, max1, max2, max3);
}
void colorMode(const int &mode, const double &max1, const double &max2, const double &max3, const double &maxA) {
  Engine::_colorMode(mode, max1, max2, max3, maxA);
}

void stroke(const double &gray) {
  Engine::_stroke(gray);
}
void stroke(const double &gray, const double &a) {
  Engine::_stroke(gray, a);
}
void stroke(const double &v1, const double &v2, const double &v3) {
  Engine::_stroke(v1, v2, v3);
}
void stroke(const double &v1, const double &v2, const double &v3, const double &a) {
  Engine::_stroke(v1, v2, v3, a);
}
void stroke(const color &c) {
  Engine::_stroke(c);
}
void stroke(const color &c, const double &a) {
  Engine::_stroke(c, a);
}

/* CreatingAndReading */
double alpha(const color &c) {
  return Engine::_alpha(c);
}
double blue(const color &c) {
  return Engine::_blue(c);
}
double brightness(const color &c) {
  return Engine::_brightness(c);
}
double green(const color &c) {
  return Engine::_hue(c);
}
double hue(const color &c) {
  return Engine::_hue(c);
}
double red(const color &c) {
  return Engine::_red(c);
}
double saturation(const color &c) {
  return Engine::_saturation(c);
}


/* ENVIRONMENT */
void size(const int &w, const int &h) {
  Engine::_size(w, h);
}
void size(const int &w, const int &h, const int &renderer) {
  Engine::_size(w, h, renderer);
}

int width() {
  return Engine::_width();
}
int height() {
  return Engine::_height();
}

/* INPUT */
/* Mouse */
int mouseX() {
  return Engine::_mouseX();
}
int mouseY() {
  return Engine::_mouseY();
}
int pmouseX() {
  return Engine::_pmouseX();
}
int pmouseY() {
  return Engine::_pmouseY();
}
int mouseButton() {
  return Engine::_mouseButton();
}
bool mousePressed() {
  return Engine::_mousePressed();
}

/* OUTPUT */
/* TextArea */
void print() {
  Engine::_print();
}
template<typename T>
void print(T value) {
  Engine::_print(value);
}
template<typename T, typename... Args>
void print(T value, Args... args) {
  Engine::_print(value, args...);
}

void println() {
  Engine::_println();
}
template<typename T>
void println(T value) {
  Engine::_println(value);
}
template<typename T, typename... Args>
void println(T value, Args... args) {
  Engine::_println(value, args...);
}

/* MATH */
/* Calculation */
double abs(const double &value) {
  return Engine::_abs(value);
}

double constrain(const double &value, const double &min, const double &max) {
  return Engine::_constrain(value, min, max);
}

double dist(const double &x1, const double &y1, const double &x2, const double &y2) {
  return Engine::_dist(x1, y1, x2, y2);
}
double dist(const double &x1, const double &y1, const double &z1, const double &x2, const double &y2, const double &z2) {
  return Engine::_dist(x1, y1, z1, x2, y2, z2);
}

double map(const double &value, const double &start1, const double &stop1, const double &start2, const double &stop2) {
  return Engine::_map(value, start1, stop1, start2, stop2);
}

double lerp(const double &start, const double &stop, const double &amt) {
  return Engine::_lerp(start, stop, amt);
}

double mag(const double &x, const double &y) {
  return Engine::_mag(x, y);
}
double mag(const double &x, const double &y, const double &z) {
  return Engine::_mag(x, y, z);
}

double max(const double &value1, const double &value2) {
  return Engine::_max(value1, value2);
}
double max(const double &value1, const double &value2, const double &value3) {
  return Engine::_max(value1, value2, value3);
}
double max(const std::vector<double> &values) {
  return Engine::_max(values);
}

double min(const double &value1, const double &value2) {
  return Engine::_min(value1, value2);
}
double min(const double &value1, const double &value2, const double &value3) {
  return Engine::_min(value1, value2, value3);
}
double min(const std::vector<double> &values) {
  return Engine::_min(values);
}

double norm(const double &value, const double &start, const double &stop) {
  return Engine::_norm(value, start, stop);
}

double sq(const double &value) {
  return Engine::_sq(value);
}

/* Trigonometry */
double degrees(const double &radians) {
  return Engine::_degrees(radians);
}
double radians(const double &degrees) {
  return Engine::_radians(degrees);
}

/* SHAPE */
/* 2DPrimitives */
void square(const double &x, const double &y, const double &w) {
  Engine::_square(x, y, w);
}

void rect(const double &a, const double &b, const double &c, const double &d) {
  Engine::_rect(a, b, c, d);
}
void rect(const double &a, const double &b, const double &c, const double &d, const double &r) {
  Engine::_rect(a, b, c, d, r);
}
void rect(const double &a, const double &b, const double &c, const double &d, const double &tl, const double &tr, const double &br, const double &bl) {
  Engine::_rect(a, b, c, d, tl, tr, br, bl);
}

void quad(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3, const double &x4, const double &y4) {
  Engine::_quad(x1, y1, x2, y2, x3, y3, x4, y4);
}

void triangle(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3) {
  Engine::_triangle(x1, y1, x2, y2, x3, y3);
}

void point(const double &x, const double &y) {
  Engine::_point(x, y);
}

void line(const double &x1, const double &y1, const double &x2, const double &y2) {
  Engine::_line(x1, y1, x2, y2);
}

void ellipse(const double &x, const double &y, const double &w, const double &h) {
  Engine::_ellipse(x, y, w, h);
}

void circle(const double &x, const double &y, const double &r) {
  Engine::_circle(x, y, r);
}

void arc(const double &x, const double &y, const double &w, const double &h, const double &start, const double &stop) {
  Engine::_arc(x, y, w, h, start, stop);
}
void arc(const double &x, const double &y, const double &w, const double &h, const double &start, const double &stop, const int &mode) {
  Engine::_arc(x, y, w, h, start, stop, mode);
}

/* Attributes */
void strokeWeight(const double &w) {
  Engine::_strokeWeight(w);
}

void rectMode(const int &mode) {
  Engine::_rectMode(mode);
}

void ellipseMode(const int &mode) {
  Engine::_ellipseMode(mode);
}

/* Typography */
font loadFont(const std::string &filename) {
  return Engine::_loadFont(filename);
}

void textFont(const font &f) {
  Engine::_textFont(f);
}

void textFont(const font &f, const double &size) {
  Engine::_textFont(f, size);
}

void text(const char &c, const double &x, const double &y) {
  Engine::_text(c, x, y);
}

void text(const std::string &text, const int &start, const int &stop, const double &x, const double &y) {
  Engine::_text(text, start, stop, x, y);
}

void text(const std::string &text, const double &x, const double &y) {
  Engine::_text(text, x, y);
}

void text(const std::string &text, const double &x, const double &y, const double &w, const double &h) {
  Engine::_text(text, x, y, w, h);
}

void text(const double &num, const double &x, const double &y) {
  Engine::_text(num, x, y);
}

void textSize(const double &size) {
  Engine::_textSize(size);
}