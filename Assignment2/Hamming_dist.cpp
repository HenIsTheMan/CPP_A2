#include "Hamming_dist.h"

int Hamming_dist(string str1, string str2){
	int count = 0; //Initialise an int var.
	for(int i = 0; i < min(str1.length(), str2.length()); ++i){ //Loop for i == 0 to i == length of shorter string - 1, incrementing i by 1 each loop.
		count += str1[i] != str2[i]; //Increment count by 1 if the chars at a certain pos are diff.						
	}
	return count + abs(int(str1.length() - str2.length())); //Return number of pos at which the chars are diff + diff in length.
}