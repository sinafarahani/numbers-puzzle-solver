#include "state.h"

state::state(int M, int N)
	:
	M(M),
	N(N)
{
	for (int i = 0; i < M * N; i++) {
		int a;
		std::cin >> a;
		numOrder.push_back(a);
	}
}

bool state::operator==(state& s)
{
	return this->numOrder == s.numOrder;
}

bool state::operator==(const state& s) const
{
	return this->numOrder == s.numOrder;
}

std::vector<state> state::getNextStates()
{
	std::pair<int, int> MPT;
	for (int i = 0; i < numOrder.size(); i++) {
		if (numOrder[i] == 0) {
			MPT = std::make_pair(i / N, i % N);
			break;
		}
	}
	state s2 = *this;
	std::vector<state> nextStates;
	for(int i = 0; i < numOrder.size(); i++){
		if ((std::abs((i / N) - MPT.first) == 1 && (i % N) == MPT.second) || (std::abs((i % N) - MPT.second) == 1 && (i / N) == MPT.first)) {
			std::iter_swap(std::find(s2.numOrder.begin(), s2.numOrder.end(), 0), s2.numOrder.begin() + i);
			nextStates.push_back(s2);
			s2 = *this;
		}
	}
	return nextStates;
}

bool state::solved() const
{
	std::vector<int> solved;
	for (int i = 1; i < M * N; i++) {
		solved.push_back(i);
	}
	solved.push_back(0);
	return numOrder == solved;
}

int state::getM() const
{
	return M;
}

int state::getN() const
{
	return N;
}

std::vector<int> state::getNumOrder() const
{
	return numOrder;
}
