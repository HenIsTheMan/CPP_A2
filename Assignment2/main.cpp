#include "main.h"

int main(){
	while(1){ //Q1
		string str1, str2; //Declare 2 string vars.
		cout << "Input 2 words separated by a space or an enter: "; //Cout.
		cin >> str1 >> str2; //Cin.
		if(str1 == "bye" && str2 == "bye"){ //Execute if str1 == "bye" && str2 == "bye".
			cout << endl; //Cout.
			break; //Break the loop.
		}
		cout << "> Hamming dist between \"" << str1 << "\" and \"" << str2 << "\" is " << Hamming_dist(str1, str2) << ".\n\n"; //Cout.
	}
	while(1){ //Q2
		char myStr[100]; //Declare a char array of size 100.
		cout << "Input string to find most frequent letters: "; //Cout.
		while(cin.get() != '\n'){ //Loop while cin.get() != '\n'.
			cin.clear(); //Clear cin.
		}
		cin.get(myStr, 101); //Insert 100 chars into myStr.
		string str = myStr; //Initialise a string var which holds the chars in myStr[100] combined.
		if(str == "bye" || str == ""){ //Execute if str == "bye" || str == "".
			cin.clear(); //Clear cin.
			cout << endl; //Cout.
			break; //Break the loop.
		}
		for(int i = 0; i < str.length(); ++i){ //Loop for i == 0 to i == length of string - 1, incrementing i by 1 each loop.
			str[i] = tolower(str[i]); //Make a letter lowercase.
		}
		frequents *result = new frequents[str.length()]; //Declare a pointer which pts to a dynamic memory allocated for a struct array of size str.length().
		most_frequent_letter(str, result); //Call the function and pass str and result as arguments.
		if(!isalpha((*result).letter)){ //Execute if the most frequent "letter" is not a letter.
			cout << "There are no letters in your input.\n\n"; //Cout.
		} else{ //Else...
			cout << "The most frequent letter is '" << (*result).letter << "'"; //Cout.
			while(str.find((*result).letter) != str.npos){ //Loop while the most frequent letter exists in the string.
				str.erase(str.begin() + str.find((*result).letter)); //Remove the most frequent letter from the string.
			}
			delete[] result; //Deallocate the dynamic memory allocated for the struct array of size str.length().
			if(str.length() != 0){ //Execute if the string is not an empty string.
				frequents *result2 = new frequents[str.length()]; //Declare a pointer which pts to a dynamic memory allocated for a struct array of size str.length().
				most_frequent_letter(str, result2); //Call the function and pass str and result2 as arguments.
				if(isalpha((*result2).letter)){ //Execute if the most frequent letter is indeed a letter.
					cout << " and the 2nd-most frequent letter is '" << (*result2).letter << "'"; //Cout.
				}
				delete[] result2; //Deallocate the dynamic memory allocated for the struct array of size str.length().
			}
			cout << ".\n\n"; //Cout.
		}
	}
	while(1){ //Q3
		string str; //Declare a string var.
		bool pass = 0; //Initialise a bool var.
		do{ //Do...
			cout << "Input a number to change into text: "; //Cout.
			cin >> str; //Cin.
			for(int i = 0; i < str.length(); ++i){ //Loop for i == 0 to i == length of string - 1, incrementing i by 1 each loop.
				if(int(str[i]) < 48 || int(str[i]) > 57){ //Execute if string is not fully made up of digits.
					cout << "Wrong input" << "\n\n"; //Cout.
					break; //Break the loop.
				} else if(i == str.length() - 1){ //Else if it is the last loop...
					++pass; //Make pass == true by incrementing it by 1.
				}
			}
		} while(!pass); //While pass == false.
		if(str == "0"){ //Execute if str == "0".
			cout << endl; //Cout.
			break; //Break the loop.
		}
		while(str[0] == '0'){ //Loop while the 1st char of the string == '0'.
			str.erase(str.begin()); //Remove the 1st char of the string from the string.
		}
		while(count(str.begin(), str.end(), ',') != 0){ //Loop while ',' exists in the string.
			str.erase(str.begin() + str.find(',')); //Remove the 1st ',' of the string from the string.
		}
		cout << "> " << str << " converts to \"" << number_to_text(str) << "\b\".\n\n"; //Cout.
	}
	while(1){ //Q4
		char myOperator; //Declare a char var.
		string str1, str2; //Declare 2 string vars.
		bool pass = 0; //Initialise a bool var.
		do{ //Do...
			cout << "Input the operator (+/-): "; //Cout.
			cin >> myOperator; //Cin.
			while(cin.get() != '\n'){ //Loop while cin.get() != '\n'.
				cin.clear(); //Clear cin.
			}
			if(myOperator != '+' && myOperator != '-'){ //Execute if the operator input is wrong.
				cout << "Wrong operator" << "\n\n"; //Cout.
			}
		} while(myOperator != '+' && myOperator != '-'); //While the operator input is wrong.
		do{ //Do...
			cout << "Input the 1st non-negative hex number (20 digits max, no '0x' in front): "; //Cout.
			cin >> str1; //Cin.
			for(int i = 0; i < str1.length(); ++i){ //Loop for i == 0 to i == length of str1 - 1, incrementing i by 1 each loop.
				if(str1.length() > 20 || (!isalpha(str1[i]) && !isdigit(str1[i]) || int(toupper(str1[i])) > 70)){ //Execute if str1 is not a non-negative hex number with 20 digits max and no '0x' in front.
					cout << "Wrong input" << endl; //Cout.
					break; //Break the loop.
				} else if(i == str1.length() - 1){ //Else if it is the last loop...
					++pass; //Make pass == true by incrementing it by 1.
				}
			}
		} while(!pass); //While pass == false.
		do{ //Do...
			pass = 0; //Assign 0 to pass.
			cout << "Input the 2nd non-negative hex number (20 digits max, no '0x' in front): "; //Cout.
			cin >> str2; //Cin.
			for(int i = 0; i < str2.length(); ++i){ //Loop for i == 0 to i == length of str2 - 1, incrementing i by 1 each loop.
				if(str2.length() > 20 || (!isalpha(str2[i]) && !isdigit(str2[i]) || int(toupper(str2[i])) > 70)){ //Execute if str2 is not a non-negative hex number with 20 digits max and no '0x' in front.
					cout << "Wrong input" << endl; //Cout.
					break; //Break the loop.
				} else if(i == str2.length() - 1){ //Else if it is the last loop...
					++pass; //Make pass == true by incrementing it by 1.
				}
			}
		} while(!pass); //While pass == false.
		if(str1 == "0" && str2 == "0"){ //Execute if str1 == "0" && str2 == "0".
			cout << endl; //Cout.
			break; //Break the loop.
		}
		for(int i = 0; i < str1.length(); ++i){ //Loop for i == 0 to i == length of str1 - 1, incrementing i by 1 each loop.
			str1[i] = toupper(str1[i]); //Make a letter uppercase.
		}
		for(int i = 0; i < str2.length(); ++i){ //Loop for i == 0 to i == length of str2 - 1, incrementing i by 1 each loop.
			str2[i] = toupper(str2[i]); //Make a letter uppercase.
		}
		string bigger, smaller; //Declare 2 string vars.
		if(str1.length() != str2.length()){ //Execute if str1 and str2 have diff lengths.
			bigger = (str1.length() > str2.length() ? str1 : str2); //Assign the longer string to bigger.
			smaller = (str1.length() < str2.length() ? str1 : str2); //Assign the shorter string to smaller.
			smaller.insert(0, bigger.length() - smaller.length(), '0'); //Insert bigger.length() - smaller.length() amt of '0'(s) at the start of smaller.
		} else if(str1 != str2){ //Else if str1 and str2 have the same length but are diff strings...
			for(int i = 0; i < str1.length(); ++i){ //Loop for i == 0 to i == length of str1 - 1, incrementing i by 1 each loop.
				if(str1[i] != str2[i]){ //Execute if str1[i] != str2[i].
					bigger = (int(str1[i]) > int(str2[i]) ? str1 : str2); //Assign the string containing the larger hex number to bigger.
					smaller = (int(str1[i]) < int(str2[i]) ? str1 : str2); //Assign the string containing the smaller hex number to smaller.
					break; //Break the loop.
				}
			}
		}
		string result = simple_hex_calculator(myOperator, bigger, smaller); //Initialise a string var which holds the calculated outcome.
		if(myOperator == '-' && bigger == str2){ //Execute if myOperator == '-' && bigger == str2.
			for(int i = 0; i < result.length(); ++i){ //Loop for i == 0 to i == length of result - 1, incrementing i by 1 each loop.
				int flipped = 15 - (int(result[i]) - (int(result[i]) < 58 ? 48 : 55)); //Calculation of 2's complement part 1.
				result[i] = char(flipped + (flipped < 10 ? 48 : 55) + (i == result.length() - 1)); //Calculation of 2's complement part 2.
			}
		}
		if(simple_hex_calculator(myOperator, bigger, smaller).length() > 20){ //Execute if length of the calculated outcome > 20.
			cout << "Out of range" << "\n\n"; //Cout.
		} else{ //Else...
			cout << "> " + str1 + " " << myOperator << " " + str2 + " = " + (myOperator == '-' && bigger == str2 && str1 != str2 ? "-" : "") + simple_hex_calculator(myOperator, bigger, smaller); //Cout.
			cout << (myOperator == '-' && bigger == str2 && str1 != str2 ? " (2's complement is " + result + ")" : "") + "\n\n"; //Cout.
		}
	}
	while(1){ //Q5
		vector<unsigned int> prices; //Initialise an unsigned int vector.
		unsigned int input, money, start = 0, numberOfPlots = 0, moneySpent = 0; //Declare 2 and initialise 3 unsigned int vars. 
		while(1){ //Loop while true.
			cout << "Input price of plot #" << prices.size() + 1 << " (Input 0 to end): "; //Cout.
			cin >> input; //Cin.
			if(input > 0 && input <= 1000){ //Execute if input > 0 && input <= 1000.
				prices.push_back(input); //Add input at the end of prices.
			} else{ //Else..
				if(input == 0){ //Execute if input == 0.
					break; //Break the loop.
				}
				cout << "Wrong input" << endl; //Cout.
			}
		}
		if(prices.size() == 0){ //Execute if there are no elements in prices.
			break; //Break the loop.
		}
		do{ //Do...
			cout << "Input how much money you have: "; //Cout.
			cin >> money; //Cin.
			if(money > 1000000){ //Execute if money > 1000000.
				cout << "Wrong input" << endl; //Cout.
			}
		} while(money > 1000000); //While money > 1000000.
		greatest_number_of_plots(prices, money, &start, &numberOfPlots, &moneySpent); //Call the function and pass prices, money, &start, &numberOfPlots, &moneySpent as arguments.
		cout << "\n> The greatest number of continuous plots of land is " << numberOfPlots << ".\n"; //Cout.
		if(start != 0){ //Execute if at least 1 plot of land can be purchased.
			cout << "  - Buy from plot index #" << start << " to #" << start + unsigned __int64(numberOfPlots) - 1 - prices.size() * (start + unsigned __int64(numberOfPlots) - 1 > prices.size()) << ".\n"; //Cout.
		}
		cout << "  - The total price is " << moneySpent << " and the change is " << money - moneySpent << ".\n\n"; //Cout.
	}
	return 0; //Return 0.
}