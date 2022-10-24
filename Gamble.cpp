#include "Gamble.h"
#include "Simple.h"


Gamble::Gamble() : Gamble(50) {
}

Gamble::Gamble(int right) {
	RandomGenerateTillRightRange(right);
}

int Gamble::GetSecret() const {
	return secret;
}

void Gamble::RandomGenerateTillRightRange(int rightRange) {
	Simple simple(rightRange);
	secret = simple.GetRandomSimpleNum();
}
