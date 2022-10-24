#pragma once

class Gamble {
private:
	int secret = 0;

public:
	Gamble();
	Gamble(int right);
	int GetSecret() const;
	void RandomGenerateTillRightRange(int rightRange);
};

