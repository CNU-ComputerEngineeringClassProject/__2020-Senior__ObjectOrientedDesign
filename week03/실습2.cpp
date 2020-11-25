//2: 추상화 캡슐화
#include <iostream>
class SetValue
{
	int x, y;

public:
	void setXY(int input_x, int input_y) {
		x = input_x;
		y = input_y;
	}

	void show() {
		std::cout << "X=" << x << ", Y=" << y << std::endl;
	}
};
int main()
{
	SetValue obj;
	obj.setXY(33, 44);
	obj.show();
	system("pause");
	return 0;
}

