#include <iostream>
#include <filesystem>

#include "EditorBuffer.h"
#include "Interface.h"

int main(int argc, char **argv) {
  std::cout << "Katalog: " << std::filesystem::current_path() << "\n";
  std::cout << "Programmet startade" << std::endl;
  std::string path;

  if (argc != 2) {
    std::cout << "Skriv in filen: ";
    std::cin >> path;
  } else {
    path = std::string(argv[1]);
  }

  Editor::EditorBuffer buffer = Editor::EditorBuffer(path);
  Editor::Interface interface = Editor::init_draw(&buffer);
  Editor::draw(buffer);
  //buffer.printAll();
  char opt = 'l';
  while (opt != 'a') {
    std::cout << ;
    std::cin >> opt;
    switch (opt) {

      case 'l':
        {
          buffer.printAll();
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
          buffer.printAll();
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
