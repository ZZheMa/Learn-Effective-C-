// ����03: ������ʹ��const

#include <iostream>
#include <vector>
#include <string>

// 1.��const ���κ����Ĳ���
//  �������������á�ָ�봫�ݡ�����ô��const���ο��Է�ֹ����ظĶ���ָ�룬�𵽱������á�
//  ����void StringCopy(char*strDestination, const char *strSource);
//  �������������á�ֵ���ݡ������ں������Զ�������ʱ�������ڸ��Ƹò�����������������������豣����
//  ���Բ�Ҫ��const���Ρ����粻Ҫ������void Func1(int x) д��voidFunc1(const int x)��
//  ͬ��Ҫ������void Func2(A a) д��void Func2(const Aa)������A Ϊ�û��Զ�����������͡�
//  ���ڷ��ڲ��������͵Ĳ������ԣ���void Func(A a)���������ĺ���ע��Ч�ʱȽϵס�
//  ��Ϊ�������ڽ�����A���͵���ʱ�������ڸ��Ʋ���a������ʱ����Ĺ��졢���ơ��������̶�������ʱ�䡣
//  Ϊ�����Ч�ʣ����Խ�����������Ϊvoid Func(A&a)����Ϊ�����ô��ݡ�������һ�²����ı������ѣ�����Ҫ������ʱ����
//  ���Ǻ���void Func(A&a) ����һ��ȱ�㣺�����ô��ݡ��п��ܸı����a���������ǲ������ġ���������������ף�
//  ��const���μ��ɣ���˺������ճ�ΪvoidFunc(const A &a)���Դ����ƣ�
//  �Ƿ�Ӧ��void Func(int x)��дΪvoid Func(const int&x)���Ա����Ч�ʣ���ȫû�б�Ҫ��
//  ��Ϊ�ڲ��������͵Ĳ��������ڹ��졢�����Ĺ��̣�������Ҳ�ǳ��죬��ֵ���ݡ��͡����ô��ݡ���Ч�ʼ����൱��
//  ����:A.���ڷ��ڲ��������͵����������Ӧ�ý���ֵ���ݡ��ķ�ʽ��Ϊ��const ���ô��ݡ���Ŀ�������Ч�ʡ�
//  ����:B.�����ڲ��������͵������������Ҫ����ֵ���ݡ��ķ�ʽ��Ϊ��const���ô��ݡ�������ȴﲻ�����Ч�ʵ�Ŀ�ģ��ֽ����˺����Ŀ�����ԡ�

// 2.��const���κ����ķ���ֵ
// ������ԡ�ָ�봫�ݡ���ʽ�ĺ�������ֵ��const���Σ���ô��������ֵ����ָ�룩�����ݲ��ܱ��޸ģ�
// �÷���ֵֻ�ܱ�������const ���ε�ͬ����ָ�롣
// ���纯��const char *GetString(void); ������佫���ֱ������
// char *str = GetString(); ��ȷ���÷���constchar *str = GetString(); 
// �����������ֵ���á�ֵ���ݷ�ʽ�������ں�����ѷ���ֵ���Ƶ��ⲿ��ʱ�Ĵ洢��Ԫ�У���const����û���κμ�ֵ��
// ���粻Ҫ�Ѻ���int GetInt(void) д��const int GetInt(void)��
// ͬ��Ҫ�Ѻ���AGetA(void) д��const A GetA(void)������A Ϊ�û��Զ�����������͡�
// �������ֵ�����ڲ��������ͣ�������AGetA(void) ��дΪconst A &GetA(void)��ȷ�����Ч�ʡ�
// ����ʱǧ��ǧ��ҪС�ģ�һ��Ҫ����������������뷵��һ������ġ����������ǽ����ء��������Ϳ����ˣ������������
// ��������ֵ���á����ô��ݡ��ĳ��ϲ����࣬���ַ�ʽһ��ֻ��������ĸ�ֵ�����У�Ŀ����Ϊ��ʵ����ʽ��
// ���磺class A{ A &operate = (const A &other); // ��ֵ����};
//  A a, b, c; //a, b, c ΪA �Ķ���
//  a = b = c; // ��������ʽ��ֵ
//  (a = b) =c; // ����������ʽ��ֵ�����Ϸ��������ֵ�����ķ���ֵ��const ���Σ���ô�÷���ֵ�����ݲ������Ķ���
//  �����У���� a = b= c ��Ȼ��ȷ��������� (a = b) = c ���ǷǷ��ġ�

