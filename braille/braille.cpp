#include "braille.h"
#include <cctype>

using namespace std;

int encode_character(char ch, char* braille){
	if(isalpha(ch)){
		if(isupper(ch)){
			encode_upper(ch, braille);
			return 12;
		}
		else{
			encode_lower(ch, braille);
			return 6;
		}
	}
	if(isdigit(ch)){
		encode_digit(ch, braille);
		return 12;
	}
	encode_special(ch, braille);
	return 6;
}

void encode(const char* plaintext, char* braille){
	if(!plaintext[0]){
		sprintf(braille, "%s", "");
		return;
	}
	char charcode[13], restcode[512];
	encode_character(plaintext[0], charcode);
	encode(&plaintext[1], restcode);
	sprintf(braille, "%s%s", charcode, restcode);
}

void print_braille(const char* plaintext, ostream& output){
	int i = 0;
	char code[13], line1[512], line2[512], line3[512], line4[512];
	line1[0] = '\0';
	line2[0] = '\0';
	line3[0] = '\0';
	line4[0] = '\0';
	while(plaintext[i]){
		int length = encode_character(plaintext[i], code);
		if(length == 6){
			snprintf(line1, 512, "%s%c%c%c", line1, code[0], code[1], ' ');
			snprintf(line2, 512, "%s%c%c%c", line2, code[2], code[3], ' ');
			snprintf(line3, 512, "%s%c%c%c", line3, code[4], code[5], ' ');
			snprintf(line4, 512, "%s%c%c%c", line4, plaintext[i], ' ', ' ');
		}
		if(length == 12){
			snprintf(line1, 512, "%s%c%c%c%c%c%c", line1, code[0], code[1], ' ', code[6], code[7], ' ');
			snprintf(line2, 512, "%s%c%c%c%c%c%c", line2, code[2], code[3], ' ', code[8], code[9], ' ');
			snprintf(line3, 512, "%s%c%c%c%c%c%c", line3, code[4], code[5], ' ', code[10], code[11], ' ');
			snprintf(line4, 512, "%s%c%c%c%c%c%c", line4, ' ', ' ', ' ', plaintext[i], ' ', ' ');
		}
		i++;
	}
	output << line1 << endl;
	output << line2 << endl;
	output << line3 << endl;
	output << line4 << endl;
}

void encode_special(char ch, char* braille){
	char* code;
	code = (char*)"......";
	if(ch == '.') code = (char*)".0..00";
	if(ch == ',') code = (char*)".0....";
	if(ch == ';') code = (char*)".00...";
	if(ch == '-') code = (char*)"..0..0";
	if(ch == '!') code = (char*)".00.0.";
	if(ch == '?') code = (char*)".00..0";
	if(ch == '(' || ch == ')') code = (char*)".00.00";
	sprintf(braille, "%s", code);
}

void encode_lower(char ch, char* braille){
	char* code;
	if(ch == 'a') code = (char*)"0.....";
	if(ch == 'b') code = (char*)"00....";
	if(ch == 'c') code = (char*)"0..0..";
	if(ch == 'd') code = (char*)"0..00.";
	if(ch == 'e') code = (char*)"0...0.";
	if(ch == 'f') code = (char*)"00.0..";
	if(ch == 'g') code = (char*)"00.00.";
	if(ch == 'h') code = (char*)"00..0.";
	if(ch == 'i') code = (char*)".0.0..";
	if(ch == 'j') code = (char*)".0.00.";
	if(ch == 'k') code = (char*)"0.0...";
	if(ch == 'l') code = (char*)"000...";
	if(ch == 'm') code = (char*)"0.00..";
	if(ch == 'n') code = (char*)"0.000.";
	if(ch == 'o') code = (char*)"0.0.0.";
	if(ch == 'p') code = (char*)"0000..";
	if(ch == 'q') code = (char*)"00000.";
	if(ch == 'r') code = (char*)"000.0.";
	if(ch == 's') code = (char*)".000..";
	if(ch == 't') code = (char*)".0000.";
	if(ch == 'u') code = (char*)"0.0..0";
	if(ch == 'v') code = (char*)"000..0";
	if(ch == 'w') code = (char*)".0.000";
	if(ch == 'x') code = (char*)"0.00.0";
	if(ch == 'y') code = (char*)"0.0000";
	if(ch == 'z') code = (char*)"0.0.00";
	sprintf(braille, "%s", code);
}

void encode_upper(char ch, char* braille){
	char* head = (char*)".....0";
	char tail[7];
	encode_lower(ch + 'a' - 'A', tail);
	sprintf(braille, "%s%s", head, tail);
}

void encode_digit(char ch, char* braille){
	char* head = (char*)"..0000";
	char tail[7];
	if(ch == '0') encode_lower('j', tail);
	else encode_lower(ch + 'a' - '1', tail);
	sprintf(braille, "%s%s", head, tail);
}
