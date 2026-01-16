

#include "EditorBuffer.h"

#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

std::ifstream infile;
std::vector<std::string> text;
std::string filePath;
int currentLine;

EditorBuffer::EditorBuffer(const std::string& path) {
  filePath = path;
  infile.open(path,  std::ios::in);
  if (!infile.is_open())
  {
    std::cerr << "Kunde inte öppna fil: " << path << std::endl;
    return;
  }

  std::string s;
  while (std::getline(infile, s))
  {
    text.emplace_back(s);
  }
}

void EditorBuffer::selectLine(int line)
{
  currentLine = line - 1;
  std::cout << currentLine + 1 << ": " << text[currentLine];
}

void EditorBuffer::print()
{
  for (int i = 0; i < text.size(); i++)
  {
    std::cout<< i + 1 << ": " << text[i] << std::endl;
  }
}

void EditorBuffer::print(int line)
{
  std::cout<< line << ": " << text[line - 1] << std::endl;
}

void EditorBuffer::editLine(const std::string line)
{
  text[currentLine] = line;
  std::cout << "Skrev '" << text[currentLine] << "' till rad " << currentLine + 1 << std::endl;
}

void EditorBuffer::saveWritten()
{
  infile.close();
  std::ofstream outfile;
  outfile.open(filePath, std::ios::out | std::ios::trunc);

  if (!outfile.is_open())
  {
    std::cerr<< "Kunde inte öppna fil: " << filePath << std::endl;
    outfile.close();
    return;
  }

  for (const std::string& line : text)
  {
    outfile << line << std::endl;
  }

  outfile.close();
}

EditorBuffer::~EditorBuffer()
{
  this->saveWritten();
}

