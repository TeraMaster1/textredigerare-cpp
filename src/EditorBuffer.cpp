#include "EditorBuffer.h"

#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace Editor {

  EditorBuffer::EditorBuffer(const std::string &path) {
    this->currentLine = 0;
    this->path = path;
    std::ifstream infile;
    infile.open(this->path, std::ios::in);
    if (!infile.is_open()) {
      std::cerr << "Kunde inte öppna fil: " << this->path << std::endl;
      return;
    }

    std::string s;
    while (std::getline(infile, s)) {
      this->text.emplace_back(s);
    }
  }

  void EditorBuffer::selectLine(int line) {
    this->currentLine = line - 1;
    std::cout << this->currentLine + 1 << ": " << this->text[this->currentLine]
      << std::endl;
  }

  void EditorBuffer::printAll() {
    for (int i = 0; i < this->text.size(); i++) {
      std::cout << i + 1 << ": " << this->text[i] << std::endl;
    }
  }

  void EditorBuffer::print() {
    if (this->text.empty()) {
      std::cout << "Ingen text har laddats in." << std::endl;
      return;
    }

    if (this->currentLine < 0 || this->currentLine > text.size()) {
      std::cout << "Raden finns inte med." << std::endl;
      return;
    }

    std::cout << this->currentLine + 1 << ": " << this->text[this->currentLine]
      << std::endl;
  }

  void EditorBuffer::editLine(const std::string line) {
    this->text[this->currentLine] = line;
    std::cout << "Skrev '" << this->text[this->currentLine] << "' till rad "
      << this->currentLine + 1 << std::endl;
  }

  void EditorBuffer::saveWritten() {
    std::ofstream outfile;
    outfile.open(this->path, std::ios::out | std::ios::trunc);

    if (!outfile.is_open()) {
      std::cerr << "Kunde inte öppna fil: " << this->path << std::endl;
      outfile.close();
      return;
    }

    for (const std::string &line : this->text) {
      outfile << line << std::endl;
    }

    outfile.close();
    std::cout << "Sparade filen " << this->path << std::endl;
  }

  EditorBuffer::~EditorBuffer() { this->saveWritten(); }

  int EditorBuffer::getCurrentLine() { return this->currentLine; }

  std::vector<std::string> EditorBuffer::getBufferText() {
    return this->text;
  }

  void EditorBuffer::addRows(int index, int rows) {
    this->text.insert(this->text.begin() + index, rows, "");
  }

} // namespace Editor