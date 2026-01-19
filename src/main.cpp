#include <iostream>

#include "EditorBuffer.h"
#include "Interface.h"

int main(int argc, char **argv) {
  std::cout << "Programmet startade" << std::endl;
  std::string path;

  if (argc != 2) {
    std::cout << "Skriv in filen: ";
    std::cin >> path;
  } else {
    path = std::string(argv[1]);
  }

  Editor::EditorBuffer buffer = Editor::EditorBuffer(path);
  buffer.print();
  char opt = 'l';
  while (opt != 'a') {
    std::cout << "Vill du [a]vsluta, [v]älja rad, [l]äsa hela fileninnehållet, "
                 "[s]kriva till en rad, s[p]ara innehållet? ";
    std::cin >> opt;
    switch (opt) {

      case 'l':
        {
          buffer.print();
          break;
        }
      case 'v':
        {
          std::cout << "Välj rad: ";
          int line;
          std::cin >> line;
          buffer.selectLine(line);
          break;
        }
      case 's':
        {
          buffer.print();
          std::string strLine;
          std::cout << "Skriv vad du vill ska stå på raden: ";
          std::cin.ignore();
          std::getline(std::cin, strLine);
          buffer.editLine(strLine);
          break;
        }
      case 'p':
        {
          buffer.saveWritten();
          break;
        }
      default:
        {
          std::cout << "Ogilitgt alternativ, försök igen." << std::endl;
          break;
        }
    }
  }
  return 0;
}
