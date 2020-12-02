//---- - Copy constructor 만 존재할 경우------
//1. Vector에 push_back 할 경우, 제일 뒤에 값(오브젝트)가 추가된다.
//2. 이때, 현재 Vector의 크기가 작을 경우 (Vector에 더 이상 새로운 원소를 넣을 공간이 없을 경우) Vector의 크기는 자동 증가한다.
//2.1 Vector의 크기가 자동 증가하는 방식은 현재의 vector 크기보다 큰 새로운 vector (구현에 따라 다르나 보통 2배씩 증가)를 생성한다.
//2.2 기존 vector의 원소들을 새롭게 생성된 vector로 옮긴다 (복사 또는 이동). 그리고 기존의 vector는 메모리에서 제거.
//3. Vector에 새로운 오브젝트가 추가(push_back)될 때, 오브젝트의 copy constructor가 호출된다. copy constructor가 별도로 정의되어 있지 않으면 컴파일러에서 자동 생성하지만, 만약 default나 parameterized constructor에서 메모리 할당(new) 연산을 할 경우, 프로그래머가 copy constructor를 명시적으로 구현해서 메모리 할당(new)관련 연산을 정의해 주어야 한다.  
//5. 만약 2에서 언급한 것 처럼, 현재 vector의 크기가 작아 새로운 vector를 생산해야 하는 경우 기존 vector에 저장된 오브젝트들을 새롭게 생성된 vector (크기: 기존 * 2)에 복사한다(뒤에서 설명할 move constructor가 따로 정의 되어 있지 않을 경우). 역시, copy constructor가 호출됨.
//std::vector가 구현된 라이브러리에 따라 다른 결과가 나올 수 있다. 


#define _CRT_SECURE_NO_WARNINGS
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

	~Animal() {
		std::cout << "Destructor!!" << std::endl;
		delete[] name;
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
