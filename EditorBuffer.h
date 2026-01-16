
#pragma once
#ifndef TEXTREDIGERARE_CPP_EDITORBUFFER_H
#define TEXTREDIGERARE_CPP_EDITORBUFFER_H
#include <fstream>
#include <string>
#include <vector>


class EditorBuffer {
public:
  explicit EditorBuffer(const std::string& path);
  void print();
  void printAll();
  void editLine(std::string line);
  void saveWritten();
  void selectLine(int line);
  int getCurrentLine();
  ~EditorBuffer();
private:
  int currentLine;
  std::string path;
  std::vector<std::string> text;
};


#endif //TEXTREDIGERARE_CPP_EDITORBUFFER_H
