#ifndef BRAILLE_H_
#define BRAILLE_H_
#include <iostream>
#include <fstream>

using namespace std;

int encode_character(char ch, char* braille);

void encode(const char* plaintext, char* braille);

void print_braille(const char* plaintext, ostream& output);

void encode_special(char ch, char* braille);

void encode_lower(char ch, char* braille);

void encode_upper(char ch, char* braille);

void encode_digit(char ch, char* braille);

#endif
