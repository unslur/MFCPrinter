// MFCPrinter.cpp: CMFCPrinterApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "MFCPrinter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMFCPrinterApp theApp;

const GUID CDECL _tlid = {0x5292bcdf,0x64d5,0x4cdf,{0x8b,0x12,0x16,0xee,0x0a,0x33,0x6c,0xac}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMFCPrinterApp::InitInstance - DLL 初始化

BOOL CMFCPrinterApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CMFCPrinterApp::ExitInstance - DLL 终止

int CMFCPrinterApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
