#include"soundex.h"
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

void encode(const char* surname, char* soundex){
	int i = 0, count = 0;
	char temp;
	while(surname[i]){
		if(!isalpha(surname[i])){
			cout << surname[i] << "is not a letter!" << endl;
			return;
		}
		if(i == 0){
			soundex[count] = toupper(surname[i]);
			count++;
		}else{
			temp = mapping(tolower(surname[i]));
			if(temp != '0' && temp != soundex[count - 1]){
				soundex[count] = temp;
				count++;
			}
		}
		i++;
		if(count >= 4) return;
	}
	if(count < 4){
		for(int j = count; j < 4; j++){
			soundex[j] = '0';
		}
	}
}

bool compare(const char* one, const char* two){
	if(!one[0] && !two[0]) return true;
	if(one[0] == two[0]){
		return compare(&one[1], &two[1]);
	}
	return false;
}

int count(const char* surname, const char* sentence){
	char scode[5];
	encode(surname, scode);
	return count2(scode, sentence);
}

int count2(const char* scode, const char* sentence){
	int i = 0, count = 0;
	char word[50];
	char wordcode[5];
	/* Loop: pick out all words from the sentence sequentially and
	 * for each word, store them temporarily in word[50], then convert
	 * into wordcode[5]. If wordcode and scode are the same, increment
	 * the return value of the function
	 */
	while(sentence[i]){
		if(!isalpha(sentence[i])){
			if(count == 0){
				i++;
				continue;
			}else{
				i++;
				break;
			}
		}
		word[count] = sentence[i];
		i++;
		count++;
	}
	if(count == 0) return 0;
	word[count] = '\0';
	encode(word, wordcode);
	if(compare(wordcode, scode)){
		return 1 + count2(scode, &sentence[i]);
	}else{
		return count2(scode, &sentence[i]);
	}
}

char mapping(char letter){
	if(letter == 'b' || letter == 'f' ||
			letter == 'p' || letter == 'v') return '1';
	if(letter == 'c' || letter == 'g' ||
			letter == 'j' || letter == 'k' ||
			letter == 'q' || letter == 's' ||
			letter == 'x' || letter == 'z') return '2';
	if(letter == 'd' || letter == 't') return '3';
	if(letter == 'l') return '4';
	if(letter == 'm' || letter == 'n') return '5';
	if(letter == 'r') return '6';
	return '0';
}


