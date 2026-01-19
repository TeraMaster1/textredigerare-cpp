#include "Interface.h"
#include "EditorBuffer.h"
#include <ncurses.h>

namespace Editor {
  void init() {
    initscr();
    refresh();
    getch();
  }
  void draw(EditorBuffer buffer) {}
} // namespace Editor
