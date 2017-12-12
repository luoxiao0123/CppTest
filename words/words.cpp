#include "words.h"
#include <cctype>
#include <string>

using namespace std;

void reverse(const char* str1, char* str2){
	int length = strlen(str1);
	for(int i = 0; i < length; i++){
		str2[i] = str1[length - 1 - i];
	}
	str2[length] = '\0';
}

bool compare(const char* one, const char* two){
	// if one and two are all empty string, they are the same
	if(!one[0] && !two[0]) return 1;
	/* if one is an empty string, while two is not
	 * 1. if two[0] is a letter, they are not the same
	 * 2. if two[0] is not a letter, check recursively whether
	 *    two[] is a string consist of all non-alphabetic character
	 */
	if(!one[0] && two[0] != '\0'){
		if(isalpha(two[0])) return 0;
		else return compare(one, &two[1]);
	}
	// if one[0] is not a letter, eliminate one[0] from string one to compare
	if(one[0] != '\0' && !isalpha(one[0])) return compare(&one[1], two);
	// now that one[0] is a letter when the following code is running
	if(!two[0]) return 0;
	if(isalpha(two[0])){
		if(toupper(one[0]) == toupper(two[0])){
			return compare(&one[1], &two[1]);
		}
		return 0;
	}else{
		return compare(one, &two[1]);
	}
}

bool palindrome(const char* sentence){
	char reverseSentence[500];
	reverse(sentence, reverseSentence);
	return compare(sentence, reverseSentence);
}

bool anagram(const char* str1, const char* str2){
	char sortStr1[500], sortStr2[500];
	sortString(str1, sortStr1);
	sortString(str2, sortStr2);
	return compare(sortStr1, sortStr2);
}

void sortString(const char* str1, char* str2){
	// copy all the character from str1 to str2 and turn the small letter
	// into capital letter
	for(int i = 0; i <= strlen(str1); i++){
		str2[i] = toupper(str1[i]);
	}
	// do bubble sorting in str2
	int j, k, tempcount;
	char temp;
	for(j = 0; j < strlen(str2); j++){
		temp = str2[j];
		tempcount = j;
		for(k = j + 1; k < strlen(str2); k++){
			if(temp > str2[k]){
				temp = str2[k];
				tempcount = k;
			}
		}
		str2[tempcount] = str2[j];
		str2[j] = temp;
	}
}

