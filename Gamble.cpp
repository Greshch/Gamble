#include "Gamble.h"
#include "Simple.h"
#include <algorithm>
#include <cmath>


Gamble::Gamble() : Gamble(50) {
}

Gamble::Gamble(int right) {
	RandomGenerateTillRightRange(right);
}

int Gamble::GetSecret() const {
	return mSecret;
}

void Gamble::RandomGenerateTillRightRange(int rightRange) {
	Simple simple(rightRange);
	mSecret = simple.GetRandomSimpleNum();
}

void Gamble::MakePrediction(std::string userName, int prediction) {
	this->mUsersResponses.insert({ userName, prediction });
}

std::string Gamble::GetWinner() {
	std::vector<std::pair<std::string, int>> tmp;
	for (auto const& e : mUsersResponses) {
		tmp.push_back(e);
	}

	int secret = mSecret;
	std::sort(tmp.begin(), tmp.end(), [secret](auto const& left, auto const& right) {
		return abs(left.second - secret) < abs(right.second - secret);
		}
	);
	return tmp[0].first;
}
