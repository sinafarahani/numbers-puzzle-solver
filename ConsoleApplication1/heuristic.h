#pragma once

#include "state.h"

class heuristic {
public:
	heuristic(state s);
	int getVal() const;
private:
	int val;
	state s;
};