#ifndef PVEVECTOR_HPP
#define PVEVECTOR_HPP

typedef struct PVector_s {
  double x, y, z;

  PVector_s();
  PVector_s(double x, double y, double z = 0);

  PVector_s &set(double x, double y, double z = 0);
  PVector_s &set(PVector_s v);
  PVector_s &set(std::array<double, 2> source);
  PVector_s &set(std::array<double, 3> source);
  PVector_s &set(std::initializer_list<double> source);

  static PVector_s random2D();
  static PVector_s &random2D(PVector_s &target);

  static PVector_s random3D();
  static PVector_s random3D(PVector_s &target);

  static PVector_s fromAngle(double angle);
  static PVector_s &fromAngle(double angle, PVector_s &target);

  PVector_s copy();

  double mag();
  double magSq();

  PVector_s &add(PVector_s v);
  PVector_s &add(double x, double y, double z = 0);
  static PVector_s add(PVector_s v1, PVector_s v2);
  static PVector_s &add(PVector_s v1, PVector_s v2, PVector_s &target);

  PVector_s &sub(PVector_s v);
  PVector_s &sub(double x, double y, double z = 0);
  static PVector_s sub(PVector_s v1, PVector_s v2);
  static PVector_s &sub(PVector_s v1, PVector_s v2, PVector_s &target);

  PVector_s &mult(double n);
  static PVector_s mult(PVector_s v, double n);
  static PVector_s &mult(PVector_s v, double n, PVector_s &target);

  PVector_s &div(double n);
  static PVector_s div(PVector_s v, double n);
  static PVector_s &div(PVector_s v, double n, PVector_s &target);

  double dist(PVector_s v);
  static double dist(PVector_s v1, PVector_s v2);

  double dot(PVector_s v);
  double dot(double x, double y, double z = 0);
  static double dot(PVector_s v1, PVector_s v2);

  PVector_s &cross(PVector_s v);
  PVector_s cross(PVector_s v, PVector_s &target);
  static PVector_s cross(PVector_s v1, PVector_s v2);
  static PVector_s &cross(PVector_s v1, PVector_s v2, PVector_s &target);

  PVector_s &normalize();
  PVector_s &normalize(PVector_s& target);

  PVector_s &limit(double max);
  static PVector_s &limit(PVector_s &target, double max);

  PVector_s &setMag(double len);
  static PVector_s &setMag(PVector_s &target, double len);

  double heading();

  PVector_s &rotate(double theta);
  static PVector_s &rotate(PVector_s &target, double theta);

  PVector_s &lerp(PVector_s v, double amt);
  PVector_s &lerp(double x, double y, double z, double amt);
  static PVector_s lerp(PVector_s v1, PVector_s v2, double amt);
  static PVector_s &lerp(PVector_s v1, PVector_s v2, double amt, PVector_s &target);

  double angleBetween(PVector_s v);
  static double angleBetween(PVector_s v1, PVector_s v2);

  std::array<double, 3> array();

  friend std::ostream& operator<<(std::ostream &out, const PVector_s& v);
} PVector;

#endif