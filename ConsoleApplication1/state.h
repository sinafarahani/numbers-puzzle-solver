#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class state {
public:
	state(int M, int N);
	bool operator==(state& s);
	bool operator==(const state& s) const;
	std::vector<state> getNextStates();
	bool solved() const;
	int getM() const;
	int getN() const;
	std::vector<int> getNumOrder() const;
private:
	int M;
	int N;
	std::vector<int> numOrder;
};