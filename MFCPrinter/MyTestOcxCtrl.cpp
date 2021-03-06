// MyTestOcxCtrl.cpp : CMyTestOcxCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "MFCPrinter.h"

#include "MyTestOcxCtrl.h"
#include "MyTestOcxPropPage.h"
#include "afxdialogex.h"
#include "Funcs.h"
#include "TscPrinter.h"
#include "PskPrinter.h"
#include "XminPrinter.h"
#include "ZbraPrinter.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyTestOcxCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CMyTestOcxCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CMyTestOcxCtrl, COleControl)
	//DISP_FUNCTION_ID(CMyTestOcxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMyTestOcxCtrl, "MyTest", dispidMyTest, MyTest, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CMyTestOcxCtrl, "print2", dispidprint2, print2, VT_I4, VTS_BSTR)
	////DISP_FUNCTION_ID(CMyTestOcxCtrl, "ReadQR", dispidReadQR, ReadQR, VT_BSTR, VTS_BSTR VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CMyTestOcxCtrl, "printNew", dispidprintNew, printNew, VT_I4, VTS_BSTR VTS_BSTR VTS_I4)
	////DISP_FUNCTION_ID(CMyTestOcxCtrl, "printNew_1", dispidprintNew_1, printNew_1, VT_I4, VTS_BSTR VTS_BSTR VTS_I4)
	////DISP_FUNCTION_ID(CMyTestOcxCtrl, "ReadQRNew", dispidReadQRNew, ReadQRNew, VT_BSTR, NULL)
	//DISP_FUNCTION_ID(CMyTestOcxCtrl, "printNew3", dispidprintNew3, printNew3, VT_I4, VTS_BSTR VTS_BSTR VTS_I4)
	DISP_FUNCTION_ID(CMyTestOcxCtrl, "DownloadData", dispidDownloadData, DownloadData, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION_ID(CMyTestOcxCtrl, "GetNumber", dispidGetNumber, GetNumber, VT_BSTR, VTS_BSTR)
	//DISP_FUNCTION_ID(CMyTestOcxCtrl, "ReadRFID2", dispidReadRFID2, ReadRFID2, VT_BSTR, VTS_I4)
	//DISP_FUNCTION_ID(CMyTestOcxCtrl, "WriteRFID2", dispidWriteRFID2, WriteRFID2, VT_BSTR, VTS_BSTR VTS_I4)
	//DISP_FUNCTION_ID(CMyTestOcxCtrl, "ULogin", dispidULogin, ULogin, VT_BSTR, VTS_NONE)
	////DISP_FUNCTION_ID(CMyTestOcxCtrl, "printNewWine", dispidprintNewWine, printNewWine, VT_I4, VTS_BSTR VTS_BSTR VTS_I4 VTS_I4)
	////DISP_FUNCTION_ID(CMyTestOcxCtrl, "printWine3", dispidprintWine3, printWine3, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4)
	//DISP_FUNCTION_ID(CMyTestOcxCtrl, "printWine3", dispidprintWine3, printWine3, VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4)
	//DISP_FUNCTION_ID(CMyTestOcxCtrl, "printtag2", dispidprinttag2, printtag2, VT_I4, VTS_BSTR VTS_BSTR VTS_I4)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CMyTestOcxCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CMyTestOcxCtrl, 1)
	PROPPAGEID(CMyTestOcxPropPage::guid)
END_PROPPAGEIDS(CMyTestOcxCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMyTestOcxCtrl, "MFCACTIVEXCONTRO.MyTestOcxCtrl.1",
	0x880401b, 0x3338, 0x475f, 0xbb, 0x19, 0x88, 0x97, 0xe2, 0xb4, 0xa, 0x10)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CMyTestOcxCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DMFCPrinter = {0x91e463b2,0xbe4b,0x4c9e,{0xa9,0x7f,0xca,0x88,0xb6,0x42,0x37,0x34}};
const IID IID_DMFCPrinterEvents = {0x49c222ac,0x435b,0x47b6,{0x98,0xea,0xf7,0x84,0x00,0xca,0xad,0x63}};

// 控件类型信息

static const DWORD _dwMFCPrinterOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMyTestOcxCtrl, IDS_MFCPRINTER, _dwMFCPrinterOleMisc)

