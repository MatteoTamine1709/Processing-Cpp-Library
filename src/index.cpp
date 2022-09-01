#include "ProcessingCpp.hpp"
#include "Slider.hpp"
#include <iostream>

using namespace std;

Slider s = Slider(0, 100, 1, 50);

struct Spot {
    int spotSize;
    int spikeLength;
};

vector<Spot> spots;

void preload() {
}

void setup() {
  size(800, 800);
  for (int i = 0; i < 100; ++i) {
    spots.push_back({(int)(random() % width()), (int)(height() - random() % height())});
  }

  // loadFont("./library/ressources/fonts/arial.ttf");
}

void draw() {
  background(255);
  fill(0);
  strokeWeight(0);
  for (const auto &spot : spots) {
    square(spot.spotSize, spot.spikeLength, 5);
  }
  s.draw(400, 400, 100, 30);
}

void onMousePressed() {
}

void onMouseReleased() {

}

void onMouseWheel(MouseEvent event) {
}