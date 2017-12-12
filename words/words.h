#ifndef WORDS_H_
#define WORDS_H_

// str2 is the reverse sequence of str1
void reverse(const char* str1, char* str2);

/* pick out the alphabetic character from string one and string two
 * sequentially to check whether they are equal (compatible capital
 * letter and small letter such as A and a are considered the same)
 */
bool compare(const char* one, const char* two);

/* check whether a sentence is palindrome (palindrome means the letters
 * of a sentence is the same when reading forward and backward ignoring
 * the case of letters)
 */
bool palindrome(const char* sentence);

/* check whether str2 is an anagram of str1 (an anagram is a word or
 *  phrase formed by reordering the letters of another word or phrase)
 */
bool anagram(const char* str1, const char* str2);

/* the output str2 is the sorting of str1 from small to big character
 * all letter in str2 is converted to upper case
 */
void sortString(const char* str1, char* str2);

#endif
