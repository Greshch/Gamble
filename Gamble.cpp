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

void Gamble::MakePrediction(std::string const& userName, int prediction) {
	this->mUsersResponses.insert({ userName, prediction });
}

std::string const& Gamble::GetWinner() const {
	/*
	* What does it happens?
	* Get winner from temporary vector<pair<string, int>.
	* It was formed(copy) from map.
	* And then this temp vector was sorted in order by more suitable users responses.
	* Finaly this method returned the best response (exactly - name of user 
	* the first element of tmp)
	*/
	std::vector<std::pair<std::string, int>> tmp;
	for (auto const& e : mUsersResponses) {
		tmp.push_back(e);
	}

	int secret = mSecret;
	std::sort(tmp.begin(), tmp.end(), [secret](auto const& left, auto const& right) {
		return abs(left.second - secret) < abs(right.second - secret);
		}
	);
	int bestDif = abs(tmp[0].second - mSecret);
	auto it = std::find_if(mUsersResponses.begin(), mUsersResponses.end(),
		[bestDif, secret](auto const& e) {
			return bestDif == abs(e.second - secret);
		}
		);
	return it->first;
}
