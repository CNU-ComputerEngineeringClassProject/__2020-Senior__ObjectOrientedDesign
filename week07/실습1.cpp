#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* (실습 1-1) 분석결과 :
	main의 try문에서 funcA함수가 호출된다.
	funcA에서는 id가 A인 Test객체 r을 생성한다. 그리고 funcB함수를 호출한다.
	funcB에서는 id가 B인 Test객체 r을 생성한다. 그리고 "Executed in B"를 출력하고 funcB함수는 종료된다.
	이때 함수가 종료되면서 함수 내부에서 생성된 id가 B인 r객체가 소멸되어야한다. Test의 destructor가 실행되어 "Destructor execution: B"가 출력되고 객체는 소멸한다.
	funcB함수가 종료되고 함수를 호출했던 상위함수 funcA로 돌아간다. 그리고 "Executed in A"를 출력하고 funcA함수는 종료된다.
	이때 함수가 종료되면서 함수 내부에서 생성된 id가 A인 r객체가 소멸되어야한다. Test의 destructor가 실행되어 "Destructor execution: A"가 출력되고 객체는 소멸한다.
	funcA함수가 종료되고 함수를 호출했던 상위함수 main으로 돌아간다. 그리고 프로그램이 종료된다. */

	/* (실습 1-2) 분석결과 :
		main의 try문에서 funcA함수가 호출된다.
		funcA에서는 id가 A인 Test객체 r을 생성한다. 그리고 funcB함수를 호출한다.
		funcB에서는 id가 B인 Test객체 r을 생성한다. 그리고 "Exception from funcB!\n"를 인자로 하는 runtime_error type 예외객체가 생성되어 던져진다.(예외발생)
		예외가 발생하면 stack unwinding과정을 통해 catch문 예외핸들러가 있는 main으로 실행흐름이 바뀌어야한다.

		실습1 코드로 설명하자면 stack unwinding는 funcB에서 예외가 발생하면 funcB의 이후 코드를 실행하지않고 바로 그 함수를 호출한 funcA영역으로 예외데이터를 전달하고,
		funcA함수에서도 예외를 처리하지 못하면 함수를 호출한 main영역으로 예외데이터가 전달되는 과정이다. 이때, 예외데이터를 전달하면 전달한 함수는 종료된다.

		그래서 funcB의 내부에 있는 출력문이 출력되지않고 바로 함수가 종료된다.
		함수가 종료되기 때문에 함수 내부에서 생성된 id가 B인 r객체가 소멸되어야한다. Test의 destructor가 실행되어 "Destructor execution: B"가 출력되고 객체는 소멸한다.
		그리고 funcA도 내부 출력문이 출력되지않고 바로 함수가 종료된다.
		함수가 종료되기 때문에 함수 내부에서 생성된 id가 A인 r객체가 소멸되어야한다. Test의 destructor가 실행되어 "Destructor execution: A"가 출력되고 객체는 소멸한다.
		main의 예외핸들러에서 "Exception : Exception from funcB!\n"를 출력하며 예외를 처리한다. 그리고 프로그램이 종료된다.*/