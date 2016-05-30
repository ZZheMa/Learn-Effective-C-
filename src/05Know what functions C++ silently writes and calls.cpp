// ����05�� �˽�C++ĬĬ��д��������Щ����
// ���������԰���Ϊclass����default���캯����copy���캯����copy assignment���������Լ���������
// Ψ�е���Щ���������ã����ǲŻᱻ��������������

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 1.����������������������non-virtual��
// 2.���class��������һ�����캯������ô�������Ͳ�����Ϊ�䴴��default���캯��
// 3.���class���������вλ����޲ι��캯������ô���������ܻ�Ϊ�䴴��copy���캯��
// 4.�������Զ�������copy assignment��Ϊ�������Զ�������copy���캯��һ��
// 5.�������Զ�����copy assignment�������󣬿��ܾܾ�����ĳ����ֵ���������������
// �ں�reference��Ա����ΪC++������referenceָ��ͬ�Ķ���ֻ�ܳ�ʼ��ʱָ��һ����
// �����ں�const��Ա����Ϊ����const��Ա�ǲ��Ϸ��ġ�
// ����һ��������ཫcopy assignment����Ϊprivate���������ܾ�Ϊ����������һ��copy assignment��
// ��Ϊ���಻�ܴ������class�ɷ֡�

class Student05 {
public:
	Student05(char* name, const string& address, int age)
		: m_age(age), m_pname(name), m_address(address) {
	}

public:
	int m_age;
	char* m_pname;
	string m_address;
};

class Student052 {
public:
	Student052(const char* name, string& address)
		: m_pname(name), m_address(address) {
	}

public:
	const char* m_pname;
	string& m_address;
};

class Empty {
};

int main() {
	Empty e1;  //  ������������default���캯��: Empty(){}
	Empty e2(e1);  // ������������copy���캯��: Empty(const Empty& e){}
	e2 = e1;  // ������������copy assignment�������� Empty& operator=(const Empty& e) {}
						// ����������������������~Empty(){}

	char* test_str = "aaaa";
	//test_str[1] = '1';  // ��������Ϊ"aaaa"Ϊ�ַ��������������˳����洢����ֻʹ��ָ��test_str��ָ������
	char test_arr[] = "abcde";
	test_arr[1] = 'a';  // ��ȷ

	{
	  char name[] = "Jack.";
		//Student05 s1("Jack.", "road1.", 18);  // �����Jack�������˳����洢�������Զ����κ��޸Ķ��Ǵ���ġ�
		Student05 s1(name, "road1.", 18);
		Student05 s2(s1);  // ������Ϊ������copy���캯��
		cout << "s1: " << s1.m_pname << s1.m_address << s1.m_age << endl;  
		cout << "s2: " << s2.m_pname << s2.m_address << s2.m_age << endl;   
		(s2.m_pname)[0] = 'P';
		s2.m_address = "road2.";
		s2.m_age = 81;
		cout << "after:" << endl;
		cout << "s1: " << s1.m_pname << s1.m_address << s1.m_age << endl;   
		cout << "s2: " << s2.m_pname << s2.m_address << s2.m_age << endl;
		// �������Ϊ��
		//  s1: Jack.road1.18
		//  s2: Jack.road1.18
		//  after :
		//  s1 : Pack.road1.18
		//  s2 : Pack.road2.81
		// �õ����ۣ���������������copy���캯����������������ͣ��ͼ򵥵ĸ�ֵ������age��name������ֱ�Ӹ��ƣ�
		// s1��name��ֵ֮���Ի����s2�ı仯����Ϊs1��s2ͬʱָ����һ���ڴ档�����class���ͣ���ô�ͻ����
		// �����copy���캯��������s2��address�ǵ���string���͵�copy���캯������s1��address��Ϊʵ��������
		// ��ʼ���ġ�
	}

	{
		char name[] = "Jack.";
		Student05 s1(name, "road1.", 18);
		Student05 s2(name, "road2.", 19);
		s2 = s1;  // ������Ϊ������copy assignment������
		cout << "s1: " << s1.m_pname << s1.m_address << s1.m_age << endl;
		cout << "s2: " << s2.m_pname << s2.m_address << s2.m_age << endl;
		(s2.m_pname)[0] = 'P';
		s2.m_address = "road2.";
		s2.m_age = 81;
		cout << "after:" << endl;
		cout << "s1: " << s1.m_pname << s1.m_address << s1.m_age << endl;
		cout << "s2: " << s2.m_pname << s2.m_address << s2.m_age << endl;
		// �������Ϊ��
		//  s1: Jack.road1.18
		//  s2: Jack.road1.18
		//  after :
		//  s1 : Pack.road1.18
		//  s2 : Pack.road2.81
	}

	{
		string address = "road";
		const char name[] = "Jack";
		Student052 s1(name, address);
		Student052 s2(name, address);
		// s1 = s2;  // ����������ܾ�������һ��
		// note: compiler has generated 'Student052::operator =' here
		// error C2280: 'Student052 &Student052::operator =(const Student052 &)':
		// attempting to reference a deleted function
	}

	return 0;
}