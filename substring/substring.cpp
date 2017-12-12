#include "substring.h"
#include <string>

int substring_position(const char* str1, const char* str2){
	int i = 0;
	if(!str1[0] && !str2[0]) return 0;
	while(str2[i]){
		if(is_prefix(str1, &str2[i])) return i;
		i++;
	}
	return -1;
}

bool is_prefix(const char* str1, const char* str2){
	if(str1[0] == '\0') return true;
	if(str1[0] == str2[0]) return is_prefix(&str1[1], &str2[1]);
	return false;
}

int substring_position2(const char* str1, const char* str2){
	return strstr(str2, str1) == nullptr ? -1 : strlen(str2) - strlen(strstr(str2, str1));
}
