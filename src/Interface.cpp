#include "Interface.h"
#include "EditorBuffer.h"
#include <ncurses.h>

namespace Editor {
  void init() {
    initscr();
    refresh();
  }
  void draw(EditorBuffer buffer) {
    addstr(buffer.getBufferText()[0].c_str());
    getch();
  }
} // namespace Editor
