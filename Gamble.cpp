#include "Gamble.h"
#include "Simple.h"
#include <algorithm>
#include <cmath>


Gamble::Gamble() : Gamble(defaultRightRange) {
}

Gamble::Gamble(int right) {
	RandomGenerateTillRightRange(right);
}

int Gamble::GetSecret() const {
	return m_secret;
}

void Gamble::RandomGenerateTillRightRange(int rightRange) {
	Simple simple(rightRange);
	m_secret = simple.GetRandomSimpleNum();
}

void Gamble::MakePrediction(std::string const& userName, int prediction) {
	this->m_usersResponses.insert({ userName, prediction });
}

void Gamble::SetWinners() {
	/*
	* What does it happens?
	* Get winner from temporary vector<pair<string, int>.
	* It was formed(copy) from map.
	* And then this temp vector was sorted in order by more suitable users responses.
	* Finaly this method returned the best response (exactly - name of user 
	* the first element of winners)
	*/
	
	for (auto const& e : m_usersResponses) {
		m_winers.push_back(e);
	}

	int secret = m_secret;
	std::sort(m_winers.begin(), m_winers.end(), [secret](auto const& left, auto const& right) {
		return abs(left.second - secret) < abs(right.second - secret);
		}
	);

	int bestDif = abs(m_winers[0].second - secret);
	
	auto newEnd = std::remove_if(m_winers.begin(), m_winers.end(), [secret, bestDif](auto e) {
		return abs(e.second - secret) > bestDif;
		}
	);

	m_winers.erase(newEnd, m_winers.end());
}

std::vector<std::pair<std::string, int>> const& Gamble::GetWinners() const {
	return m_winers;
}
