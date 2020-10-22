//  This file is part of Double Duty Canvas
//  Copyright (C) Matthew Andres Moreno, 2020.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "web/web.h"

#include "double-duty-canvas/draw.hpp"

namespace UI = emp::web;

struct setup_fake_dom {

  setup_fake_dom() { EM_ASM(

    // setup jsdom
    var jsdom = require("jsdom");
    var JSDOM = jsdom.JSDOM;

    global.dom = (new JSDOM(`<div id="emp_base"></div>`));
    global.document = dom.window.document;

    // setup jquery
    var jquery = require('jquery');
    global.$ = jquery( dom.window );

    // shim for alert
    global.alert = console.log;

  ); }

} do_setup;

UI::Document doc{"emp_base"};

void save_canvas() { EM_ASM( setTimeout(function(){

  fs = require('fs');

  canvas = document.getElementById("my_canvas");

  // adapted from https://stackoverflow.com/a/11335500
  var url = canvas.toDataURL('image/png');
  var regex = `^data:.+\/(.+);base64,(.*)$`;

  var matches = url.match(regex);
  var ext = matches[1];
  var data = matches[2];
  var buffer = Buffer.from(data, 'base64');

  fs.writeFileSync('data.' + ext, buffer);

  console.log( dom.window.document.documentElement.outerHTML );

}, 10); ); }

int main() {

  UI::Canvas canvas{500, 500, "my_canvas"};
  doc << canvas;

  ddc::draw( canvas );

  save_canvas();

  return 0;

}
