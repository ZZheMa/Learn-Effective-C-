// ����18�� �ýӿ����ױ���ȷʹ�ã����ױ�����
// 1.�õĽӿں����ױ�ʹ�ã������ױ����á�Ӧ�������еĽӿ���Ŭ�������Щ���ʡ�
// 2.���ٽ���ȷʹ�á��İ취�����ӿڵ�һ���ԣ��Լ����������͵���Ϊ���ݡ�
// 3.����ֹ���á��İ취�������������͡����������ϵĲ��������ݶ���ֵ���Լ������ͻ�����Դ�������Ρ�
// 4.tr1::shared_ptr֧�ֶ�����ɾ��������ɷ���DLL���⣬�ɱ������Զ������������

#include <iostream>
#include <memory>

struct Day {
	explicit Day(int d)
		: val(d) {
	}
	int val;
};

struct Year {
	explicit Year(int y)
		: val(y) {
	}
	int val;
};

class Month {
public:
	static Month Jan() {
		return Month(1);  // ����������Ч�·�
	}
	static Month Feb() {
		return Month(2);
	}

private:
	explicit Month(int m);  // ��ֹ�����µ��·�
};

class Date {
public:
	Date(const Month& m, const Day& d, const Year& y) {

	}
};

int main18() {
	// �����ϣ�����ͻ���ͼʹ��ĳ���ӿڶ�ȴû�л����Ԥ�ڵ���Ϊ���������Ͳ���ͨ�����룬
	// �������ͨ���˱��룬������Ϊ���Ǹÿͻ���Ҫ�ġ�
	Date d(Month::Feb(), Day(12), Year(2012));
	// Date d(Month::Feb(), Day(12.1), Year(2012));  // ���벻ͨ����������explicit��������ʽת������
	// Date d2(2, Day(2), Year(12));  // ���벻ͨ��

	return 0;
}
