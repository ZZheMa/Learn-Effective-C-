// ����10�� ��operator=����һ��reference to *this��
// Have assignment operators return a reference to *this.

// ��ֻ�Ǹ����õĽ��飬������鱻���е��������ͺͱ�׼������ṩ�����͹�ͬ���ء�
// �������ͬ��������+=��-=��*=�ȵȡ�
// ���磺
class Widgets {
public:
	Widgets& operator+=(const Widgets& widgets) {
		// ʵ��
		return *this;
	}
	Widgets& operator=(int rhs) {  // �˺���ͬ�����ã���ʱ�˲������˲������Ͳ���Э����
		// ʵ��
		return *this;
	}

};
