#include "heuristic.h"

heuristic::heuristic(state s)
	:
	s(s)
{
	val = 0;
	if (!s.solved()) {
		const auto numbers = s.getNumOrder();
		for (int i = 0; i < numbers.size(); i++) {
			if(numbers[i] != 0)
				val += std::abs((numbers[i] - 1) / s.getN() - i / s.getN()) + std::abs((numbers[i] - 1) % s.getN() - i % s.getN());
		}
	}
}

int heuristic::getVal() const
{
	return val;
}
