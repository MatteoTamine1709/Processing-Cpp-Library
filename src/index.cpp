#include "ProcessingCpp.hpp"
#include <iostream>
#include "Constants.hpp"

Constants constants;

std::unordered_map<std::string, Status> planets;

double calculateDistanceAcceleration(Status& state) {
  return state.distance.value * pow(state.angle.speed, 2) -
    (constants.gravitationalConstant * state.massOfTheSunKg) / pow(state.distance.value, 2);
}

double calculateAngleAcceleration(Status& state) {
  return -2.0 * state.distance.speed * state.angle.speed / state.distance.value;
}

double newValue(double currentValue, double deltaT, double derivative) {
  return currentValue + deltaT * derivative;
}

double scaledDistance(Status& state) {
  return state.distance.value / state.scaleFactor;
}

Status& calculateNewPosition(Status& state) {
  // Calculate new distance
  double distanceAcceleration = calculateDistanceAcceleration(state);
  state.distance.speed = newValue(state.distance.speed, constants.deltaT, distanceAcceleration);
  state.distance.value = newValue(state.distance.value, constants.deltaT, state.distance.speed);

  // Calculate new angle
  double angleAcceleration = calculateAngleAcceleration(state);
  state.angle.speed = newValue(state.angle.speed, constants.deltaT, angleAcceleration);
  state.angle.value = newValue(state.angle.value, constants.deltaT, state.angle.speed);

  if (state.angle.value > TWO_PI)
    state.angle.value = std::fmod(state.angle.value, TWO_PI);
  return state;
}

void updatePosition(Status& state) {
  for (int i = 0; i < constants.numberOfCalculationsPerFrame; i++)
    state = calculateNewPosition(state);
}



void preload() {
}

void setup() {
  size(800, 800);
  planets["earth"] = {
    distance: {
      value: constants.earthSunDistanceMeters,
      speed: 0
    },
    angle: {
      value: PI / 6,
      speed: constants.earthAngularVelocityMetersPerSecond
    },
    massOfTheSunKg: constants.massOfTheSunKg,
    c: color(0, 255, 0),
    scaleFactor: constants.earthSunDistanceMeters / constants.pixelsInOneEarthSunDistancePerPixel
  };
}

void draw() {
  background(0);
  fill(255, 0, 0);
  circle(width() / 2, height() / 2, 50);
  for (auto &[planetName, planet] : planets) {
    updatePosition(planet);
    fill(planet.c);
    circle(width() / 2 + scaledDistance(planet) * cos(planet.angle.value), height() / 2 + scaledDistance(planet) * sin(planet.angle.value), 20);
  }
  // double m = map(mouseX(), 0, width(), 1, 5);
  // state.massOfTheSunKg = constants.massOfTheSunKg * m;
}

void onMousePressed() {
}

void onMouseReleased() {

}

void onMouseWheel(MouseEvent event) {
}