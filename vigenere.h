#include <iostream>
#include <fstream>
#include <ctype.h>

const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

std::string vigenere_encrypt(std::string& plaintext, std::string& key);
std::string vigenere_decrypt(std::string& ciphertext, std::string& key);

// helper functions
const int alphabet_index(const char c);
