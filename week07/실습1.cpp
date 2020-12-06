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
/* (�ǽ� 1-1) �м���� :
	main�� try������ funcA�Լ��� ȣ��ȴ�.
	funcA������ id�� A�� Test��ü r�� �����Ѵ�. �׸��� funcB�Լ��� ȣ���Ѵ�.
	funcB������ id�� B�� Test��ü r�� �����Ѵ�. �׸��� "Executed in B"�� ����ϰ� funcB�Լ��� ����ȴ�.
	�̶� �Լ��� ����Ǹ鼭 �Լ� ���ο��� ������ id�� B�� r��ü�� �Ҹ�Ǿ���Ѵ�. Test�� destructor�� ����Ǿ� "Destructor execution: B"�� ��µǰ� ��ü�� �Ҹ��Ѵ�.
	funcB�Լ��� ����ǰ� �Լ��� ȣ���ߴ� �����Լ� funcA�� ���ư���. �׸��� "Executed in A"�� ����ϰ� funcA�Լ��� ����ȴ�.
	�̶� �Լ��� ����Ǹ鼭 �Լ� ���ο��� ������ id�� A�� r��ü�� �Ҹ�Ǿ���Ѵ�. Test�� destructor�� ����Ǿ� "Destructor execution: A"�� ��µǰ� ��ü�� �Ҹ��Ѵ�.
	funcA�Լ��� ����ǰ� �Լ��� ȣ���ߴ� �����Լ� main���� ���ư���. �׸��� ���α׷��� ����ȴ�. */

	/* (�ǽ� 1-2) �м���� :
		main�� try������ funcA�Լ��� ȣ��ȴ�.
		funcA������ id�� A�� Test��ü r�� �����Ѵ�. �׸��� funcB�Լ��� ȣ���Ѵ�.
		funcB������ id�� B�� Test��ü r�� �����Ѵ�. �׸��� "Exception from funcB!\n"�� ���ڷ� �ϴ� runtime_error type ���ܰ�ü�� �����Ǿ� ��������.(���ܹ߻�)
		���ܰ� �߻��ϸ� stack unwinding������ ���� catch�� �����ڵ鷯�� �ִ� main���� �����帧�� �ٲ����Ѵ�.

		�ǽ�1 �ڵ�� �������ڸ� stack unwinding�� funcB���� ���ܰ� �߻��ϸ� funcB�� ���� �ڵ带 ���������ʰ� �ٷ� �� �Լ��� ȣ���� funcA�������� ���ܵ����͸� �����ϰ�,
		funcA�Լ������� ���ܸ� ó������ ���ϸ� �Լ��� ȣ���� main�������� ���ܵ����Ͱ� ���޵Ǵ� �����̴�. �̶�, ���ܵ����͸� �����ϸ� ������ �Լ��� ����ȴ�.

		�׷��� funcB�� ���ο� �ִ� ��¹��� ��µ����ʰ� �ٷ� �Լ��� ����ȴ�.
		�Լ��� ����Ǳ� ������ �Լ� ���ο��� ������ id�� B�� r��ü�� �Ҹ�Ǿ���Ѵ�. Test�� destructor�� ����Ǿ� "Destructor execution: B"�� ��µǰ� ��ü�� �Ҹ��Ѵ�.
		�׸��� funcA�� ���� ��¹��� ��µ����ʰ� �ٷ� �Լ��� ����ȴ�.
		�Լ��� ����Ǳ� ������ �Լ� ���ο��� ������ id�� A�� r��ü�� �Ҹ�Ǿ���Ѵ�. Test�� destructor�� ����Ǿ� "Destructor execution: A"�� ��µǰ� ��ü�� �Ҹ��Ѵ�.
		main�� �����ڵ鷯���� "Exception : Exception from funcB!\n"�� ����ϸ� ���ܸ� ó���Ѵ�. �׸��� ���α׷��� ����ȴ�.*/