#include "Simple.h"
#include <ctime>

Simple::Simple() : Simple(defaultRightRange) {
}

Simple::Simple(int rightRange) {
	GenerateNSimpleNums(rightRange);
}

size_t Simple::GetAmountOfSimplesNums() const {
	return m_simpleNums.size();
}

int Simple::GetSimpleByIndex(int id) const {
	return m_simpleNums[id];
}

bool Simple::IsSimple(int num) const {
	return std::binary_search(m_simpleNums.begin(), m_simpleNums.end(), num);
}

int Simple::GetRandomSimpleNum() const {
	srand(time(nullptr));
	int randIndex = rand() % GetAmountOfSimplesNums();
	return GetSimpleByIndex(randIndex);
}

void Simple::GenerateNSimpleNums(int rightRange) {
	for (int i = 0; i < rightRange; i++) {
		m_simpleNums.push_back(i + 1);
	}

	for (int i = 2; i * i < rightRange; i++) {
		for (int j = 0; j < rightRange; j++) {
			if (m_simpleNums[j] != 0 && m_simpleNums[j] != i && m_simpleNums[j] % i == 0) {
				m_simpleNums[j] = 0;
			}
		}
	}

	auto newEnd = std::remove_if(m_simpleNums.begin(), m_simpleNums.end(), [](auto e) {
		return e == 0;
		}
	);

	m_simpleNums.erase(newEnd, m_simpleNums.end());
}
