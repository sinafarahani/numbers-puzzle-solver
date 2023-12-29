#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "state.h"
#include "solver.h"

int main()
{
	int T;
	std::vector<std::thread> solvers;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int m, n;
		std::cin >> m >> n;
		state st(m, n);
		solver s(st);
		auto j = [=]() mutable {s.solve(i+1); };
		solvers.push_back(std::thread{ j });
	}
	auto now = std::chrono::high_resolution_clock::now();
	for (auto& w : solvers) {
		w.join();
	}
	auto next = std::chrono::high_resolution_clock::now();

	auto time = std::chrono::duration<float>(next - now).count();
	std::cout << "calculation took " << time << " seconds" << std::endl;
	system("pause");
}