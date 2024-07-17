#include <iostream>
#include <vector>
#include <algorithm>

// std::for_each

// std::fill

// std::generate

void test_generate()
{
	std::vector<int> numbers (10);

	std::for_each(
		numbers.begin(),
		numbers.end(),
		[] (int n) {
			std::cout << n << std::endl;
		}
	);

	// für konstante Wert
	std::fill(
		numbers.begin(),
		numbers.end(), 
		123
   );

	std::for_each(
		numbers.begin(),
		numbers.end(),
		[](int n) {
			std::cout << n << std::endl;
		}
	);

	// aufsteigende Werte -- unterschiedliche Werte:
	// 1, 2, 3, 4, 5, ...
	std::generate(
		numbers.begin(),
		numbers.end(),
		[start = 0] () mutable -> int { 
		
			start ++;
			return start;
		}
	);

	// versus

	std::for_each(
		numbers.begin(),
		numbers.end(),
		[start = 10] (int& n) mutable {
			start++;
			n = start;
			// std::cout << n << std::endl;
		}
	);

	std::for_each(
		numbers.begin(),
		numbers.end(),
		[](int n)  {
			std::cout << n << std::endl;
		}
	);

}



