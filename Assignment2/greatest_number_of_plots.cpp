#include "greatest_number_of_plots.h"

void greatest_number_of_plots(vector<unsigned int> prices, const unsigned int money, unsigned int *startOffset, unsigned int *numberOfPlots, unsigned int *moneySpent){
	for(int startIndex = 0; startIndex < prices.size(); ++startIndex){ //Loop for startIndex == 0 to startIndex == number of elements in prices - 1, incrementing startIndex by 1 each loop.
		unsigned int count = 0, myMoney = money; //Initialise 2 unsigned int vars.
		for(int i = startIndex; myMoney >= prices[i]; i += (i == prices.size() - 1 ? -(int(prices.size()) - 1) : 1)){ //Loop till myMoney >= price of the current plot of land, starting from i == startIndex and updating startIndex each loop in a way that allows for wrap around.
			if(i == startIndex && myMoney != money){ //Execute if i == startIndex && some money has been spent.
				break; //Break the loop to prevent repeated purchases.
			}
			myMoney -= prices[i]; //Reduce myMoney by the price of the current plot of land.
			count++; //Increment count by 1.
		}
		if(count > *numberOfPlots){ //Execute if the new calculated number of plots > the current greatest number of plots.
			*numberOfPlots = count; //Assign the new calculated number of plots to *numberOfPlots.
			*startOffset = startIndex + 1; //Calculate the index of the plot of land to start from.
			*moneySpent = money - myMoney; //Calculate the money spent.
		}
	}
}