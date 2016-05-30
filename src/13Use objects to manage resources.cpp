// ����13: �Զ��������Դ
// 1.Ϊ��ֹ��Դй©����ʹ��RAII���������ڹ��캯���л����Դ���������������ͷ���Դ.
// 2.��������ʹ�õ�RAII classes �ֱ���tr1::shared_ptr��auto_ptr��ǰ��ͨ���ǽϼ�ѡ��
// ��Ϊ��copy��Ϊ�Ƚ�ֱ�ۡ���ѡ��auto_ptr�����ƶ�����ʹ�����������ָ��null.

// 3.TR1(Technical Report1)�����c++��׼��ĵ�һ����չ.

// 4.�Զ��������Դ�������ؼ��뷨��
// (A)RAII(Resource Acquisition Is Initialization)����Դȡ��ʱ�����ǳ�ʼ��ʱ����
// �����Դ�����̷����������ڡ�����ʹ��auto_ptr������ָ����������й������
// (B)�������������������ȷ����Դ���ͷš�Ҳ���Ƕ���һ�������٣��͵������������ͷ���Դ��

#include <iostream>
#include <memory>

class Investment {
public:
	Investment() {
		std::cout << "construct" << std::endl;
	}
	~Investment() {
		std::cout << "destruct" << std::endl;
	}
};

// ���칤���������������󣬷���ָ�룬ָ��Investment,�̳���ϵ�ڵĶ�̬������󣬵�����������ɾ������
Investment* CreateInvestment() {
	return new Investment;
}
                                
// f1���������ı׶��Ǻܶ�����£����������������delete������pinvָ��Ķ���,
// ���������汣�����Դû�б��ͷš�
void f1() {
	Investment* pinv = CreateInvestment();
	{
		// ��������
	}
	delete pinv;  // �ͷ�pinv��ָ����
}

// f2ͨ�������󽻸��������auto_ptr������ʹ���������뿪��������ĳ����������
// ����ʱ���ͷš�
void f2() {
	// ����auto_ptr�����������Զ�ɾ��pinv
	std::auto_ptr<Investment> pinv(CreateInvestment());
	// auto_ptrΪ�˷�ֹһ������ɾ��һ�����ϣ��и���Ѱ�������ʣ�����ͨ��copy���캯��
	// ��copy assignment�������������ǣ����Ǿͻ���null�����������õ�ָ�뽫ȡ����Դ��
  // Ψһӵ��Ȩ�����ĵײ��������ǣ���auto_ptr�������Դ�������û��һ�����ϵ�auto_ptr
	// ͬʱָ������
	std::auto_ptr<Investment> pinv2(pinv);  // ����pinv2ָ�����pinvΪnull
	pinv = pinv2;  // ����pinvָ�����pinv2����Ϊnull��
}

// f3ʹ��shared_ptr���������
// RCSP(reference-counting smart pointer)�����ü������ǻ�ָ�룬����׷�ٹ��ж��ٶ���ָ��
// ĳ����Դ����������ָ����ʱ�Զ�ɾ������Դ������Ϊ�������������ա��������޷�����
// ��״���ã�cycles of refrence������������ʵ�Ѿ�û��ʹ�õĶ���ָ����˺�����
// ����ʹ�á�״̬����
void f3() {
	// ����shared_ptr���������Զ�ɾ��pinv��
	std::tr1::shared_ptr<Investment> pinv(CreateInvestment());
	std::tr1::shared_ptr<Investment> pinv2(pinv);  // pinv��pinv2ָ��ͬһ������
	pinv = pinv2;  // ͬ�ϣ����κθı�
}

// ע�� auto_ptr��shared_ptr��������������������delete������delete[],Ҳ����˵�ڶ�̬
// ������õ�array����ʹ�������������õġ�

int main13() {
	f1();  // �����construct destruct
	f2();  // �����construct destruct
	f3();  // �����construct destruct
	return 0;
}
