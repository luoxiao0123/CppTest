#ifndef SOUNDEX_H_
#define SOUNDEX_H_


void encode(const char* surname, char* soundex);

bool compare(const char* one, const char* two);

int count(const char* surname, const char* sentence);

// return the digit mapping with the small letter
char mapping(char letter);

// returns the number of words in a given sentence that have
// the same Soundex encoding as scode
int count2(const char* scode, const char* sentence);

#endif
