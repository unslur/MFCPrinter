#pragma once
#include <string>
#include <string.h>
#include <vector>
using namespace std;

// MyTestOcxCtrl.h : CMyTestOcxCtrl ActiveX 控件类的声明。


// CMyTestOcxCtrl : 请参阅 MyTestOcxCtrl.cpp 了解实现。

class CMyTestOcxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMyTestOcxCtrl)

// 构造函数
public:
	CMyTestOcxCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CMyTestOcxCtrl();

	DECLARE_OLECREATE_EX(CMyTestOcxCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CMyTestOcxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMyTestOcxCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CMyTestOcxCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidprinttag2 = 17L,
		dispidprintNew_1 = 16L,
		dispidprintWine3 = 15L, dispidULogin = 14L, dispidWriteRFID2 = 13L, dispidReadRFID2 = 12L, dispidGetNumber = 11L, dispidDownloadData = 10L,
		dispidprintNew3 = 9L,
		dispidReadQRNew = 8L,
		dispidprintNew = 7L,
		dispidReadQR = 6L,
		dispidprint2 = 5L,
		dispidWriteRFID = 4L,
		dispidReadRFID = 3L,
		dispidprint = 2L,
		dispidMyTest = 1L
	};
private:
	const string GetDefaultPrinter() const;
	
	HINSTANCE hInstMaster;
	char usbId[64], usbAuth[64];

protected:
	LONG MyTest(LPCTSTR bstrTest);
	LONG printNew(LPCTSTR pp, LPCTSTR printerName, LONG nPrintType);
	LONG printNew_1(LPCTSTR pp, LPCTSTR printerName, LONG nPrintType);
	LONG printNew3(LPCTSTR pp, LPCTSTR printerName, LONG nPrintType);
	LONG print2(LPCTSTR pp);
	BSTR ReadQR(LPCTSTR com, LONG baudRate, LONG overTime);
	BSTR ReadQRNew();
	BSTR DownloadData(LPCTSTR inVar);
	BSTR GetNumber(LPCTSTR inVar);
	BSTR ReadRFID2(LONG overTime);
	BSTR WriteRFID2(LPCTSTR codeStr, LONG mode);
	bool JudgeDefaultType(void);
	bool JudgeOldType(void);
	bool ModifyPass(void);
	string EncryptNoUseBlock();
	BSTR ULogin(void);
	BOOL initUsb();
	string UkeyGetDownData(IN const char* sendCommand, IN const char* ip, IN int port, OUT unsigned char** buffer, OUT size_t& bufferLen) const;
	string SentUsbIdToServer(string& taskIP, int taskPort, char* usbId);
	LONG printWine3(LPCTSTR http, LPCTSTR code, LPCTSTR pp, LONG nPrintType);
	LONG printtag2(LPCTSTR pp, LPCTSTR printerName, LONG nPrintType);
};