// 3.const��Ա����const������
// ˵���䲻���޸����ݳ�Ա,�κβ����޸����ݳ�Ա�ĺ�����Ӧ������Ϊconst ���͡�
// ����ڱ�дconst��Ա����ʱ�������޸������ݳ�Ա�����ߵ�����������const��Ա��������������ָ������
// �����ɻ���߳���Ľ�׳�ԡ����³����У���stack �ĳ�Ա����GetCount�����ڼ��������߼��Ͻ�GetCount 
// Ӧ��Ϊconst ��������������ָ��GetCount �����еĴ���
class Stack {
public:
	void Push(int elem);
	int Pop(void);
	int GetCount(void) const;  // const��Ա����
  private:
	  int m_num; 
		int m_data[100];
  };
int Stack::GetCount(void)const
{
	//++m_num; //���������ͼ�޸����ݳ�Աm_num
	//Pop(); // ���������ͼ���÷�const����
	return m_num;
  }
// const��Ա�����������������ֵֹģ�const�ؼ���ֻ�ܷ��ں���������β�����������Ϊ�����ط����Ѿ���ռ���ˡ�

// 4.����Const�����ļ������
//  a.const����ֻ�ܷ���const��Ա����, ����const������Է�������ĳ�Ա����, ����const��Ա����.
//  b.const����ĳ�Ա�ǲ����޸ĵ�, Ȼ��const����ͨ��ָ��ά���Ķ���ȴ�ǿ����޸ĵ�.
//  c.const��Ա�����������޸Ķ��������.���ڱ���ʱ, ���Ƿ��޸ĳ�Ա����Ϊ����, ���м��.
//  d.Ȼ������mutable���η������ݳ�Ա, �����κ������ͨ���κ��ֶζ����޸�, ��Ȼ��ʱ��const��Ա�����ǿ����޸�����
//  e.const ����ֻ�ܵ��� const��������ʹĳ������������û���޸��κ����ݣ���û������Ϊconst��Ҳ�ǲ��ܱ�const�������õġ�

class A {
public:
	int a;
	int b;
	mutable int c;
	void Test() const {
		//a++;  // ����
		c++;  // ��ȷ
	}
	void Test1() {
		a++;
	}
};

// 5.const ����ָ��
const char* p1 = "hello";  // const data, non-const pointer
char* const p2 = "hello";  // const pointer, non-const data

// 6.const���ε�����
// STL����������ָ��Ϊ�������������,���Ե����������þ����T*ָ��
void ConstIterator() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	const std::vector<int>::iterator iter = vec.begin();  // iter�����þ���һ��T* const.
	*iter = 10;  // ��ȷ
	//iter++;  // ����

	std::vector<int>::const_iterator citer = vec.begin();  // citer�����þ���const T*.
	//*citer = 10;  // ���� 
	++citer;  // ��ȷ

}

// 7.������Ա�������ֻ�ǳ����Բ�ͬ,���Ա�����
class TextBlock {
public:
	TextBlock() {
		str = "abcdefg";
	}

	char& operator[] (std::string::size_type position) {
		return str[position];
	}

	const char& operator[] (std::string::size_type position) const { 
		// ע��: ֻ�г�Ա������const����,��Ϊ����
		// ����ֵ������const����,��Ϊ������const����,��ô����ĳ�Ա��ҲΪconst����,
		// 'return' : cannot convert from 'const char' to 'char &
		return str[position + 1];
	}

	void Test() {
	}

	void TestConst() const {
	}

	void Print(TextBlock& text) {
		std::cout << text[0] << std::endl;
	}

	void Print(const TextBlock& text) {  
		// ������const����Ҳ��Ϊ������
		std::cout << text[0] << std::endl;
	}

private:
	std::string str;
};

