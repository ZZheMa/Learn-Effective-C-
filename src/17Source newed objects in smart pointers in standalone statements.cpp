// ����17�� �Զ�������佫newed������������ָ�롣
// 1.�Զ�����佫newed����洢������ָ���ڡ��������������һ���쳣���׳���
// �п��ܵ������Բ������Դй©��
// 2.�ǻ����ԣ��Զ��������Դ������������ָ�����Widget

#include <iostream>
#include <memory>

int GetPriority() {
	return 1;
}

class Widget17 {
};

void ProcessWidget1(std::tr1::shared_ptr<Widget17> pw, int priority);

int main17() {
	// cannot convert argument 1 from 'Widget17 *' to 'std::shared_ptr<Widget17>'
	//ProcessWidget1(new Widget17, GetPriority());

	// �������ַ�ʽ����ͨ�����룬���ǻ�����ڴ�й¶�ķ���
	ProcessWidget1(std::tr1::shared_ptr<Widget17>(new Widget17), GetPriority());
	// ��ΪC++��ͬ��Java��C#�������������������ض��Ĵ�����ɺ��������ͺ��㡣
	// ��C++�ǲ�ȷ���ģ����Կ϶�����new Widget�϶�������tr1::shared_ptr���캯��֮ǰ
	// ����GetPriority������ʱ��λ�ò���ȷ���������������˳��new Widget-->Getpriority-->
	// tr1::shared_ptr�Ĺ��캯���������Getpriority��ʱ�������쳣����ônew������Widget��û��
	// ���ŵ�tr1::shared_ptr�У���ô�Ϳ��ܲ�����Դй©��

	// ���������newһ������ʹ�������ָ��ֿ���
	std::tr1::shared_ptr<Widget17> pw(new Widget17);
	ProcessWidget1(pw, GetPriority());
	
	return 0;
}
