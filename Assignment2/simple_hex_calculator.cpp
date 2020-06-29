#include "simple_hex_calculator.h"

string simple_hex_calculator(char Operator, string hexNumber1st, string hexNumber2nd){
	int carry = 0, borrow = 0; //Initialise 2 int vars.
	vector<char> result; //Initialise a char vector.
	for(int i = int(hexNumber1st.length()) - 1; i >= 0; --i){ //Loop for i == length of hexNumber1st - 1 to i == 0, decrementing i by 1 each loop.
		bool didBorrow = borrow * (int(hexNumber1st[i]) > int(hexNumber2nd[i])); //Track whether the digits at the back borrowed from the current digit.
		borrow = (15 + (i == hexNumber1st.length() - 1 || int(hexNumber1st[i + __int64(1)]) > int(hexNumber2nd[i + __int64(1)]))) * (int(hexNumber1st[i]) < int(hexNumber2nd[i])); //Calculate the borrow from subtraction.
		int dec = int(hexNumber1st[i]) - (int(hexNumber1st[i]) < 58 ? 48 : 55) + (int(hexNumber2nd[i]) - (int(hexNumber2nd[i]) < 58 ? 48 : 55)) * (Operator == '+' ? 1 : -1) + (Operator == '+' ? carry : borrow); //Calculate the sum including carry or diff including borrow of 2 digits at a certain pos.
		carry = (dec > 15) * (Operator == '+'); //Calculate the carry from addition.
		dec -= didBorrow * (Operator == '-'); //Reduce the subtraction outcome by 1 if the digit(s) behind it in hexNumber1st borrowed.
		result.insert(result.begin(), char(dec + (dec % 16 < 10 ? 48 : 55) - 16 * carry)); //Insert the resulting char at the front of result.
	}
	string str(result.begin(), result.end()); //Convert the char vector to a string var.
	while(str[0] == '0' && str.length() != 1){ //Loop while the 1st char of str == '0' && length of str != 1.
		str.erase(str.begin()); //Remove an extra '0' fronting str.
	}
	return (carry == 1 ? "1" : "") + str; //Return the calculated outcome.
}