// TextBlockʵ�ִ��븴�õķ���:
// �����TextBlock����=�����������,����ʵ����ͬ���Ĵ���,�������Ļ�����,�������ܳ���ô,�͵����˴�����׸.
// �����������non-const��������const����,Ȼ�󷵻�ֵǿתΪnon-const.
// static_cast < type-id > ( expression )
// ���������expressionת��Ϊtype-id���ͣ���û������ʱ���ͼ������֤ת���İ�ȫ�ԡ�
// const_cast<type_id> (expression)
// ������������޸����͵�const��volatile���ԡ�����const ��volatile����֮�⣬ type_id��expression��������һ���ġ�
class TextBlock2 {
private:
	std::string str;

public:
	TextBlock2(std::string str) {
		this->str = str;
	}

	const char& operator[] (std::string::size_type position) const {
		std::string other_code = "many other codes";
		std::cout << other_code << std::endl;
		return str[position];
	}

	char& operator[] (std::string::size_type position) {
		return const_cast<char&>(static_cast<const TextBlock2&>(*this)[position]);  
		//��*this������ǿ��תΪconst TextBlock2&����,Ȼ�����[]const�����õ�const char��ֵ,������const����ȥ��
	}
};

int main03() {
	A* a = new A();
	a->Test();  // ��ȷ
	const A* a1 = new A();
	a->Test1();  // ��ȷ
	a->Test();  // ��ȷ

	TextBlock text1, text2;
	const TextBlock ctext;
	text2.Print(text1);  // a const��non-const�������²�ͬ�Ĵ���
	text2.Print(ctext);  // b
	ctext.TestConst();  // ��ȷ
	//ctext.Test();  // cannot convert 'this' pointer from 'const TextBlock' to 'TextBlock &'
	// const����ֻ�ܵ���const��Ա����
	// ԭ��: C++ Primer��˵�ˣ���һ������������Ա����ʱ����������һ���β�thisָ�롣
  // ���磬���Ƕ�����һ������CTest::t(); ʵ�����ڱ������иú����Ķ������CTest::t(CTest *const this)��
	// ��thisָ����ָ������ݿ��Ըı䣬���Ǹ�thisָ�벻���Ա��ı䡣
	// ��������CTest��һ������test1����t����ʱ��test1.t()ʱ���������ͻὫ������Ϊt(&test1)��
	// ����������t��ʹ��thisָ��Ϳ��Ըı����test1�ĳ�Ա�����ˡ�
  // ���ǣ������ǵĶ�����const����ʱ����const CTest t;t�������ǲ����Ըı�ģ�
	// �����ǰ�&t��Ϊһ�����������β�thisʱ��ì�ܳ����ˣ�t��һ�����������Ա�����Ա��ı䣻
	// thisָ��ĳ�Ա�����ǿ��Ըı�ġ����������ȷ�Ľ�t�ĵ�ַ����this��
	// ��ôt���������ֵ���ǿ�����this�б��ı��������ԣ��������ǲ���������������ֵģ�����ʾ�����ˡ�
	// �ʣ�const�����ܷ��ʷ�const��Ա������
  // ͬ�������ǵĳ�Ա������const��Ա����ʱ������CTest::t() const, 
	// �ڱ���������ʱ�Ὣ�ú�������ΪCTest::t(const CTest * const this), thisָ�뼰����ָ������ݶ������Ա��޸ģ�
	// ǰ���ᵽ��ì��Ҳ�Ͳ������ˣ�����const������Է���const��Ա������

	TextBlock t;
	char& tem = t[0];
	std::cout << tem << std::endl;  // a
	const char& tem2 = t[0];
	std::cout << tem2 << std::endl; //a
	const TextBlock t1;  // const�������const��Ա����
	const char& tem3 = t1[0];  // ����const,���Ա�����const����

	TextBlock2 t3("abcdef");
	char& tem4 = t3[0];
	std::cout << tem3 << std::endl;
	tem4 = 'b';  // ��ȷ
	return 0;
}

//  �ο� : http://blog.csdn.net/zheng19880607/article/details/23883437
