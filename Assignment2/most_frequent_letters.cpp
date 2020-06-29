#include "most_frequent_letters.h"

void most_frequent_letter(string str, struct frequents result[]){
	int ii = 0; //Initialise an int var.
	for(int i = 0; i < str.length(); ++i){ //Loop for i == 0 to i == length of string - 1, incrementing i by 1 each loop.
		for(int index = 0; index < str.length(); ++index){ //Loop for index == 0 to index == length of string - 1, incrementing index by 1 each loop.
			if(str[i] == result[index].letter){ //Execute if the char at a certain pos in the string == a char already stored in result[].
				ii = (++result[index].count > result[ii].count ? index : (int(result[index].letter) < int(result[ii].letter) && result[index].count == result[ii].count ? index : ii)); //Assign the index of the most frequent letter to ii.
				break; //Break the loop.
			} else if(result[index].letter == '\0' && int(str[i]) > 96 && int(str[i]) < 123){ //Execute if result[index].letter is not a letter and str[i] is a lowercase letter.
				result[index].letter = str[i]; //Store str[i] in result[index].letter.
				ii = (result[index].count >= result[ii].count && int(result[index].letter) < int(result[ii].letter) ? index : ii); //Assign the index of the most frequent letter to ii.
				break; //Break the loop.
			}
		}
	}
	(*result).letter = result[ii].letter; //Assign the most frequent letter to (*result).letter.
}