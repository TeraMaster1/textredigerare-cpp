#include "EditorBuffer.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

namespace Editor {
  enum Mode { MOVE, INPUT };
  void init_draw();
  void draw(EditorBuffer buffer);
} // namespace Editor
