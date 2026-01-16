#include <iostream>

#include "EditorBuffer.h"

int main() {
  std::cout << "Programmet startade" << std::endl;
  std::string path;
  std::cout << "Skriv in filen: ";
  std::cin >> path;
  EditorBuffer buffer = EditorBuffer(path);
  buffer.print();
  char opt = 'l';
  while (opt != 'a')
  {
    std::cout<< "Vill du [a]vsluta, [v]älja rad, [l]äsa hela fileninnehållet, [s]kriva till en rad, s[p]ara innehållet?";
    std::cin >> opt;
    switch (opt){

    case 'l': {
      buffer.print();
      break;
    }
      case 'v': {
      std::cout<< "Välj rad: ";
      int line;
      std::cin>> line;
      buffer.selectLine(line);
      break;
    }
    case 's':
      {
        int lineNum;
        std::cout<< "Vilken rad? ";
        std::cin >> lineNum;
        buffer.print(lineNum);
        buffer.selectLine(lineNum);
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
