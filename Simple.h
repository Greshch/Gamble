#pragma once
#include <vector>
#include <algorithm>

class Simple {
public:
	Simple();
	Simple(int rightRange);
	size_t GetAmountOfSimplesNums() const;
	int GetSimpleByIndex(int id) const;
	bool IsSimple(int num) const;
	int GetRandomSimpleNum() const;

private:
	std::vector<int> m_simpleNums;
	static const int defaultRightRange = 100;

private:
	void GenerateNSimpleNums(int rightRange);
};

