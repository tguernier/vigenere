#include "vigenere.h"

int main(int argc, char* argv[]) {
  if (!(argc == 3 || argc == 5) || !((std::string(argv[1]) == "-e") || (std::string(argv[1]) == "-d"))) {
    std::cout << "Encrypt: -e key (input from stdin)" << std::endl;
    std::cout << "Decrypt: -d key (input from stdin)" << std::endl;
    std::cout << "Encrypt File: -e -f filename key" << std::endl;
    std::cout << "Decrypt File: -d -f filename key" << std::endl;
    return -1;
  } else {
    std::string source_text;
    std::string result_text;
    std::string key;
    std::ifstream source_text_file;
    
    if (argc == 5 && std::string(argv[2]) == "-f") {
      std::string line;
      source_text_file.open(std::string(argv[3]));
      if (source_text_file.is_open()) {
        while (getline(source_text_file, line)) {
          source_text.append(line);
          source_text.append("\n");
        }
        source_text.pop_back(); // remove last \n
      } else {
        std::cout << "File not opened!" << std::endl;
      }
      source_text_file.close();
      key = std::string(argv[4]);
    } else {
      std::string line;
      while (getline(std::cin, line)) {
        source_text.append(line);
      } 
      key = std::string(argv[2]);
    }
    if (std::string(argv[1]) == "-e") {
      result_text = vigenere_encrypt(source_text, key);
    } else if (std::string(argv[1]) == "-d") {
      result_text = vigenere_decrypt(source_text, key);
    }
    std::cout << result_text << std::endl;
  }
  return 0;
}
