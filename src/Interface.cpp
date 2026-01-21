#include "Interface.h"

#include <ranges>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"


namespace Editor {
  Interface init_draw(EditorBuffer *buffer) {
    ftxui::Screen screen = ftxui::Screen::Create(ftxui::Dimension::Full(),
                                                 ftxui::Dimension::Fixed(10));
    std::vector<ftxui::Element> elements = std::vector<ftxui::Element>();
    ftxui::Element bottom_bar = ftxui::hbox(
    {ftxui::text("Vill du [a]vsluta, [v]älja rad, [l]äsa hela fileninnehållet, "
               "[s]kriva till en rad, s[p]ara innehållet?")});
    elements.push_back(bottom_bar);
    Interface interface = {buffer, screen, elements, 0};
    return interface;
  }

  void draw(Interface *interface) {
    for (ftxui::Element element : interface->elements) {
      ftxui::Render(interface->screen, element);
    }
  }
} // namespace Editor