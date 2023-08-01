#pragma once
#include <random>


class Random {
public:
	Random() : rnGen(seed()) {
	}

	int getIntInRange(int min, int max) {
		return std::uniform_int_distribution<int>(min, max - 1)(rnGen);
	}

	double getDoubleInRange(double min, double max) {
		return std::uniform_real_distribution<double>(min, max)(rnGen);
	}

	float getFloatInRange(float min, float max) {
		return std::uniform_real_distribution<float>(min, max)(rnGen);
	}
private:
	std::random_device seed;
	std::default_random_engine rnGen;
};