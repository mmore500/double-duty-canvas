//  This file is part of Double Duty Canvas
//  Copyright (C) Matthew Andres Moreno, 2020.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "web/web.h"

#include "double-duty-canvas/draw.hpp"

namespace UI = emp::web;

UI::Document doc("emp_base");

UI::Canvas canvas{500, 500, "my_canvas"};

int main() {

  ddc::draw( canvas );

  doc << "<h1>Hello, browser!</h1>";
  doc << canvas;

  std::cout << "Hello, console!" << std::endl;
  return 0;

}
