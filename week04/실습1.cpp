#include <string>
#include <iostream>

int main() {
	std::string s;
	std::cout << "문자를 입력하세요(100자 이내)." << std::endl;
	std::cin >> s;
	std::cout << "입력된 문자는 " << s << "입니다." << std::endl;
	return 0;
}

//공백 문자 이전까지의 문자열을 입력받고 s에 저장한 후 출력한다.