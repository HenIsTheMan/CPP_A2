#include "number_to_text.h"

string number_to_text(string numberStr){
	string str = "", set1[] = {"thousand", "million", "billion", "trillion", "quadrillion", "quintillion"}, set2[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //Initialise a string var and 2 string arrays.
	string set3[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}, set4[] = {"", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}; //Initialise 2 string arrays.
	while(numberStr.length() != 0){ //Loop while length of numberStr != 0.
		int rem = numberStr.length() % 3; //Initialise an int var which holds the remainder of length of numberStr / 3.
		if(numberStr[0] != '0' || numberStr[1] != '0' || numberStr[2] != '0'){ //Execute if the 1st 3 chars of numberStr are not '0'.
			switch(rem){ //Algorithm that flows based on the number of chars in front of the imaginary or present ',' in numberStr due to the absence of breaks...
				case 0: str += set2[int(numberStr[0]) - 48] + (numberStr[0] != '0' ? " hundred " : ""); //Alg part 1.
				case 2: str += (numberStr[!rem] == '1' ? set3[int(numberStr[!rem + __int64(1)]) - 48] + " " : set4[int(numberStr[!rem]) - 49 + (numberStr[!rem] == '0')] + (numberStr[!rem] != '0' ? " " : "")); //Alg part 2.
				case 1: str += (rem == 1 || numberStr[!rem] != '1' ? set2[int(numberStr[rem - __int64(1) + __int64(3) * (rem == 0)]) - 48] + (numberStr[rem - __int64(1) + __int64(3) * (rem == 0)] != '0' ? " " : ""): ""); //Alg part 3.
			}
			str += (numberStr.length() > 3 ? set1[(numberStr.length() - rem - __int64(3) * (rem == 0)) / 3 - 1] + " ": ""); //Add the appropriate string from set1[] and spacing to str.
		}
		numberStr.erase(0, rem + __int64(3) * (rem == 0)); //Remove chars from numberStr that are alr done.
	}
	return str; //Return str.
}