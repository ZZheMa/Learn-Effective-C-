// ����09�� �����ڹ�������������е���virtual������

#include <iostream>
#include <string>

using namespace std;

// 1.����һ�������ڴ��������ٵ�ʱ�����Ҫִ����һ����Ϊ��
// ��������Ŀ����base class �е�LogTransaction��ΪVirtual��������ֻ��Ҫ��д�����������ô����
// ��ÿ�����ഴ�������ʱ���ܵ��������������Ϊ����Ĺ������������������������������
// ��������˶�̬��ԭ��
// ���������������������С�
// �����ԭ��
// ���߼��Ϸ�����base class�ù��캯����derived class֮ǰִ�С�base class���캯��
// ִ��ʱderived class�ĳ�Ա������û�г�ʼ���������ʱvirtual�������õ���derived 
// class����ģ���ô��ʮ��Σ�գ���Ϊ�ú�������ܿ���Ҫ�õ�derived class����ĳ�Ա������
// C++�������ǲ���������Σ������ġ�
// ����ԭ���ǣ�derived class������base class�����ڼ䣬���������ʱbase class������derived
// class��virtual������������������Ϣ���ᱻ����������Ϊbase class����������˼���ǣ�
// ����derived class�����е�ר���ɷ���δ����ʼ������������ȫ����������������Ϊ
// �����ڡ�derived class���캯����ʼִ��ǰ�����Ϊһ��derived class����
// ����ͬ����������������������base class�������������ͳ�Ϊһ��base class����
class Transaction {
public:
	Transaction() {
		LogTransaction();
	}
	~Transaction() {
		LogTransaction();
	}
	virtual void LogTransaction() {
		cout << "I am base class" << endl;
	}
};

class BuyTransaction : public Transaction {
public:
	BuyTransaction() {
	}
	~BuyTransaction() {
	}
	virtual void LogTransaction() override {
		cout << "I am derived class" << endl;
	}
};

// ��������Ľ����������ʵ�����ø����ഫ�ݲ����ķ����������
class Transaction2 {
public:
	Transaction2(const string log_info) {
		LogTransaction(log_info);  // non-virtual��ʹ�ö�̬
	}
	void LogTransaction(const string log_info) {  // non-virtual ����
		cout << log_info << endl;
	}
};

class BuyTransaction2 : public Transaction2 {
public:
	BuyTransaction2(string info) : Transaction2(CreateLogInfo(info)) {  // ��log��Ϣ��������
	}
	~BuyTransaction2() {
	}
private:
	// ������һ������������������Ա�б��ʼ�����࣬�������ɶ��Ը��ã����Ҹ��������Խ���������Ϊ��
	// ����Ϊstatic������˸ú�������ʱʹ�������໹û�г�ʼ���õĶ�����Ϊstatic�Ǻ���һ������ġ�
	static string CreateLogInfo(string info) {
		return info;
	}
};


int main09() {
	{
		BuyTransaction b;
	}
	// ���Ϊ��
	// I am base class
	// I am base class
	// �����е����Ϊ��
	// I am derived clss
	// I am derived clss
	// ��Ϊ�����˶�̬��������ΪӦ�����������

	{
		BuyTransaction2 b2("I am derived");
	}

	return 0;
}
