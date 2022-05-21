#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <unordered_map>
#include <string>
#include "ProcessingCpp.hpp"

typedef struct VS_s {
  double value;
  double speed;
} VS;

typedef struct Status_s {
  VS distance;
  VS angle;
  double massOfTheSunKg;
  color c;
  double scaleFactor;
} Status;

typedef struct Constants_s {
  double numberOfCalculationsPerFrame = 1000;
  double deltaT = 3600 * 24 / numberOfCalculationsPerFrame;
  double gravitationalConstant = 6.67408 * pow(10, -11);
  double massOfTheSunKg = 1.98855 * pow(10, 30);

  double earthSunDistanceMeters = 1.496 * pow(10, 11);
  double earthAngularVelocityMetersPerSecond = 1.990986 *  pow(10, -7);
  double pixelsInOneEarthSunDistancePerPixel = 150;

  double venusSunDistanceMeters = 0.723 * pow(10, 11);
  double venusAngularVelocityMetersPerSecond = 0.0028 * pow(10, -3);
  double pixelsInOneVenusSunDistancePerPixel = 72.5;
} Constants;

#endif
