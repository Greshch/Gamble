#pragma once
#include <string>
#include <map>

class Gamble {
private:
	int mSecret = 0;
	std::map<std::string, int> mUsersResponses;


public:
	Gamble();
	Gamble(int right);
	int GetSecret() const;
	void RandomGenerateTillRightRange(int rightRange);
	void MakePrediction(std::string userName, int prediction);
	std::string GetWinner();
};

