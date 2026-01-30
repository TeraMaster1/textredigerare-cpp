#pragma once
#include "EditorBuffer.h"
#include <ftxui/dom/elements.hpp>
#include "ftxui/component/screen_interactive.hpp"

namespace Editor {
  enum Mode { MOVE, INPUT };

  typedef struct {
    EditorBuffer *buffer;
    ftxui::ScreenInteractive *screen;
    ftxui::Element body;
    ftxui::Element bottomBar;
    int cursorPosX;
  } Interface ;

  Interface init_draw(EditorBuffer *buffer);
  void create_elements(Interface *interface);
  void draw(Interface *interface);
} // namespace Editor
