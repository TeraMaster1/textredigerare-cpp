#include "Interface.h"


namespace Editor {
  void init_draw() {
    // Create a simple document with three text elements.
    ftxui::Element document = ftxui::hbox({
      ftxui::text("left")   | ftxui::border,
      ftxui::text("middle") | ftxui::border | ftxui::flex,
      ftxui::text("right")  | ftxui::border,
    });

    // Create a screen with full width and height fitting the document.
    auto screen = ftxui::Screen::Create(
      ftxui::Dimension::Full(),       // Width
      ftxui::Dimension::Fit(document) // Height
    );

    // Render the document onto the screen.
    ftxui::Render(screen, document);

    // Print the screen to the console.
    screen.Print();
  }
  void draw(EditorBuffer buffer) {
  }
} // namespace Editor
