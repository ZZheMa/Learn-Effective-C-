// ����06�� ������ʹ�ñ������Զ����ɵĺ������͸���ȷ�ܾ���

#include <iostream>

// ��ֹ�������Զ�����copy���캯����copy assignment�����������ַ�����
// 1.����������������Ϊprivate�����Ҳ�ʵ�����ǡ�������˵����������������ڻ�õ�һ�����Ӵ���
// 2.ר�����һ����ֹcopying������base class��Ȼ��̳����������ڱ����ڼ���ܷ��ִ���

class HomeForSale1 {
public:
	HomeForSale1() {};
	~HomeForSale1() {};

private:
	HomeForSale1(const HomeForSale1&);
	HomeForSale1& operator=(const HomeForSale1&);
};

class Uncopyable {
protected:
	Uncopyable() {};  // ����derive�Ķ����������
	~Uncopyable() {};

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale2 : public Uncopyable {
	// ��class����˽����������������
};

int main06() {
	HomeForSale1 h1;
	//HomeForSale1 h2(h1);  // ����
	//HomeForSale1 h2 = h1; // ����

	HomeForSale2 h3;
	//HomeForSale2 h4(h3);  // ����cannot access private member declared in class 'Uncopyable'
  //HomeForSale2 h4 = h3;  // ����
	return 0;
}