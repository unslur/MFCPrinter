// MyTestOcxPropPage.cpp : CMyTestOcxPropPage 属性页类的实现。

#include "stdafx.h"
#include "MFCPrinter.h"
#include "MyTestOcxPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyTestOcxPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CMyTestOcxPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMyTestOcxPropPage, "MFCACTIVEXCONT.MyTestOcxPropPage.1",
	0xe0ca8e3f,0x3e7b,0x47a4,0x90,0xee,0x94,0x35,0x80,0x60,0xc7,0x31)

// CMyTestOcxPropPage::CMyTestOcxPropPageFactory::UpdateRegistry -
// 添加或移除 CMyTestOcxPropPage 的系统注册表项

BOOL CMyTestOcxPropPage::CMyTestOcxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCPRINTER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMyTestOcxPropPage::CMyTestOcxPropPage - 构造函数

CMyTestOcxPropPage::CMyTestOcxPropPage() :
	COlePropertyPage(IDD, IDS_MFCPRINTER_PPG_CAPTION)
{
}

// CMyTestOcxPropPage::DoDataExchange - 在页和属性间移动数据

void CMyTestOcxPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMyTestOcxPropPage 消息处理程序
