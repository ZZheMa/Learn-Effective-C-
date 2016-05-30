// ����12�� ���ƶ���ʱ��������ÿһ���ɷ�

// ���ｫcopy���캯����copy assignment������ͳ��Ϊcopying������
// 1.Copying����Ӧ��ȷ�����ơ������ڵ����г�Ա��������������base class�ɷ֡���
// 2.��Ҫ������ĳ��copying����ʵ����һ��copying������Ӧ�ý���ͬ���ܷŽ������������У�
// ��������copying������ͬ���á�copy���캯����copy assignment����������֮��Ļ������
// ��û���κ�����ģ�һ�����������µĶ�����һ������������ֵ��

#include <iostream>
#include <string>

class Customer {
public:
	Customer() {
	}
	Customer(const Customer& rhs) : name_(rhs.name_) {
		// name_ = rhs.name_;  // ��Ҫ����д��Ч�����⣬�������⣬д����ʼ���б�
	}
	Customer& operator=(const Customer& rhs) {
		name_ = rhs.name_;
		return *this;
	}

private:
	std::string name_;
};

class PriorityCustomer : public Customer {
public:
	PriorityCustomer() {
	}
	PriorityCustomer(const PriorityCustomer& rhs)
		: Customer(rhs), priority_(rhs.priority_) {  // ����base class��copy���캯��
	}
	PriorityCustomer& operator=(const PriorityCustomer& rhs) {
		Customer::operator=(rhs);  // ��base class�ɷֽ��и�ֵ
		priority_ = rhs.priority_;
		return *this;
	}

private:
	int priority_;
};

int main12() {
	PriorityCustomer priority_customer;
	PriorityCustomer priority_customer2(priority_customer);
	priority_customer = priority_customer2;
	return 0;
}