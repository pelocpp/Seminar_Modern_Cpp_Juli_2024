// friend

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class FirstClass
{
	friend std::ostream& operator<< (std::ostream& os, const FirstClass& obj);

private:
	int m_x;

public:
	int getValue() const { return m_x; }
};

std::ostream& operator<< (std::ostream& os, const FirstClass& obj)
{
	// os << obj.getValue();
	os << obj.m_x;   // Performanz

	return os;
}

void test_questions()
{
	FirstClass fc;

	std::cout << fc;
}
