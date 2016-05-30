// ����21�� ���뷵�ض���ʱ�������뷵����reference
// ����Ҫ����pointer��referenceָ��һ��local stack���󣬻᷵��referenceָ��
// һ��heap-allocated���󣬻򷵻�pointer��referenceָ��һ��local static����
// ���п���ͬʱ��Ҫ��������Ķ�������4�Ѿ�Ϊ���ڵ��̻߳����к�����reference
// ָ��һ��local static�����ṩ��һ�����ʵ����

#include <iostream>

// ��������20�Ľ���pass by referenceЧ�ʸߣ������˹��캯�����µ�Ч�����⡣
// �����к�������ʱ��Ҳ��pass by reference�����Ч�ʣ��ͺܿ��ܳ������⡣

class Rational21 {
public:
	int a;
};

// ���ض���������һ�� ���ض���ʱ��ָ���������ָ��local����
// ������������û�б��⹹�캯���������������ص���result��һ��local�������ں����˳�
// ǰ�ͱ������ˡ����ص���һ���к�
// ��ʵ��������ǣ��κκ����������һ��referenceָ��local���󣬶���ʧ�ܡ������������
// ָ��ָ��һ��local���󣬺��Ҳ��һ����
const Rational21& operator* (const Rational21& r1, const Rational21& r2) {
	Rational21 result;
	return result;
}

// ���ض���������������ض���ʱ��ָ���������ָ��heap����
// �����˹��캯�����õĴ��ۣ�����new �����Ķ���˭��delete��
// �������x + y + z�������Ĵ��룬����������������operator+��new������������
// ����û��ʲô����İ취�����reference�������ص��Ǹ�ָ�롣
const Rational21& operator+ (const Rational21& r1, const Rational21& r2) {
	Rational21 *r = new Rational21();
	return *r;
}

// ���ض������������� ���ض���ʱ��ָ���������ָ��static����
// ͬ�������˹��캯���Ĵ��ۣ�����static�ǹ���������ں�����Ҳ��������
// ��ε�����������������Ķ���ͬһ��static���������̵߳İ�ȫ���������ǡ�
const Rational21& operator-(const Rational21& r1, const Rational21& r2) {
	static Rational21 result;
	// ��r2��һЩ����
	return result;
}
// ���ܵ���������������Ĵ���
bool operator== (const Rational21& r1, const Rational21& r2) {
	if (r1.a == r2.a) {
		return true;
	}
	return false;
}
// ���������Զ����true����Ϊ����������operator-���������η��ص���ͬһ��������
// ���صĶ���static���������ı�����ǰһ�μ����һ������ᱻ��һ�ε��ðѽ�������
// ����Ϊ���ص�����������==�Ƚϵľ�������ָ���ͬһ����������Ƿ��ص���ֱ�ӵ�
// ������ô������ǶԵġ�
bool Terrible() {
	Rational21 a, b, c, d;
	if ((a - b) == (c - d)) {
		return true;
	}
	return false;
}

// ������ʽ�Ĵ������,��ȻҪ��������ɱ��������ɱ�
inline const Rational21 operator/ (const Rational21& r1, const Rational21& r2) {
	return Rational21();
}
