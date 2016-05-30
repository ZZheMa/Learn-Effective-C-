// ����15: ����Դ���������ṩ��ԭʼ��Դ�ķ���
// ��һ������������ڣ�ǰ��������ᵽʹ��RAII���������������
// ʹ�ö����Զ����ͷ��ڴ棬�����Զ��ļ����������Զ�������Ϊ��
// ����ԭ���Ķ��󶼱���װ���������ˣ����Թ�������Ҫ�ṩ��ԭʼ��Դ�ķ���������

// 1.APIs����Ҫ�����ԭʼ��Դ������ÿһ��RAII classӦ���ṩһ����ȡ����������֮��Դ���İ취��
// 2.��ԭʼ��Դ�ķ��ʿ��ܾ�����ʾת������ʽת����һ�������ʾת���Ƚϰ�ȫ������ʽת���Կͻ��ȽϷ��㡣

#include <iostream>
#include <memory>

class Investment15 {
public:
	Investment15() {
	}
	bool IsTaxFree() const;
};

Investment15* CreateInvestment() {
	return new Investment15;
}

int DaysHeld(const Investment15* pi);

void TestSmartPointer() {
	std::tr1::shared_ptr<Investment15> pinv(CreateInvestment());
	//DaysHeld(pinv);  // ����
	// 3.tr1::shared_ptr��auto_ptr���ṩ��һ��get��Ա����������ִ����ʾת����Ҳ�������᷵������ָ���ڲ���ԭʼָ�롣
	DaysHeld(pinv.get());

	// 4.tr1::shared_ptr��auto_ptrҲ������ָ��ȡֵ������(->��*)��������ʹ�õ�ʱ��RAII����ָ��ת�����ײ�ԭʼָ�롣
	bool b1 = pinv->IsTaxFree();
	bool b2 = (*pinv).IsTaxFree();
}

// 5.����һ���Լ���Ƶ�RAII�࣬����Ҫ�Լ������ʾ����ʽת��������
// ����Font������Ҫ��ȡ���ڲ���ʱ�Զ��ͷš�
class FontHandle {
};

// ��ȡ������
FontHandle getFont();

// �ͷ�������
void ReleaseFont(FontHandle fh);

int ChangeFontSize(FontHandle f, int new_size);

// ����һ��RAII������������
class Font {
public:
	explicit Font(FontHandle fh) 
		: fh_(fh) {
	}
	~Font() {
		ReleaseFont(fh_);
	}
	FontHandle get() const {  // ��ʾת������
		return fh_;
	}
	operator FontHandle() const {  // ��ʽת������
		return fh_;
	}

private:
	FontHandle fh_;  // ԭʼ������Դ
};

int main15() {
	Font f(getFont());
	ChangeFontSize(f, 5);
	ChangeFontSize(f.get(), 5);
	return 0;
}
