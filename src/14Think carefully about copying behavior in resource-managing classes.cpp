// ����14�� ����Դ��������С��copy��Ϊ
// 1.����RAII�������һ�����������������Դ��������Դ��copying��Ϊ����RAII�����copying��Ϊ��
// 2.�ձ��������RAII class copying��Ϊ�ǣ�����copying��ʩ�����ü�����(reference counting)��
// ����������ΪҲ�����ܱ�ʵ�֡�

#include <iostream>
#include <memory>

class UnCopyable {
public:
	UnCopyable() {
	}
	~UnCopyable() {
	}
	
private:
	UnCopyable(UnCopyable& );
	UnCopyable& operator=(UnCopyable&);
};

// ����������
class Mutex {
};

// ����pm��ָ�Ļ�����
void lock(Mutex* pm);

// ����������������������ǽ����������٣�ֻ�ǽ������
void unlock(Mutex* pm);

// ����һ������������������RAII������Դ��ȡʱ���ǳ�ʼ��ʱ����Ҳ����
// ����Դ�ڹ����ڻ�ã����������ͷš����������ǻ����������ڹ����๹���ڼ�����
// �ڹ����������ڽ�����
// ��������Ŀ���ǣ�����һ��������������ĳ�����������Զ���ĳЩ��Ϊ������������
// ������Դ�ͷ��ڴ�ȡ����Կ�����ָ�����������࣬��������������Ϊ��
class Lock {
public:
	explicit Lock(Mutex* pm) 
		: mutex_ptr_(pm) {
		lock(mutex_ptr_);  // �ڹ�������ȡ��ԴҲ���Ǽ������������ȡ��Դ���Ǽ���
	}
	~Lock() {
		unlock(mutex_ptr_);  // ���������ͷ���ԴҲ���ǽ���
	}

private:
	Mutex* mutex_ptr_;
};

// 3.һ�㵱һ��RAII���󱻸��ƣ������ʱ�������������ѡ��
// (A)��ֹ���ƣ���Ϊ���ʱ������RAII���󱻸��Ʋ�������
class Lock1 : public UnCopyable {  // ʹ�����ַ�������ֹ����
};

// (B)�Եײ���Դ���������ü�����(refrence-count)������������Ŀ���ǣ�ϣ��������Դ��
// ֱ���������һ��ʹ���߱�����ʱ���ͷŸ���Դ��
// ���ǵ�ʵ�ַ�������ʹ��tr1::shared_ptr��Ա����������tr1::shared_ptr��ȱʡ��Ϊ��
// �������ô���Ϊ0��ʱ��ɾ��ĳ�������Ҫ����Ϊ��unlockĳ����˵��ǣ�tr1::shared_ptr
// ����ָ����ɾ������,yҲ����ָ��ɾ����Ϊ������ɾ����Ϊ��Ϊ������Ҫ����Ϊ��
class Lock2 {
public:
	explicit Lock2(Mutex* pm)
		: mutex_ptr_(pm, unlock) {  // ��shared_ptr����unlockΪɾ����
		lock(mutex_ptr_.get());
	}
	// ���ض���������������Ϊclass���������������Ǳ��������ɣ������û��Զ���ģ�
	// ���ǻ��Զ�������non-static��Ա��������������������mutex_ptr_����������
	// ���ڻ����������ô���Ϊ0ʱ�Զ�����tr1::shared_ptr��ɾ����
private:
	std::tr1::shared_ptr<Mutex> mutex_ptr_;  // ʹ��shared_ptr���滻raw_pointer��
};

// 4.�������ֽ������Ҳ���ܳ���
// (A)���Ƶײ���Դ��Ҳ���������
// (B)ת�Ƶײ���Դ��ӵ��Ȩ������auto_ptrһ����˭�����ˣ������Դ�͹�˭��

int main14() {
	Mutex m;
	// ����һ�����飬������ĩβ�Զ��������������
	{
		Lock m1(&m);
	}
	// �����������������Ϊ����ô�����ö���ᱻunlock���Σ���Ϊ������ǳ��������ֱ��ָ�븳ֵ��
	{
		Lock ml1(&m);
		Lock ml2(&m);
	}

	return 0;
}
