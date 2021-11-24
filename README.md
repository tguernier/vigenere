# Vigenere Cipher in C++
This is an implementation of the [Vigenere Cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) in C++. The code can encrypt and decrypt messages in the English alphabet. All other characters are passed through without being encrypted.

## Build Instructions
Simply run `make all` to build. The project directory can be cleaned with `make clean`.

## Usage Examples
```
$ echo "Hello!" | ./vigenere.out -e hi
omstv!
$ echo "Hello!" | ./vigenere.out -e hi | ./vigenere.out -d hi
hello!
$ echo "This is an example of a text file being encrypted and decrypted." >> test.txt
$ ./vigenere.out -e -f test.txt testkey >> cipher.txt
$ cat cipher.txt
mlal sw yg iptwtjx sx t divm jaeo fcbry xxgprtlxn elw hwvbcnmiv.
$ ./vigenere.out -d -f cipher.txt testkey
this is an example of a text file being encrypted and decrypted.
```

