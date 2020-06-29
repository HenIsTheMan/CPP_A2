#include "simple_hex_calculator.h"

string simple_hex_calculator(char Operator, string HexaNumber1st, string HexaNumber2nd){
	int carry = 0, strLen = (HexaNumber1st.length() < HexaNumber2nd.length() ? HexaNumber1st.length() : HexaNumber2nd.length());
	vector<char> result;
	for(int i = strLen - 1; i >= 0; --i){
		int decSum = int(HexaNumber1st[i]) + int(HexaNumber2nd[i]) - (int(HexaNumber1st[i]) < 58 ? 48 : 55) - (int(HexaNumber2nd[i]) < 58 ? 48 : 55) + carry;
		carry = (decSum - 16) * (decSum > 16);
		result.push_back((carry != 0 ? 'F' : char(decSum + (decSum % 16 < 10 ? 48 : 55))));
	}
	reverse(result.begin(), result.end());
	string str(result.begin(), result.end());
	return str;
}

//a - a
/* 	long long numberResult = 0;
	vector<char> result;
	for(int i = 0; i < HexaNumber1st.length(); ++i){
		numberResult += (int(toupper(HexaNumber1st[i])) - __int64(int(toupper(HexaNumber1st[i])) < 58 ? 48 : 55)) * pow(16, HexaNumber1st.length() - 1 - i);
	}
	for(int j = 0; j < HexaNumber2nd.length(); ++j){
		numberResult += ((int(toupper(HexaNumber2nd[j])) - __int64(int(toupper(HexaNumber2nd[j])) < 58 ? 48 : 55)) * pow(16, HexaNumber2nd.length() - 1 - j)) * (Operator == '+' ? 1 : -1);
	}
	while(numberResult != 0){
		result.push_back(char(numberResult % 16 + (numberResult % 16 < 10 ? 48 : 55)));
		numberResult /= 16;
	}
	reverse(result.begin(), result.end());
	string str(result.begin(), result.end());
	return str; */