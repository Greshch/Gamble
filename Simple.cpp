#include "Simple.h"
Simple::Simple() : Simple(100) {
}

Simple::Simple(int rightRange) {
	GenerateNSimpleNums(rightRange);
}

size_t Simple::GetAmountOfSimplesNums() const {
	return mSimpleNums.size();
}

int Simple::GetSimpleByIndex(int id) const {
	return mSimpleNums[id];
}

bool Simple::IsSimple(int num) const {
	return std::binary_search(mSimpleNums.begin(), mSimpleNums.end(), num);
}

void Simple::GenerateNSimpleNums(int rightRange) {
	for (int i = 0; i < rightRange; i++) {
		mSimpleNums.push_back(i + 1);
	}

	for (int i = 2; i * i < rightRange; i++) {
		for (int j = 0; j < rightRange; j++) {
			if (mSimpleNums[j] != 0 && mSimpleNums[j] != i && mSimpleNums[j] % i == 0) {
				mSimpleNums[j] = 0;
			}
		}
	}

	auto newEnd = std::remove_if(mSimpleNums.begin(), mSimpleNums.end(), [](auto e) {
		return e == 0;
		}
	);

	mSimpleNums.erase(newEnd, mSimpleNums.end());
}
