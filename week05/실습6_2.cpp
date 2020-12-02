//------------Move constructor를 추가할 경우--------------
//위 코드(Copy constructor만 있을 경우)의 문제점은, 새로운 vector 생성에 따라 기존 vector에 저장된 오브젝트들이 새로운 vector로 복사 될 때마다 
//copy constructor가 호출되고 이는 성능 저하를 일으킨다는 점이다(메모리 할당(new)이 반복됨).
//
//이러한 문제를 해결하기 위해, 클래스에 shallow copy를 수행하는 이동 생성자(Move constructor)를 정의해 준다.그러면 새로운 vector로 이동 시, 
//move constructor가 호출되며, 불필요한 메모리 할당을 줄일 수 있다.
//
//이 때, 주의할 점은
//1. move constructor에 noexcept 키워드가 지정되어 있어야 한다.이는 move constructor 수행 도중에 예외가 없다는 것을 컴파일러에 알려주는 것임.
//2. Shallow copy가 일어나는 변수에 nullptr을 넣어줌.
//2. Destructor에서 메모리 할당에 관련된 변수가 nullptr인지 체크.

#include <iostream>
#include <string.h>
#include <vector>

class Animal {

	char* name;
	int age;
public:
	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}
	Animal(const Animal& a) {//Copy constructor with deep copy
		age = a.age;
		name = new char[strlen(a.name) + 1];
		strcpy(name, a.name);
		std::cout << "Copy constructor is invoked!!\n";
	}


	Animal(Animal&& a) noexcept {//Move constructor with Shallow copy
		age = a.age;
		name = a.name;
		std::cout << "Move constructor is invoked!!\n";
		a.name = nullptr;
	}
	~Animal() {
		std::cout << "Destructor!!" << std::endl;
		if (name) delete[] name;
	}
	void changeName(const char* newName) {
		strcpy(name, newName);
	}
	void printAnimal() {
		std::cout << "Name: " << name << " Age: "
			<< age << std::endl;
	}
};

int main() {
	Animal A(10, "Jenny");

	A.printAnimal();

	std::vector<Animal> vec; //Vector for Animal type

	std::cout << "-----1st push-----\n";
	vec.push_back(A);   //Insert an Animal object to vec
	std::cout << "-----2nd push-----\n";
	vec.push_back(A);
	std::cout << "-----3rd push-----\n";
	vec.push_back(A);
	std::cout << "-----4th push-----\n";
	vec.push_back(A);
	std::cout << "-----5th push-----\n";
	vec.push_back(A);

	A.printAnimal();
	vec[0].printAnimal();
	vec[1].printAnimal();
	vec[2].printAnimal();
	vec[3].printAnimal();
	vec[4].printAnimal();

	return 0;
}

