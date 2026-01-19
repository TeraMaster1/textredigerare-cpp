#include "EditorBuffer.h"
#include <ncurses.h>

namespace Editor {
  enum Mode { MOVE, INPUT };
  void init();
  void draw(EditorBuffer buffer);
} // namespace Editor
