#pragma once

#include <algorithm>

#include "state.h"
#include "node.h"

class solver {
public:
	solver(const state s);
	void solve(int i);

private:
	const state s;
	std::vector<node> frontier;
	std::vector<node> checked_nodes;
};