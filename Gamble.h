#pragma once
#include <string>
#include <vector>
#include <map>

class Gamble {
public:
	Gamble();
	Gamble(int right);
	int GetSecret() const;
	void RandomGenerateTillRightRange(int rightRange);
	void MakePrediction(std::string const& userName, int prediction);
	void SetWinners();
	std::vector<std::pair<std::string, int>> const& GetWinners() const;
	

private:
	int m_secret = 0;
	std::map<std::string, int> m_usersResponses;
	std::vector<std::pair<std::string, int>> m_winers;
	static int const defaultRightRange = 50;
};

