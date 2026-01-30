
#pragma once
#ifndef TEXTREDIGERARE_CPP_EDITORBUFFER_H
#define TEXTREDIGERARE_CPP_EDITORBUFFER_H
#include <string>
#include <vector>

namespace Editor {

  class EditorBuffer {
    public:
      explicit EditorBuffer(const std::string &path);
      void print();
      void printAll();
      void editLine(std::string line);
      void saveWritten();
      void selectLine(int line);
      int getCurrentLine() const;
      std::vector<std::string> getBufferText();
      void addRows(int index, int rows);
      ~EditorBuffer();

    private:
      int currentLine;
      std::string path;
      std::vector<std::string> text;
  };
} // namespace Editor

#endif // TEXTREDIGERARE_CPP_EDITORBUFFER_H
