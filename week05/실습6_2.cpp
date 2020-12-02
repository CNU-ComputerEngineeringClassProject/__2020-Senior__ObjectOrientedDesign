//------------Move constructor�� �߰��� ���--------------
//�� �ڵ�(Copy constructor�� ���� ���)�� ��������, ���ο� vector ������ ���� ���� vector�� ����� ������Ʈ���� ���ο� vector�� ���� �� ������ 
//copy constructor�� ȣ��ǰ� �̴� ���� ���ϸ� ����Ų�ٴ� ���̴�(�޸� �Ҵ�(new)�� �ݺ���).
//
//�̷��� ������ �ذ��ϱ� ����, Ŭ������ shallow copy�� �����ϴ� �̵� ������(Move constructor)�� ������ �ش�.�׷��� ���ο� vector�� �̵� ��, 
//move constructor�� ȣ��Ǹ�, ���ʿ��� �޸� �Ҵ��� ���� �� �ִ�.
//
//�� ��, ������ ����
//1. move constructor�� noexcept Ű���尡 �����Ǿ� �־�� �Ѵ�.�̴� move constructor ���� ���߿� ���ܰ� ���ٴ� ���� �����Ϸ��� �˷��ִ� ����.
//2. Shallow copy�� �Ͼ�� ������ nullptr�� �־���.
//2. Destructor���� �޸� �Ҵ翡 ���õ� ������ nullptr���� üũ.

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

