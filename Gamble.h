#pragma once
#include <string>
#include <map>

class Gamble {
public:
	Gamble();
	Gamble(int right);
	int GetSecret() const;
	void RandomGenerateTillRightRange(int rightRange);
	void MakePrediction(std::string const& userName, int prediction);
	std::string const& GetWinner()const;

private:
	int m_secret = 0;
	std::map<std::string, int> mUsersResponses;
	static int const defaultRightRange = 50;
};

