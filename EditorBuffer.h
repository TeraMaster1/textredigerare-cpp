//
// Created by hen3066 on 2025-10-22.
//
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
  void print(int line);
  void editLine(std::string line);
  void saveWritten();
  void selectLine(int line);
  ~EditorBuffer();
};


#endif //TEXTREDIGERARE_CPP_EDITORBUFFER_H