#pragma once

#include <iostream>

#include "../../third-party/Empirical/source/web/Canvas.h"

namespace ddc {

void draw(emp::web::Canvas& canvas) {
  canvas.Text( emp::Point{100, 100}, "hello world!" );
}

} // namespace ddc
