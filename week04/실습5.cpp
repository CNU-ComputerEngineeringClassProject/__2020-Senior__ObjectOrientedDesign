#include <iostream>
void increment(int& x)
{
	++x;
}
int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x);

	std::cout << " After increment: " << x << std::endl;
	return 0;
}

//결과
/*
 * Before increment: 55
 * After increment: 56
 */