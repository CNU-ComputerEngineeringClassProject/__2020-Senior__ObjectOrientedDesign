#include <vector>
#include <string>
#include <iostream>

class Base1 {
public:
	Base1(int n) : vector_(n, 3) {
		std::cout << "Base1" << std::endl;
	}
	//.....
private:
	std::vector<char> vector_;
};
class Base2 {
public:
	Base2(int n) : vector_(n, 3) {
		std::cout << "Base2" << std::endl;
	}
	//.....
private:
	std::vector<char> vector_;
};
class Derived : public Base1, Base2 {
public:
	Derived(const std::string& str) : Base2(1024), Base1(512)
	{
		i = 0;
		std::cout << "Derived" << std::endl;
	}
	// ...
private:
	std::string str_;
	int i = 0;
};
int main() {
	Derived drv("1");
	return 0;
}

//생성자 호출 순서 Base1 -> Base2 -> Derived
//상속순서 변경 시 Base2 -> Base1 -> Derived