// CMyTestOcxCtrl::CMyTestOcxCtrlFactory::UpdateRegistry -
// 添加或移除 CMyTestOcxCtrl 的系统注册表项

BOOL CMyTestOcxCtrl::CMyTestOcxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCPRINTER,
			IDB_MFCPRINTER,
			afxRegApartmentThreading,
			_dwMFCPrinterOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMyTestOcxCtrl::CMyTestOcxCtrl - 构造函数

CMyTestOcxCtrl::CMyTestOcxCtrl()
{
	InitializeIIDs(&IID_DMFCPrinter, &IID_DMFCPrinterEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CMyTestOcxCtrl::~CMyTestOcxCtrl - 析构函数

CMyTestOcxCtrl::~CMyTestOcxCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CMyTestOcxCtrl::OnDraw - 绘图函数

void CMyTestOcxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMyTestOcxCtrl::DoPropExchange - 持久性支持

void CMyTestOcxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CMyTestOcxCtrl::OnResetState - 将控件重置为默认状态

void CMyTestOcxCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CMyTestOcxCtrl::AboutBox - 向用户显示“关于”框

void CMyTestOcxCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCPRINTER);
	dlgAbout.DoModal();
}
const string CMyTestOcxCtrl::GetDefaultPrinter() const {
	CPrintDialog printDlg(FALSE);
	printDlg.GetDefaults();
	return printDlg.GetDeviceName().GetBuffer(0);
}
string codes;
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	//int i;
	char buff[0x50];
	sprintf(buff, "%s,%s|", argv[0], argv[1]);
	codes += buff;
	/*for(int i=0; i<argc; i++){
	codes += argv[i];
	codes += ",";
	//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	codes += "|";*/
	return 0;
}
string GetNumbers(const char* orgID, const char* taskID, int num, const char* dbPathName) {
	char buff[0x200];
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open(dbPathName, &db);


	sprintf(buff, "select code,flag from number where orgid='%s' and taskid='%s' limit %d", orgID, taskID, num);

	
	codes = "";
	rc = sqlite3_exec(db, buff, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		sprintf(buff, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return buff;
	}

	if (codes.length() > 0)
		codes = codes.substr(0, codes.length() - 1);
	//AfxMessageBox(codes.c_str());
	return codes;
}
string GetDownData(const char* userID, const char* password, const char* dt, const char* taskID, const char* taskType, const char* ip, int port) {
	char buff[0x100];
	sprintf(buff, "%s %s %s %s %s", userID, password, dt, taskID, taskType);
	string sendStr = buff;
	Socket so;
	//so.CInit("192.168.0.215",5555);
	so.CInit(ip, port);
	so.CCreateSocket();
	if (!so.CConnect()) {
		so.CCloseSocket();
		return "net error";
	}
	so.Send(sendStr);


	int recvInt = 0, allRecvLen = 0;
	char* recvBuff = (char*)malloc(0x400 * 0x400 * 10);
	while (true) {
		if (!so.Recv(recvBuff + allRecvLen, int(0x400), recvInt)) break;
		allRecvLen += recvInt;
	}
	so.CCloseSocket();
	//AfxMessageBox(recvBuff);

	if (strstr(recvBuff, "error") != NULL) {
		return recvBuff;
	}

	LodePNG_DecompressSettings setting;
	setting.ignoreAdler32 = 0;
	/*char stringsss[32];
	itoa(allRecvLen, stringsss, 10);
	AfxMessageBox(stringsss);*/
	unsigned char* zip_buffer = (unsigned char*)malloc(0x400 * 0x400 * 10);// 这个是输出缓冲
	size_t zip_length; // 输出长度
	int ret = LodePNG_zlib_decompress(&zip_buffer, &zip_length, (unsigned char*)recvBuff, allRecvLen, &setting);
	free(recvBuff);
	recvBuff = NULL;
	if (ret != 0) {
		char buff[0x50];
		sprintf(buff, "unzip error %d", ret);
		return buff;
	}
	*(zip_buffer + zip_length) = 0;
	char* p = (char*)zip_buffer;

	char* q = strstr((char*)zip_buffer, " ");
	*q = 0;
	string orgID = p;
	p = q + 1;

	char sqlBuff[0x200];

	filePath();//设置数据库目录文件

	string rtn = FindAndCreatDB(DBPathName); //检测库
	if (rtn != "OK") {
		return rtn;
	}
	//AfxMessageBox("1");
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open(DBPathName, &db);
	if (rc) {
		sqlite3_close(db);
		sprintf(buff, "Can't open database: %s", sqlite3_errmsg(db));
		return buff;
	}
	//AfxMessageBox("2");
	sprintf(sqlBuff, "delete from number where orgid='%s' and taskid='%s'", orgID.c_str(), taskID);
	sqlite3_exec(db, sqlBuff, NULL, 0, &zErrMsg);//插入前清除无效数据
	rc = sqlite3_exec(db, "BEGIN;", NULL, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		sprintf(buff, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return buff;
	}
	//<<<<<<< .mine
	//	fp=fopen("d://zyczs/num.txt","a+");
	//	num=0;
	//	//AfxMessageBox(p);
	//||||||| .r813
	//
	//=======
	//	//AfxMessageBox(p);
	//>>>>>>> .r894
	while (true) {
		q = strstr(p, "|");
		if (NULL == q) break;
		*q = 0;
		string record = p;
		p = q + 1;
		//num++;
		//	AfxMessageBox("4");
		string code = record.substr(0, record.find(","));
		record = record.substr(record.find(",") + 1);
		string flag = record.substr(record.find(",") + 1);
		sprintf(sqlBuff, "insert into number(orgid,taskid,flag,code) values('%s','%s',%s,'%s')", orgID.c_str(), taskID, flag.c_str(), code.c_str());
		rc = sqlite3_exec(db, sqlBuff, NULL, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			sprintf(buff, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_close(db);
			return buff;
		}
	}
	//AfxMessageBox("3");
	free(zip_buffer);
	zip_buffer = NULL;
	/*char cnum[10]={0};
	itoa(num,cnum,10);
	sprintf(cnum,"%s\n",cnum);
	fwrite(cnum,sizeof(cnum),1,fp);*/
	//AfxMessageBox("5");
	sqlite3_exec(db, "COMMIT;", NULL, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		sprintf(buff, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return buff;
	}
	//fclose(fp);
	sqlite3_close(db);
	//AfxMessageBox("5");
	return "OK";
}
// CMyTestOcxCtrl message handlers
LONG CMyTestOcxCtrl::MyTest(LPCTSTR bstrTest)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	//AfxMessageBox(bstrTest);
	AfxMessageBox("cys");
	//filePath();
	//string rtn = FindAndCreatDB(DBPathName); //检测库
	//AfxMessageBox(rtn.c_str());
	return 0;
}
// CMyTestOcxCtrl 消息处理程序
BSTR CMyTestOcxCtrl::DownloadData(LPCTSTR inVar)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxMessageBox(inVar);
	CString strResult;
	
	string InVar = inVar;

	string userID, password, dt, taskID, taskType, ip, port;
	userID = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);

	password = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);

	dt = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);

	taskID = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);

	taskType = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);

	ip = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);
	port = InVar;

	string rtnStr =  GetDownData(userID.c_str(), password.c_str(), dt.c_str(), taskID.c_str(), taskType.c_str(), ip.c_str(), atoi(port.c_str()));
	strResult = rtnStr.c_str();
	return strResult.AllocSysString();
}
LONG CMyTestOcxCtrl::print2(LPCTSTR pp)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const int DYJC = 34;
	int resultI = 1;

	// 增加如下代码
	char szprinter[80];
	char *szDevice, *szDriver, *szOutput;
	HDC hdcprint; // 定义一个设备环境句柄
				  //定义一个打印作业
	static DOCINFO di = { sizeof(DOCINFO),"printer",NULL };
	// 得到设备字符串存入数组szprinter中
	GetProfileString("windows", "device", ",,,", szprinter, 80);
	// 将设备字符串分解
	if (NULL != (szDevice = strtok(szprinter, ",")) &&
		NULL != (szDriver = strtok(NULL, ",")) &&
		NULL != (szOutput = strtok(NULL, ",")))
		// 创建一个打印机设备句柄 

		if ((hdcprint = CreateDC(szDriver, szDevice, szOutput, NULL)) != 0) {
			if (StartDoc(hdcprint, &di)>0) { //开始执行一个打印作业
				StartPage(hdcprint); //打印机走纸,开始打印				
				SaveDC(hdcprint); //保存打印机设备句柄				
								  // 输出一行文字
				char buff[DYJC * 2 + 1];
				string printStr = pp; //"上面是在MSDN中的TextOut的\n定义,第一个参数是文字输出的开始点的横坐标,第二参数是纵坐标,第三个参数是输\n出文字的内容,第四个参数是要输出几个字";
				list<string> printv = splitPrintv(splitPrintStr(printStr), DYJC);
				int l = 0;
				for (list<string>::const_iterator iter = printv.begin(); iter != printv.end(); ++iter) {
					memset(buff, 0, sizeof(buff));
					strcpy(buff, iter->c_str());
					TextOut(hdcprint, 1, l * 41 + 1, buff, DYJC);
					l++;
				}

				RestoreDC(hdcprint, -1); //恢复打印机设备句柄
				EndPage(hdcprint); //打印机停纸,停止打印
				EndDoc(hdcprint); //结束一个打印作业
								  //MessageBox("打印完毕!","提示",MB_ICONINFORMATION);				
			}
			// 用API函数DeleteDC销毁一个打印机设备句柄 			
			DeleteDC(hdcprint);
		}
		else {
			MessageBox("没有默认打印机,或者没有安装打印机!");
			resultI = 0;
		}
		return resultI;
}
//nPrintType 1表示打印左边，2表示打印右边，3表示一行打印2个
LONG CMyTestOcxCtrl::printNew(LPCTSTR pp, LPCTSTR printerNamet, LONG nPrintType) {

	string printStr = (const char*)pp;
	//string printStr1, printStr2;
	AfxMessageBox(printStr.c_str());
	bool bIsPrint = false;
	int id_name = 0, rtn = 0;


	char printerName[0x64] = { 0 };
	//AfxMessageBox("2");
	if (strlen(printerNamet) == 0)
		strcpy(printerName, GetDefaultPrinter().c_str());
	else
		strcpy(printerName, printerNamet);
	//波斯得  POSTEK G2000
	//tsc  Bar Code Printer LP-2000A
	//斑马  ZDesigner ZT210-200dpi ZPL
	//AfxMessageBox(printerName);
	if (strstr(printerName, "Printer LP") != NULL
		|| strstr(printerName, "Printer B") != NULL)
	{
		CTscPrinter printer;
		if (!printer.TscInit(printerName)) {
			return	0;
		}
		rtn = printer.PrintTsc2(printerName, printStr, nPrintType);
		printer.TscUnInit();
	}
	else if (strstr(printerName, "POSTEK") != NULL)
	{
		CPskPrinter printer;
		if (!printer.PskInit(printerName)) {
			return 0;
		}
		rtn = printer.PrintPsk2(printerName, printStr, nPrintType);
		printer.PskUnInit();
	}
	else if (strstr(printerName, "ZMIN") != NULL)
	{
		CXminPrinter printer;
		if (!printer.XminInit(printerName)) {
			return 0;
		}
		rtn = printer.PrintXmin2(printerName, printStr, nPrintType);
		printer.XminUnInit();
	}
	else if (strstr(printerName, "ZDesigner") != NULL || strstr(printerName, "Microsoft") != NULL)
	{
		CZbraPrinter printer;
		rtn = printer.PrintZbra2(printerName, printStr, nPrintType);
	}
	else
	{
		AfxMessageBox("请检查是否正确设置默认打印机！");
	}

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return rtn;
}
BSTR CMyTestOcxCtrl::GetNumber(LPCTSTR inVar)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult;
	AfxMessageBox(inVar);
	string InVar = inVar;
	string userID, taskID;
	int num;
	userID = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);
	taskID = InVar.substr(0, InVar.find(" "));
	InVar = InVar.substr(InVar.find(" ") + 1);
	num = atoi(InVar.c_str());
	filePath();
	string rtnData = GetNumbers(userID.c_str(), taskID.c_str(), num, DBPathName);
	strResult = rtnData.c_str();
	return strResult.AllocSysString();
}