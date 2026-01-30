#include "Interface.h"

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>


namespace Editor {
  Interface init_draw(EditorBuffer *buffer) {
    ftxui::Screen screen = ftxui::Screen::Create(ftxui::Dimension::Full(),
                                                 ftxui::Dimension::Full());
    ftxui::Element body = ftxui::Element();
    ftxui::Element bottom_bar = ftxui::Element();
    ftxui::Dimensions dimensions = ftxui::Terminal::Size();
    Interface interface = {buffer, screen, body, bottom_bar, 0, dimensions};
    return interface;
  }

  void create_elements(Interface *interface) {
    std::vector<std::string> lines = interface->buffer->getBufferText();
    int currentLine = interface->buffer->getCurrentLine();
    interface->dimensions = ftxui::Terminal::Size();
    int upper = currentLine - (interface->dimensions.dimy / 2);
    int lower = currentLine + (interface->dimensions.dimy / 2);

    if (lines.empty()) {
      return;
    }

    int start = std::max(0, upper);
    int end = std::min(static_cast<int>(lines.size()) - 1, lower);

    std::vector<ftxui::Element> content;
    for (int i = start; i <= end; ++i) {
      content.push_back(ftxui::text(std::to_string(i) + " " + lines[i]));
    }

    interface->body = ftxui::vbox(content) | ftxui::flex;

    interface->bottomBar = ftxui::vbox(
    {ftxui::filler(),
     ftxui::hbox({ftxui::filler(), ftxui::text(
                    "Vill du [a]vsluta, [v]älja rad, [l]äsa hela fileninnehållet, "
                    "[s]kriva till en rad, s[p]ara innehållet?"),
                  ftxui::filler()})});
  }

  void draw(Interface *interface) {
    interface->screen.Clear();
    ftxui::Render(interface->screen, interface->body);
    ftxui::Render(interface->screen, interface->bottomBar);

    interface->screen.Print();
  }
} // namespace Editor