// ����16�� �ɶ�ʹ��new��deleteʱҪ������ͬ����ʽ
// 1.�����new���ʽ��ʹ��[],��������Ӧ��delete���ʽ��ʹ��[]�����
// ��new���ʽ�в�ʹ��[]��һ����Ҫ����Ӧ��delete���ʽ��ʹ��[]��
// 2.newһ���������������Ϊ����һ�����ڴ汻����������ڶ�����Դ��ڴ����һ��
// �������캯�������á�
// 3.deleteһ������Ҳ����������Ϊ����һ������Դ��ڴ����һ�������������������ã�
// �ڶ������ڴ汻�ͷš�

#include <iostream>
#include <string>

class MyString16 {
public:
	MyString16() {
		count_++;
		std::cout << "construct" << count_ << std::endl;
	}
	~MyString16() {
		std::cout << "destruct" << count_ << std::endl;
		count_--;
	}

public:
	static int count_;
};

int MyString16::count_ = 0;

int main16() {
	MyString16* ptr1 = new MyString16;
	MyString16* ptr2 = new MyString16[10];
	delete ptr1;  // ɾ��һ������
	delete [] ptr2;  // ɾ��һ����������

	// �����÷���δ֪���������ϵͳ����
	MyString16* ptr3 = new MyString16;
	MyString16* ptr4 = new MyString16[10];
	delete ptr4;
	delete [] ptr3;

	return 0;
}