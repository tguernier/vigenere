#include "vigenere.h"

std::string vigenere_encrypt(std::string& plaintext, std::string& key) {
  std::string ciphertext = "";
  auto j = key.begin();

  for (auto i = plaintext.begin(); i != plaintext.end(); i++) {
    // shift the character at index i of the plaintext by the numeric value of the character
    // at index j of the key modulo 25
    // formula: Ci = (Pi + Kj) mod 25 (0 indexed)
    if (!isalpha(*i)) {
      // pass through non-alphabetical characters without encrypting them
      ciphertext.append(1, *i);
    } else {
      ciphertext.append(1, alphabet[(alphabet_index(*i) + alphabet_index(*j)) % 26]);
      j++;
      if (j == key.end()) {
        j = key.begin();
      }
    }
  } 
  return ciphertext;
}

std::string vigenere_decrypt(std::string& ciphertext, std::string& key) {
  std::string plaintext = "";
  auto j = key.begin();

  for (auto i = ciphertext.begin(); i != ciphertext.end(); i++) {
    // shift the character at index i of the ciphertext by the difference of the character
    // at index j of the key and 26 modulo 26
    // formula: Pi = (Ci + (26 - Kj)) mod 26 (0 indexed)
    if (!isalpha(*i)) {
      // pass through non-alphabetical characters without decrypting them
      plaintext.append(1, *i);
    } else {
      plaintext.append(1, alphabet[(alphabet_index(*i) + (26 - alphabet_index(*j))) % 26]);
      j++;
      if (j == key.end()) {
        j = key.begin();
      }
    }
  } 
  return plaintext;
}

// helper functions
const int alphabet_index(const char c) {
  // returns the index of the char c in the alphabet (0-indexed)
  // returns same result for same character in uppercase/lowercase
  return isupper(c) ? c - 'A' : c - 'a';
}
