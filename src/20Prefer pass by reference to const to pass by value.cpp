// ����20�� ����pass-by-reference-to-const�滻pass-by-value
// 1.������pass-by-reference-to-const�滻pass-by-value��ǰ��ͨ���Ƚϸ�Ч���ɱ����и����⡣
// 2.���Ϲ��򲢲��������������ͣ��Լ�STL�ĵ������ͺ������󡣶����Ƕ��ԣ�pass-by-value�����Ƚ�ǡ����

#include <iostream>
#include <string>

// ȱʡ״����C++��ֵ��ʽ���ݶ���ʱ�����ݵ��Ƕ���ĸ�����ϵ��copy���캯������������ʹ����ֵ����
// ��Ϊ��ʱ������

class Face20 {
public:
	Face20(const Face20& f) {
		std::cout << "I am Face" << std::endl;
	}
	Face20() {
	}
};

class Person20 {
public: 
	Person20(const Person20& p)
		: face(p.face) { 
		std::cout << "I am Person" << std::endl;
	}
	Person20() {
	}
	virtual void Name() const {
		std::cout << "My name is Person20" << std::endl;
	}

private:
	Face20 face;
};

class Student20 : public Person20 {
public:
	Student20() {
	}
	Student20(const Student20& s) {
		std::cout << "I am Student" << std::endl;
	}
	virtual void Name() const {
		std::cout << "My name is Student20" << std::endl;
	}
};

// ������ֵ���ݵĺ�ʱ��
// I am Student
// I am Face
// I am Person
// ��ֵ���ݲ����Ĵ��ݳɱ����Ƕ�ε��ù��캯������������������
void TestStudent20(Student20 s) {
}

// ������ֵ���ݵ��и���
// My name is Person20
// ��ֵ����ʱ������p�ᱻ�����һ��Person20�Ķ���pԭ�����ػ���Ϣ���и���¶�̬�����γɡ�
void TestStudent202(Person20 p) {
	p.Name();
}

// �������ô��ݵ������ԣ�����ʵ�ֶ�̬
// My name is Student20
void TestStudent203(const Person20& p) {
	p.Name();
}

int main21() {
	Student20 s;
	TestStudent20(s);
	TestStudent202(s);
	TestStudent203(s);
	//���Ϊ��
	// I am Student
	// I am Face
	// I am Person
	// ------------
	// My name is Person20
	// ------------
	// My name is Student20

	return 0;
}
