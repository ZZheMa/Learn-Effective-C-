// ����07�� Ϊ��̬��������virtual��������

// 1.C++��ȷָ���������������һ������ָ��ɾ�������û������һ��non-virtual����������
// ����δ�ж��塣ʵ��ִ��ʱͨ���������Ƕ����derived�ɷ�û�б����١�Ҳ���ǲ�������
// ����ĳ�Ա��������û�����٣����������������Ҳδ��ִ��������������ɷ�ͨ���ᱻ���٣�
// �����һ������ġ��ֲ����١�����

// 2.����������������ʽ�ǣ�������������Ǹ�������������Ȼ����ÿһ��base class��������

// 3.polymorphic(����̬���ʵ�)base classesӦ������һ��virtual�������������class
// �����κ�virtual����������Ӧ��ӵ��һ��virtual���������������Ļ�������Ŀ����Ϊ��
// ����ͨ������ӿڴ���derived class����

// 4.һ��������Ŀ�����������Ϊ����ʹ�ã�����Ϊ�˾߱���̬�ԣ��Ͳ�Ӧ������Ϊvirtual
// ����������

// 5.������������������һ����;�ǣ�������һ���������ʱ��û����Ҫ����Ϊvirtual�ĺ�����
// ���Խ�������������virtual

#include <iostream>
#include <string>

using namespace std;

class AbstractClass {
	AbstractClass();
	virtual ~AbstractClass() = 0;
};

class Base06 {
public:
	Base06() {
		cout << "Base06 construct" << endl;
	}

	virtual ~Base06() {
		cout << "Base06 destruct" << endl;
	}

	void IntroduceNoVirtual() {
		cout << "I am Base06" << endl;
	}

	virtual void IntroduceWithVirtual() {
		cout << "I am Base06" << endl;
	}
};

class Derived061 : public Base06 {
public:
	Derived061() {
		cout << "Derived061 construct" << endl;
	}

	~Derived061() {
		cout << "Derived061 destruct" << endl;
	}

	void IntroduceNoVirtual() {
		cout << "I am Derived061" << endl;
	}

	virtual void IntroduceWithVirtual() {
		cout << "I am Derived061" << endl;
	}
};

class Derived062 : public Derived061 {
public:
	Derived062() {
		cout << "Derived062 construct" << endl;
	}

	~Derived062() {
		cout << "Derived062 destruct" << endl;
	}

	void IntroduceNoVirtual() {
		cout << "I am Derived062" << endl;
	}

	virtual void IntroduceWithVirtual() {
		cout << "I am Derived062" << endl;
	}
};

int main07() {
	Base06* b1 = new Derived062();
	b1->IntroduceNoVirtual();  // �����I am Base06
	b1->IntroduceWithVirtual();  // �����I am Derived062
	delete b1;
	//Base06��������������ʱ��������Ϊ��
	//Base06 construct
	//Derived061 construct
	//Derived062 construct
	//Base06 destruct
 
	//Base06ʹ������������ʱ��������Ϊ��
	//Base06 construct
	//Derived061 construct
	//Derived062 construct
	//Derived062 destruct
	//Derived061 destruct
	//Base06 destruct
	//����ʱ˳��Ϊ��û���������ж��ӡ�����˳��Ϊ�׷����ͺڷ��ˡ�
	
	return 0;
}
