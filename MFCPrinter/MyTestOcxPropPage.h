#pragma once

// MyTestOcxPropPage.h: CMyTestOcxPropPage 属性页类的声明。


// CMyTestOcxPropPage : 请参阅 MyTestOcxPropPage.cpp 了解实现。

class CMyTestOcxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyTestOcxPropPage)
	DECLARE_OLECREATE_EX(CMyTestOcxPropPage)

// 构造函数
public:
	CMyTestOcxPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MFCPRINTER };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

