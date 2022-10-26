#include "PrinterGambleResults.h"

void PrinterGambleResults::Print(Gamble const& gamble) const {
	auto const& winers = gamble.GetWinners();
	auto const secret = gamble.GetSecret();
	std::cout << "\n\nSecret's num is : " << secret << std::endl;

	std::cout << "Winners:\n";

	for (auto const& winner : winers) {
		std::cout << "\t" << winner.first << "\t\t" << winner.second << "\n";
	}
}
