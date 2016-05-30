// ����02�� ������const��enum��inline �滻#define
// �����ܵ�ʹ�ñ�����������Ԥ������

#include <iostream>

// 1. ����classר����������const����define��
//   A. ������#define����Ϊdefine������������scope��
//   B. ��const��static���Ρ���const��Ϊ���ܱ��ı䣬��static��Ϊ���еĶ�������һ������
//   C. ��class��const��static���ε�int���������⴦�����������и�ֵ��������ֻ�����������Ƕ��壬
//      ����ȡֵʹ�ã���ȡ��ַʱ����û���Ҫ�ⲿ���塣
//   D. �������г����ķ����ǣ������涨�壬������������

// 2. ��enum����define
//   ���ۻ����� һ��ö�����͵���ֵ���Գ䵱int���ͱ�ʹ��

// 3. �������ƺ����ĺ꣬��inline����������#define

class Circle {
private:
	enum {
		Num = 5  // ö�����ͱ�Ĭ��Ϊint����
	};

public:
	static const int A = 5;  // ��ȷ����ֻ�ǳ�������ʽ��ֻ��ȡ��ַʱc++�������Ż���������ڴ�
  double a = 5;  // ��ȷ��˵��c++ �г�Ա��������ֱ�Ӹ�ֵ
	//static const double Pi = 3.14; //���� 
	//����:: a static data member with an in-class initializer must have non-volatile const integral type
	static const double Pi;  // ��������
	int array[Num];  // ��������
};

const double Circle::Pi = 3.14;  // ���峣��

int main02() {
	Circle *c1 = new Circle();
	std::cout << Circle::A << c1->A << std::endl;  // ��ȷ�����Է���
	std::cout << &Circle::A << std::endl;  // ��ȷ
	std::cout << c1->a << std::endl;  // ��ȷ
	std::cout << c1->Pi << std::endl;  //��ȷ
	std::cout << Circle::Pi << std::endl;  // ��ȷ
	//c1->Pi = c1->Pi + 1;  // ����
	return 0;
}