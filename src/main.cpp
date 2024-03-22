﻿// cNPM.cpp : Defines the entry point for the application.
//

#include "../include/main.h"
#include "../include/fib.h"

#include <chrono>

int main()
{
	fmt::println("{}", "where if the fibonacci sequence do you want to be");
	std::string amount;
	std::cin >> amount;
	const auto start = std::chrono::high_resolution_clock::now();
	fmt::println("{}", fibonacci::fibCal(std::stoi(amount)));
	const auto stop = std::chrono::high_resolution_clock::now();
	const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
	return 0;
}
