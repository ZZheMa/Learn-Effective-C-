// ����11�� ��operator=�д������Ҹ�ֵ��
// 1.ȷ���κκ����������һ�����ϵĶ��󣬶����ж��������ͬһ������ʱ������Ϊ��Ȼ��ȷ��
// 2.ȷ�����������Ҹ�ֵʱoperator=��������Ϊ�����м��������Ƚϡ���Դ���󡱺͡�Ŀ����󡱵ĵ�ַ��
// ���İ��ŵ����˳���Լ�copy-and-swap��

// operator=�Լ����Լ���ֵ�Ŀ����龰��
// class Widget{} Widget w��
// w = w�� ws[i] = ws[j]��*px = *py��

// ����
class Bitmap {
};

class Widget {
public:
	// �׶˷�������������������������Ҹ�ֵʱ��delete pbʱ�����������٣���ôҲ����
	// ������rhs�Ķ������Ժ���Ķ���ȫ�Ǵ�ġ�
	Widget& operator=(const Widget& rhs) {
		delete pb;  // ��ΪҪ��ֵ����������ɾ��ԭ���Լ�ָ����ڴ棬��ֹ�ڴ�й¶��
		pb = new Bitmap(*rhs.pb);  // ָ��rhs����bitmap�ĸ�����
		return *this;
	}

private:
	Bitmap* pb;  // ָ�룬ָ��һ����heap������õĶ���
};

// �Ľ���ʽһ��֤ͬ���ԣ�identity test��
// �׶˷����� �����new Bitmap() ��һ������쳣����ôpb�Ϳ���ָ��һ�鱻ɾ����Bitmap.
class Widget1 {
public:
	Widget1& operator=(const Widget1& rhs) {
		 if (this == &rhs)  // ����֤ͬ���ԣ���������Ҹ�ֵ���Ͳ����κ��¡�
		 {
			 return *this;
		 }
		 delete pb;   
		 pb = new Bitmap(*rhs.pb);   
		 return *this;
	}
private:
	Bitmap* pb;  // ָ�룬ָ��һ����heap������õĶ���
};

// �Ľ���ʽ���� ���İ������˳��
// ���new Bitmap�׳��쳣����ôpb����ָ��ԭ����bitmap��������׳��쳣����ôpb����ָ���µ�bitmap,
// Ȼ��ɾ���Լ�ԭ����bitmap��
// �׶˷�������������Ҹ�ֵ���൱�ڶ�ԭ����bitmap����һ�ݸ�����Ȼ��ɾ��ԭ����bitmap��Ȼ����ָ�����bitmap��
// ���ְ취��Ȼ�е���ʧЧ�ʡ�
class Widget2 {
public:
	Widget2& operator=(const Widget2& rhs) {
		Bitmap* ptemp = pb;  // ���ȼ�סԭ����pb����pbָ��*pb��һ��������Ȼ��ɾ��ԭ�ȵ�pb��
		pb = new Bitmap(*rhs.pb);
		delete ptemp;
		return *this;
	}
private:
	Bitmap* pb;  // ָ�룬ָ��һ����heap������õĶ���
};

// ��ʽ����copy-and-swap
// �ŵ㣺������֤���쳣��ȫ�������ҡ����Ҹ�ֵ��ȫ����
class Widget3 {
public:
	void Swap(Widget3& rhs);  // ����*this��rhs�����ݡ�
	Widget3& operator=(const Widget3& rhs) {
		Widget3 temp(rhs);  // Ϊrhs��������һ�ݸ�������*this���ݺ��������������ݽ�����
		Swap(temp);
		return *this;
	}
private:
	Bitmap* pb;  // ָ�룬ָ��һ����heap������õĶ���
};