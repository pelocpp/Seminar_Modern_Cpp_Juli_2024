#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

template <typename T, typename... U>
	// requires std::integral<T> && (std::integral<U> && ...)
		requires (std::same_as<T, U> && ...)
void printer(std::ostream& os, T arg, U... args) {
	std::vector<T> data{ arg, args... };

	int index = 0;
	size_t length = data.size();

	std::for_each(data.begin(), data.end(), [&](auto item) {
		if (index == 0) {
			os << item;
		}
		else {
			os << ", " << item;
		}
		++index;
		});
}

void test() {
	std::ostringstream oss;
	std::string expected { "1" };

	printer(oss, 1, 2, 3);

}

//TEST(concepts, printer_single_arguments) {
//	std::ostringstream oss;
//	std::string expected{ "1" };
//
//	printer(oss, 1);
//
//	EXPECT_EQ(oss.str(), expected);
//}