#include "Interface.h"

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>


namespace Editor {
  Interface init_draw(EditorBuffer *buffer) {
    ftxui::Screen screen = ftxui::Screen::Create(ftxui::Dimension::Full(),
                                                 ftxui::Dimension::Full());
    std::vector<ftxui::Element> elements = std::vector<ftxui::Element>();
    Interface interface = {buffer, screen, elements, 0};
    return interface;
  }

  void create_elements(Interface *interface) {
    std::vector<std::string> lines = interface->buffer->getBufferText();
    std::string text;
    for (const std::string& line : lines) {
      text.append(line + "\n");
    }
    ftxui::Element bottom_bar = ftxui::vbox(
    {ftxui::hbox({ftxui::text(text)}),
     ftxui::hbox({ftxui::filler(), ftxui::text(
                    "Vill du [a]vsluta, [v]älja rad, [l]äsa hela fileninnehållet, "
                    "[s]kriva till en rad, s[p]ara innehållet?"),
                  ftxui::filler()})});
    interface->elements.push_back(bottom_bar);
  }

  void draw(Interface *interface) {
    interface->screen.Clear();
    for (const ftxui::Element &element : interface->elements) {
      ftxui::Render(interface->screen, element);
    }

    interface->screen.Print();
  }
} // namespace Editor