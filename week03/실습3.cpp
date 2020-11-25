//3: 오버로딩
//C: 에러남, C에서는 함수 오버로딩을 지원하지 않기 때문에 컴파일되지 않는다. 변수나 함수명이 동일하면 안된다.
//C++: 에러안남
#include <stdio.h>
void print(int var)
{
	printf("Integer number: %d \n", var);
}
void print(float var)
{
	printf("Float number: %f \n", var);
}
void print(int var1, float var2)
{
	printf("Integer number: %d \n", var1);
	printf(" and float number: %f", var2);
}
int main()
{
	int a = 7;
	float b = 9;
	print(a);
	print(b);
	print(a, b);
	return 0;
}
