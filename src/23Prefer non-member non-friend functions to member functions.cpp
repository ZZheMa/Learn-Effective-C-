// ����23�� ����non-member��non-friend�滻member������
// 1.������non-member non-friend�����滻member�������������������ӷ�װ�ԡ�
// �������Ժͻ��������ԡ�

class WebBrowser23 {
public:
	void ClearCache();
	void ClearHistory();
	void RemoveCookies();

public:
	void ClearEverthing() {
		ClearCache();
		ClearHistory;
		RemoveCookies();
	}
};

void ClearBrower(WebBrowser23& wb) {
	wb.ClearCache();
	wb.ClearHistory();
	wb.RemoveCookies();
}

// �ṩ�����ĺ����÷ŵ����

// ���ǣ�һ��������������member����ClearEverything�û���non-member
// non-friend����ClearBrowser�ã�����ClearBrowser���ã�����ķ�װ�Ը��á�

// 2.��װ�����ĳЩ��������װ�����Ͳ��ٿɼ���Խ��Ķ�������װ��Խ�ٵ��˿��Կ�������
// ��Խ���˿����������Ǿ���Խ��ĵ���ȥ�ı�������Ϊ���ǵĸı����ֱ��Ӱ�쿴���ı�
// ����Щ�����װʹ�����ܸı������ֻӰ�����޿ͻ���

// 3.���Ƕ����ڵ����ݣ�Խ�ٵĴ�����Է������ݣ���ôԽ������ݾͿ��Ա���װ��������
// Ҳ��Խ�����ɵظı�������ݡ���β����ж��ٴ�����Կ���ĳ�������أ����ǿ��Լ����ܹ�
// ���ʸ����ݵĺ�������������Ϊһ�ֲִڵĲ�����Խ��ĺ��������������ݵķ�װ��Ҳ��Խ�͡�
// ��������22��˵��Ա����Ӧ����private��������ǣ��ͻ����������ĺ������Է������ǣ�
// ����Ҳ�ͺ��޷�װ�ԡ��ⲿ��һ��������Ҫ����private��Ա������ֻ��ʹ�ó�Ա�������߼���
// friend.����������ֱ�ӷ�����private��Ա�����������˷������ĺ�����������Ҳ�ͽ�����
// non-member non-friend������member�������ݻ�ӭ��ԭ��non-member non-friendʹ��
// �нϴ�ķ�װ�ԡ�

// C++��Ϊ��Ȼ����������ClearBrower��Ϊһ��non-member�������Һ�WebBrowserλ��ͬһ��
// namespace���档namespace���Կ�Խ���Դ���ļ�����class���С�
// �����еı����������ڶ��ͷ�ļ��ڵ�����ͬһ�������ռ䣬��ζ�ſͻ�����������չ
// ��һ��������������ַָ��ʹ�ÿͻ�����ֻ���������õ���һС����ϵͳ�γɱ�������.
// ����C++��׼�⣬��std�����ռ������кö�ͷ�ļ����������vector���������ֻ��#include
// vector�Ϳ����ˣ�����ȥinclude�������޹����ݡ�

// ��"web_browser.h"�ж���WebBrower����������Լ�����Ĺ��ܡ�
namespace WebBrowserStuff {
	class WebBrowser23 {
	public :
		void Func1();
		void Func2();
		void Func3();
	};
	
	// non-member�������ṩ�������пͻ�����Ҫ�ĺ��Ļ���
	void CoreFunc(WebBrowser23& wb) {
		wb.Func1();
	}
}

// ��ͷ�ļ�"webbrower_bookmarks.h"���ṩ����ǩ��صı�������
namespace WebBrowserStuff {
	void ClearBookmarks(WebBrowser23& wb) {
		wb.Func2();
		wb.Func3();
	}
}

// ��ͷ�ļ�"webbrower_cookies.h"���ṩ��Cookies��صı�������
namespace WebBrowserStuff {
	void ClearCookies(WebBrowser23& wb) {
		wb.Func1();
		wb.Func2();
		wb.Func3();
	}
}
