#pragma once
#include "EditorBuffer.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

namespace Editor {
  enum Mode { MOVE, INPUT };

  typedef struct {
    EditorBuffer *buffer;
    ftxui::Screen screen;
    std::vector<ftxui::Element> elements;
    int cursorPosX;
  } Interface ;

  Interface init_draw(EditorBuffer *buffer);
  void create_elements(Interface *interface);
  void draw(Interface *interface);
} // namespace Editor
