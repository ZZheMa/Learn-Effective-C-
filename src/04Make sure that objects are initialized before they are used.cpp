// ����04�� ȷ������ʹ��ǰ�ѱ���ʼ��

#include <iostream>
#include <string>
#include <list>

using std::string;
using std::cout;
using std::endl;
using std::list;

class Point04 {
public: 
	int a;
	int b;
};

// 1.��Ҫ�����˸�ֵ(assignment)�ͳ�ʼ��(initialization)
// C++�涨�������Ա�����ĳ�ʼ�����������ڽ��빹�캯������֮ǰ��
// ��������Ϊ�û��Զ������͵ĳ�Ա�����Զ�����default���캯����
// Ҳ����˵�ڽ���ABEntry���캯������ʱ��֮ǰ����Щ�Զ������͵ĳ�Ա��default���캯��
// �Ѿ������á����Ƕ����������ͣ����ܱ�֤һ���ڸ�ֵ����֮ǰ��ó�ֵ��
class PhoneNumber {
};

class ABEntry {
public:
	ABEntry(string& name, string& address, list<PhoneNumber> phones);

private:
	string m_name;
	string m_address;
	list<PhoneNumber> m_phones;
	int m_num_consulted; 
};

// ��ֵ
// �ȵ���default���캯����Ȼ�����copy assignment������
// ABEntry::ABEntry(string& name, string& address, list<PhoneNumber> phones) {
//   m_name = name;  // ��Щ���Ǹ�ֵ�����ǶԳ�Ա�����ĳ�ʼ������
//   m_address = address;  // �����������������ȵ���default���캯��Ϊm_name,m_address,m_phones
//   m_phones = phones;  // ���ֵ��Ȼ���������뺯�����ٶ����Ǹ�����ֵ��
// }

// ��ʼ�����ó�Ա�б��ʼ����
// ֻ����һ��copy���캯��
// �������Ч�ʸ��ߣ���Ϊ��ʼ������Ը�����Ա�������ʵ��,
// ����ȥ��Ϊ����Ա�����Ĺ��캯����ʵ��,���ù��캯��ʱ�Ѿ��Ը�������������copy��ʼ��
// ���������������籾���е�int���ͣ���ֵ�ͳ�ʼ���ɱ���ͬ��Ϊ��һ���ԣ�Ҳ�ڳ�Ա�б��ʼ��
// ���Ƕ����������ͣ������Ϊconst����reference����ô���ǾͲ��ܱ���ֵ����Ҫ��ֵ������Ҫ�ó�ʼ���б�
ABEntry::ABEntry(string& name, string& address, list<PhoneNumber> phones)
		: m_name(name),  // ��Щ���ǳ�ʼ�������캯�����岻�����κζ���
			m_address(address),  // m_name��nameΪ��ֵ���п������죬�ȵ�
			m_phones(phones),
			m_num_consulted(0) {  
}                        

// 2.����ʹ�ó�Ա�б���г�ʼ������������ʱ����Ա�Ҫ���������ȸ�ֵ����Ч

// 3.C++����ʮ�̶ֹ��ĳ�Ա��ʼ�����򣬻������ĳ�ʼ������Ա�������������Ĵ��򱻳�ʼ����

// 4.Ϊ�������Ͷ�������ֹ���ʼ������ΪC++����֤��ʼ�����ǡ�

// 5.Ϊ���������뵥Ԫֻ��ʼ���������⣬����local static�����滻non-local

int main04() {
	// Point04 p1;
	// cout << p1.a << "&" << endl;  // ���� ��uninitialized local variable 'p1' used
 
	return 0;
}