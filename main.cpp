#include "Gamble.h"


int main() {
	Gamble gamble;
	int guess = gamble.GetSecret();
	gamble.MakePrediction("First", 7);
	gamble.MakePrediction("Second", 11);
	gamble.MakePrediction("Third", 13);
	auto winner = gamble.GetWinner();
	return 0;
}