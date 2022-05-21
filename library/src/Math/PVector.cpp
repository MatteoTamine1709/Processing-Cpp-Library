#include "Engine.hpp"

PVector_s::PVector_s() {
  x = 0;
  y = 0;
  z = 0;
}
PVector_s::PVector_s(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

PVector &PVector::set(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
  return *this;
}
PVector &PVector::set(PVector v) {
  this->x = v.x;
  this->y = v.y;
  this->z = v.z;
  return *this;
}
PVector &PVector::set(std::array<double, 2> source) {
  this->x = source[0];
  this->y = source[1];
  this->z = 0;
  return *this;
}
PVector &PVector::set(std::array<double, 3> source) {
  this->x = source[0];
  this->y = source[1];
  this->z = source[2];
  return *this;
}
PVector &PVector::set(std::initializer_list<double> source) {
  if (source.size() == 2) {
    this->x = *source.begin();
    this->y = *(source.begin() + 1);
    this->z = 0;
  } else if (source.size() == 3) {
    this->x = *source.begin();
    this->y = *(source.begin() + 1);
    this->z = *(source.begin() + 2);
  }
  return *this;
}

PVector PVector::random2D() {
  return PVector((double)rand() / ((double)RAND_MAX / 2.f) - 1, (double)rand() / ((double)RAND_MAX / 2.f) - 1);
}
PVector &PVector::random2D(PVector &target) {
  return target.set((double)rand() / ((double)RAND_MAX / 2.f) - 1, (double)rand() / ((double)RAND_MAX / 2.f) - 1, target.z);
}

PVector PVector::random3D() {
  return PVector((double)rand() / ((double)RAND_MAX / 2.f) - 1, (double)rand() / ((double)RAND_MAX / 2.f) - 1, (double)rand() / ((double)RAND_MAX / 2.f) - 1);
}
PVector PVector::random3D(PVector &target) {
  return target.set((double)rand() / ((double)RAND_MAX / 2.f) - 1, (double)rand() / ((double)RAND_MAX / 2.f) - 1, (double)rand() / ((double)RAND_MAX / 2.f) - 1);
}

PVector PVector::fromAngle(double angle) {
  return PVector(cos(angle), sin(angle));
}
PVector &PVector::fromAngle(double angle, PVector &target) {
  return target.set(cos(angle), sin(angle), target.z);
}

PVector PVector::copy() {
  return PVector(x, y, z);
}

double PVector::mag() {
  return sqrt(x * x + y * y + z * z);
}
double PVector::magSq() {
  return (x * x + y * y + z * z);
}

PVector &PVector::add(PVector v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}
PVector &PVector::add(double x, double y, double z) {
  this->x += x;
  this->y += y;
  this->z += z;
  return *this;
}
PVector PVector::add(PVector v1, PVector v2) {
  return PVector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
PVector &PVector::add(PVector v1, PVector v2, PVector &target) {
  return target.set(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

PVector &PVector::sub(PVector v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}
PVector &PVector::sub(double x, double y, double z) {
  this->x -= x;
  this->y -= y;
  this->z -= z;
  return *this;
}
PVector PVector::sub(PVector v1, PVector v2) {
  return PVector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
PVector &PVector::sub(PVector v1, PVector v2, PVector &target) {
  return target.set(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

PVector &PVector::mult(double n) {
  x *= n;
  y *= n;
  z *= n;
  return *this;
}
PVector PVector::mult(PVector v, double n) {
  return PVector(v.x * n, v.y * n, v.z * n);
}
PVector &PVector::mult(PVector v, double n, PVector &target) {
  return target.set(v.x * n, v.y * n, v.z * n);
}

PVector &PVector::div(double n) {
  x /= n;
  y /= n;
  z /= n;
  return *this;
}
PVector PVector::div(PVector v, double n) {
  return PVector(v.x / n, v.y / n, v.z / n);
}
PVector &PVector::div(PVector v, double n, PVector &target) {
  return target.set(v.x / n, v.y / n, v.z / n);
}

double PVector::dist(PVector v) {
  return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z));
}
double PVector::dist(PVector v1, PVector v2) {
  return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z));
}

double PVector::dot(PVector v) {
  return (x * v.x + y * v.y + z * v.z);
}
double PVector::dot(double x, double y, double z) {
  return (this->x * x + this->y * y + this->z * z);
}
double PVector::dot(PVector v1, PVector v2) {
  return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

PVector &PVector::cross(PVector v) {
  double _x = y * v.z - z * v.y;
  double _y = z * v.x - x * v.z;
  double _z = x * v.y - y * v.x;
  x = _x;
  y = _y;
  z = _z;
  return *this;
}
PVector PVector::cross(PVector v, PVector &target) {
  return target.set(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
PVector PVector::cross(PVector v1, PVector v2) {
  return PVector(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}
PVector &PVector::cross(PVector v1, PVector v2, PVector &target) {
  return target.set(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

PVector &PVector::normalize() {
  double m = mag();
  if (m > 0) {
    div(m);
    return *this;
  }
  return set(0, 0, 0);
}
PVector &PVector::normalize(PVector &target) {
  target = copy();
  double m = target.mag();
  if (m > 0)
    return target.div(m);
  return target.set(0, 0, 0);
}

PVector &PVector::limit(double max) {
  if (magSq() > max * max)
    return normalize().mult(max);
  return *this;
}
PVector &PVector::limit(PVector &target, double max) {
  if (target.magSq() > max * max)
    return target.normalize().mult(max);
  return target;
}

PVector &PVector::setMag(double len) {
  return normalize().mult(len);
}
PVector &PVector::setMag(PVector &target, double len) {
  return target.normalize().mult(len);
}

double PVector::heading() {
  return atan2(y, x);
}

PVector &PVector::rotate(double angle) {
  double cs = cos(angle);
  double sn = sin(angle);

  double _x = x * cs - y * sn;
  double _y = x * sn + y * cs;

  return set(_x, _y, z);
}
PVector &PVector::rotate(PVector &target, double angle) {
  double cs = cos(angle);
  double sn = sin(angle);

  double _x = target.x * cs - target.y * sn;
  double _y = target.x * sn + target.y * cs;

  return target.set(_x, _y, target.z);
}

PVector &PVector::lerp(PVector v, double amt) {
  return add(v.sub(*this).mult(amt));
}
PVector &PVector::lerp(double x, double y, double z, double amt) {
  return add(PVector(x, y, z).sub(*this).mult(amt));
}
PVector PVector::lerp(PVector v1, PVector v2, double amt) {
  return PVector::add(v2, (PVector::mult(PVector::sub(v1, v2), amt)));
}
PVector &PVector::lerp(PVector v1, PVector v2, double amt, PVector &target) {
  return target.set(PVector::add(v2, (PVector::mult(PVector::sub(v1, v2), amt))));
}

double PVector::angleBetween(PVector v) {
  return acos(dot(v) / (mag() * v.mag()));
}
double PVector::angleBetween(PVector v1, PVector v2) {
  return acos(PVector::dot(v1, v2) / (v1.mag() * v2.mag()));
}

std::array<double, 3> PVector::array() {
  return {x, y, z};
}

std::ostream& operator<<(std::ostream& os, const PVector& v) {
  os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
  return os;
}