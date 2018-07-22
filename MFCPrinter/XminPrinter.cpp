#include "StdAfx.h"
#include ".\xminprinter.h"

/////////////////////////////////


////////////////////////////////////////////////////
typedef int(__stdcall *fXOpenPort)(LPCTSTR printername);
typedef int(__stdcall *fZM_SetDarkness)(unsigned  int id);
typedef int(__stdcall *fZM_SetPrintSpeed)(unsigned int px);
typedef int(__stdcall *fXClosePort)(void);
typedef int(__stdcall *fZM_PrintLabel)(unsigned int number,
	unsigned int cpnumber);
typedef int(__stdcall *fZM_DrawBarcode)(unsigned  int px,
	unsigned int  py,
	unsigned int  pdirec,
	LPTSTR        pCode,
	unsigned int  pHorizontal,
	unsigned int  pVertical,
	unsigned int pbright,
	char ptext,
	LPTSTR pstr);
typedef int(__stdcall *fZM_DrawTextTrueTypeW)
(int x, int y, int FHeight,
	int FWidth, LPCTSTR FType,
	int Fspin, int FWeight,
	BOOL FItalic, BOOL FUnline,
	BOOL FStrikeOut,
	LPCTSTR id_name,
	LPCTSTR data);
typedef int(__stdcall *fZM_SetLabelHeight)
(unsigned int lheight, unsigned int gapH);
typedef int(__stdcall *fZM_SetLabelWidth)(unsigned int lwidth);
typedef int(__stdcall *fZM_SetDirection)( char  direct	);
typedef int(__stdcall *fZM_ClearBuffer)();
typedef int(__stdcall *fZM_DrawRectangle)(unsigned int    px, unsigned int    py,
	unsigned int   thickness, unsigned int   pEx,
	unsigned int   pEy);
typedef int(__stdcall *fZM_PcxGraphicsDel) (LPTSTR pid);
typedef int(__stdcall *fZM_PcxGraphicsDownload) (char*  pcxname, char* pcxpath);
typedef int(__stdcall *fZM_DrawPcxGraphics)(unsigned int  px, unsigned int  py, LPTSTR  gname);
typedef int(__stdcall *fZM_DrawBar2D_Pdf417)(unsigned int x, unsigned int  y,
	unsigned int w, unsigned int v,
	unsigned int s, unsigned int c,
	unsigned int px, unsigned int  py,
	unsigned int r, unsigned int l,
	unsigned int t, unsigned int o,
	LPTSTR pstr);
typedef int(__stdcall *fZM_DrawBar2D_QR)(unsigned int x,
	unsigned int y,
	unsigned int w,
	unsigned int v,
	unsigned int o,
	unsigned int r,
	unsigned int m,
	unsigned int g,
	unsigned int s,
	LPTSTR pstr);
typedef int(_stdcall *fZM_DrawLineOr)(unsigned int px, unsigned int py, unsigned int plength, unsigned int pH);
typedef int(_stdcall *fZM_DrawText)(unsigned  int px, unsigned int  py,
	unsigned int  pdirec, unsigned int pFont,
	unsigned int  pHorizontal,
	unsigned int  pVertical,
	char ptext, LPTSTR pstr);
HINSTANCE gt1Xmin=NULL;
fXOpenPort XOpenPort = NULL;
fZM_SetDarkness ZM_SetDarkness = NULL;
fZM_DrawTextTrueTypeW ZM_DrawTextTrueTypeW = NULL;
fZM_SetPrintSpeed ZM_SetPrintSpeed = NULL;
fXClosePort XClosePort = NULL;
fZM_PrintLabel ZM_PrintLabel = NULL;
fZM_DrawBarcode ZM_DrawBarcode = NULL;
fZM_SetLabelHeight ZM_SetLabelHeight = NULL;
fZM_SetLabelWidth ZM_SetLabelWidth = NULL;
fZM_ClearBuffer ZM_ClearBuffer = NULL;
fZM_DrawRectangle ZM_DrawRectangle = NULL;
fZM_PcxGraphicsDel ZM_PcxGraphicsDel = NULL;
fZM_PcxGraphicsDownload ZM_PcxGraphicsDownload = NULL;
fZM_DrawPcxGraphics ZM_DrawPcxGraphics = NULL;
fZM_DrawBar2D_Pdf417 ZM_DrawBar2D_Pdf417 = NULL;
fZM_DrawBar2D_QR ZM_DrawBar2D_QR = NULL;
fZM_DrawLineOr ZM_DrawLineOr = NULL;
fZM_DrawText ZM_DrawText = NULL;
fZM_SetDirection ZM_SetDirection = NULL;

//OSVERSIONINFO os;
 
///////////////////////////////

CXminPrinter::CXminPrinter(void)
{
}

CXminPrinter::~CXminPrinter(void)
{
}

bool printNew2_Xmin(const string& printStr,int X, int Y,int& id_name){
	char buff[0x100];
	int errorcode = 0;
	list<string> printv = splitPrintStr(printStr);
	int x = 0, y = 0, z = 0, ret = 0,XX = X + 135;
	char numBuff[10]={"dda"};
	static int num=1;
	for ( list<string>::iterator iter = printv.begin();iter != printv.end(); ++iter ){
		if( 0 == z ){ //打二维码
			sprintf(numBuff,"484%d",num++);
			
			if (strstr(iter->c_str(),"http") != NULL)
			{
				//ret = PTK_DrawBar2D_QR(X+134, Y, 0, 0, 0, 3, 4, 3, 3, (char*)iter->c_str());
				//ret = PTK_DrawBar2D_QREx(X+134,Y,0,4,0,0,3,(char *)numBuff,(char*)iter->c_str());//字符串长度限制导致无法正确扫描二维码，故选取该API，
				//AfxMessageBox("2");
				errorcode = ZM_DrawBar2D_QR(X + 214, Y + 23, 180, 180, 0, 3, 4, 3, 8, (char*)iter->c_str());
				//AfxMessageBox("2");
				if (errorcode != 0) {
				return false;
				}
				num=num%39;
			}
			else if(strlen(iter->c_str())<5){
				break;}
			else
			{
				//ret = PTK_DrawBar2D_QR(X+134, Y, 0, 0, 0, 4, 4, 3, 3, (char*)iter->c_str());
				//ret = PTK_DrawBar2D_QREx(X+120,Y,0,5,0,0,3,(char *)numBuff,(char*)iter->c_str());//字符串长度限制导致无法正确扫描二维码，故选取该API，
				errorcode = ZM_DrawBar2D_QR(X + 214+8, Y + 23+14, 180, 180, 0, 4, 4, 3, 8, (char*)iter->c_str());
				if (errorcode != 0) {
				return false;
				}
				num%=3;
			}
		
			if ( ret != 0 ){
				sprintf(buff,"PTK_DrawBar2D_QR:%d",ret);
				throw(buff);
			}
			
			y = Y + 190;
		}else if( 1 == z ){//打数字码
		
			list<string> printCodes = splitPrintv(string(*iter),28);
			int x = X;
			for ( list<string>::const_iterator citer = printCodes.begin(); citer != printCodes.end(); ++citer ){
			//	ret = PTK_DrawTextTrueTypeW(x, y, 17,0,"宋体", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)citer->c_str()); //x-100
				errorcode = ZM_DrawTextTrueTypeW(x+80, y, 18, 0, "宋体", 1, 600, 0, 0, 0, itoa(id_name++, buff, 10), (char*)citer->c_str());
				if ( ret != 0 ){
					sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
					throw(buff);
				}
				x += 64;
				y += 22;
			}
			*iter=iter->substr((iter->find( "溯源码:")!=-1?iter->find("溯源码:")+7:0),iter->length());
			//DelRecordByCode(citer->c_str(),DBPathName);
			DelRecordByCode(iter->c_str(),DBPathName);
		}else if( 2 == z || 4 == z || 6 == z || 7 == z||3 == z || 5 == z ){ //品名 产地 批号 厂家
			if( 3 == z){
				delchar((char *)iter->c_str(),' ');
				// *iter="重"+iter->substr(5,50);
			
			}//
			if (iter->length()==0)
			{
				z++;
				continue;
			}
			
			//else
		//	ret = PTK_DrawTextTrueTypeW(X, y, 17,0,"宋体", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)iter->c_str()); //x-100
			errorcode = ZM_DrawTextTrueTypeW(X + 80, y , 18, 0, "宋体", 1, 600, 0, 0, 0, itoa(id_name++, buff, 10), (char*)iter->c_str());
			if ( ret != 0 ){
				sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
				throw(buff);
			}
			
		//	if( 2 != z && 4 != z )
				y += 20;
		}
		#if 0
		else if(  5 == z ){ //重量  /*生产日期*/ 2015-6-23 取消药材打印日期
			if (z == 5)
			{
				//y+=22;
				z++;
				continue;
			}

		#if 0
			//ret = PTK_DrawTextTrueTypeW(XX, y, 17,0,"宋体", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)iter->c_str()); //x-100
			errorcode = ZM_DrawTextTrueTypeW(X + 90, y , 19, 0, "宋体", 1, 600, 0, 0, 0, itoa(id_name++, buff, 10), (char*)iter->c_str());
			if ( ret != 0 ){
				sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
				throw(buff);
			}
			y += 22;
			#endif
			
}
#endif
		
		z++;
	}
	
	return true;

}
bool printNew2_Xmin_1(const string& printStr,int X, int Y,int& id_name)

{
	char buff[0x100];
	list<string> printv = splitPrintStr(printStr);
	int x = 0, y = 0, z = 0, ret = 0,XX = X + 135;
	int numTextX=X,numTextY=120,numX=X+170,numY=216;
	char numBuff[10]={"sps"};
	static int num=0;
	
	for ( list<string>::iterator iter = printv.begin();iter != printv.end(); ++iter ){
		if( 0 == z ){ //打二维码
			sprintf(numBuff,"rfdf%d",num++);
			if (strstr(iter->c_str(),"http") != NULL)
			{
				//ret = PTK_DrawBar2D_QREx(X+180,Y+92,0,3,0,0,3,(char*)numBuff,(char*)iter->c_str());//字符串长度限制导致无法正确扫描二维码，故选取该API，
				num%=2;
			}
			else if(strlen(iter->c_str())<5){
				break;}
			else
			{
				
				//ret = PTK_DrawBar2D_QREx(X+180,Y+92,0,4,0,0,3,(char*)numBuff,(char*)iter->c_str());//"psk+1"字符串：调用一次打印机，同时（init与uninit之间）打印多张二维码（此处为两张）且与其他参数不一样时，每次需要该字符串唯一，
				num%=3;
			}
		
			if ( ret != 0 ){
				sprintf(buff,"PTK_DrawBar2D_QR:%d",ret);
				throw(buff);
			}
			
			y = Y;
		}else if( 1 == z ){//打数字码
			string num=iter->substr(7,50);
			list<string> printCodes = splitPrintv(num,16);
			
			for ( list<string>::const_iterator citer = printCodes.begin(); citer != printCodes.end(); ++citer ){
				//ret = PTK_DrawTextTrueTypeW(numX, numY, 12,0,"宋体", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)citer->c_str()); //x-100
				if ( ret != 0 ){
					sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
					throw(buff);
				}
				
				numY += 10;
			}
			*iter=iter->substr((iter->find( "溯源码:")!=-1?iter->find("溯源码:")+7:0),iter->length());
			DelRecordByCode(iter->c_str(),DBPathName);
		}else if( 2 == z || 4 == z || 6 == z || 7 == z ||3 == z || 5 == z){ //品名 产地 批号 厂家
			if( 7 == z){
				
				//if(strstr((char*)iter->c_str(),"厂家")!=NULL)
				//{
				//	*iter=iter->substr(5,50);
				//}
				*iter=iter->substr((iter->find( "厂家:")!=-1?iter->find("厂家:")+5:0),iter->length());
			}
			
				//ret = PTK_DrawTextTrueTypeW(numTextX, numTextY, 14,0,"宋体", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)iter->c_str()); //x-100
				if ( ret != 0 ){
					sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
					throw(buff);
				}
			
					numTextY += 20;
		}
#if 0
		else if( 3 == z || 5 == z ){ //重量  /*生产日期*/ 2015-6-23 取消药材打印日期
			if (z == 5)
			{
				y+=22;
				z++;
				continue;
			}
		//	ret = PTK_DrawTextTrueTypeW(XX, y, 20,0,"微软雅黑", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)iter->c_str()); //x-100
			if ( ret != 0 ){
				sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
				throw(buff);
			}
			y += 22;
		}
#endif
		z++;
	}
	return true;
}

bool printNew3_Xmin(const string& printStr,int X, int Y,int& id_name)
{
	char buff[0x100];
	list<string> printv = splitPrintStr(printStr);
	int y = 0,z = 0,ret = 0;
	bool flag = false;
	char numBuff[10]={"pskss"};
	static int num=1;
	int division=12;
	int offset_X=0,offset_Y=0;
	for ( list<string>::iterator iter = printv.begin();iter != printv.end(); ++iter ){
		if( 0 == z ){ //打二维码

			sprintf(numBuff,"hhkh%d",num++);
			if (strstr(iter->c_str(),"http") != NULL)
			{	
				ret = ZM_DrawBar2D_QR(X + 125, Y + 18, 90, 90, 0, 2, 4, 2, 8, (char*)iter->c_str());
				if ( ret != 0 ){
					sprintf(buff,"PTK_DrawBar2D_QR:%d",ret);
					throw(buff);
				}
				y = Y + 116;
				flag = true;					
				num=num%39;
			}
			else if(strlen(iter->c_str())<5){
				break;
			}
			else
			{
				
				ret = ZM_DrawBar2D_QR(X + 125, Y + 18, 90, 90, 0, 3, 4, 2, 8, (char*)iter->c_str());
				if ( ret != 0 ){
					sprintf(buff,"PTK_DrawBar2D_QR:%d",ret);
					throw(buff);
				}
				y = Y + 116;
				num=num%3;
			}
		}else if( 1 == z ){//打数字码
			*iter=iter->substr((iter->find( "溯源码:")!=-1?iter->find("溯源码:")+7:0),iter->length());
			//int offset_X=0;
			if (iter->c_str()[0]=='8')
			{
				division=20;
				offset_X=-102;offset_Y=32;
			}
			list<string> printCodes = splitPrintv(string(*iter),division);
			for ( list<string>::const_iterator citer = printCodes.begin(); citer != printCodes.end(); ++citer ){
				ret = ZM_DrawTextTrueTypeW(X + 125+offset_X, y, 14, 0, "宋体", 1, 600, 0, 0, 0, itoa(id_name++, buff, 10), (char*)citer->c_str());
				//ret = PTK_DrawTextTrueTypeW(X+106+offset_X, y, 14,0,"宋体", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)citer->c_str()); //x-100
				
				if ( ret != 0 ){
					sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
					throw(buff);
				}
				y += 16;
			}
			if (iter->c_str()[0]=='6')
			{
				offset_Y=-16;

			}
		
			 y = Y + 116+offset_Y;
			DelRecordByCode(iter->c_str(),DBPathName);
		}
		else{//其它文字
			if (2 == z)
			{
				delchar((char *)iter->c_str(),' ');
				
			}
			
			if (iter->length()==0)
			{
				z++;
				continue;
			}
			//ret = PTK_DrawTextTrueTypeW(X, y, 14,0,"宋体", 1, 600, 0, 0, 0, itoa(id_name++,buff,10), (char*)iter->c_str()); //x-100
			ret = ZM_DrawTextTrueTypeW(X + 28,y, 14, 0, "宋体", 1, 600, 0, 0, 0, itoa(id_name++, buff, 10),  (char*)iter->c_str());
			if ( ret != 0 ){
				sprintf(buff,"PTK_DrawTextTrueTypeW:%d",ret);
				throw(buff);
			}
			y += 16;
		}
		z++;
	}
	return true;
}

bool CXminPrinter::XminInit(char* printerName)
{
	 gt1Xmin = LoadLibrary("ZMWIN.dll");
	if (!gt1Xmin) {
		DWORD er = GetLastError();
		AfxMessageBox("找不到zmwin.dll");
		return false;
	}
	XOpenPort = (fXOpenPort)GetProcAddress(gt1Xmin, "OpenPort");
	XClosePort = (fXClosePort)GetProcAddress(gt1Xmin, "ClosePort");
	ZM_DrawBarcode = (fZM_DrawBarcode)GetProcAddress(gt1Xmin, "ZM_DrawBarcode");
	ZM_SetLabelHeight = (fZM_SetLabelHeight)GetProcAddress(gt1Xmin, "ZM_SetLabelHeight");
	ZM_PrintLabel = (fZM_PrintLabel)GetProcAddress(gt1Xmin, "ZM_PrintLabel");
	ZM_SetDarkness = (fZM_SetDarkness)GetProcAddress(gt1Xmin, "ZM_SetDarkness");
	ZM_SetPrintSpeed = (fZM_SetPrintSpeed)GetProcAddress(gt1Xmin, "ZM_SetPrintSpeed");
	ZM_SetLabelWidth = (fZM_SetLabelWidth)GetProcAddress(gt1Xmin, "ZM_SetLabelWidth");
	ZM_SetDirection = (fZM_SetDirection)GetProcAddress(gt1Xmin, "ZM_SetDirection");
	ZM_ClearBuffer = (fZM_ClearBuffer)GetProcAddress(gt1Xmin, "ZM_ClearBuffer");
	ZM_DrawTextTrueTypeW = (fZM_DrawTextTrueTypeW)GetProcAddress(gt1Xmin, "ZM_DrawTextTrueTypeW");
	ZM_DrawLineOr = (fZM_DrawLineOr)GetProcAddress(gt1Xmin, "ZM_DrawLineOr");
	ZM_DrawText = (fZM_DrawText)GetProcAddress(gt1Xmin, "ZM_DrawText");
	ZM_DrawBar2D_QR = (fZM_DrawBar2D_QR)GetProcAddress(gt1Xmin, "ZM_DrawBar2D_QR");
	ZM_DrawBar2D_Pdf417 = (fZM_DrawBar2D_Pdf417)GetProcAddress(gt1Xmin, "ZM_DrawBar2D_Pdf417");
	ZM_PcxGraphicsDel = (fZM_PcxGraphicsDel)GetProcAddress(gt1Xmin, "ZM_PcxGraphicsDel");
	ZM_PcxGraphicsDownload = (fZM_PcxGraphicsDownload)GetProcAddress(gt1Xmin, "ZM_PcxGraphicsDownload");
	ZM_DrawPcxGraphics = (fZM_DrawPcxGraphics)GetProcAddress(gt1Xmin, "ZM_DrawPcxGraphics");
	ZM_DrawRectangle = (fZM_DrawRectangle)GetProcAddress(gt1Xmin, "ZM_DrawRectangle");
	if (!XOpenPort || !XClosePort||!ZM_DrawTextTrueTypeW) {
		return false;
	}
	int ret = XOpenPort(printerName);	
		if ( ret != 0 ){
			AfxMessageBox("无法打开打印机");
			return false;
		}
		//AfxMessageBox("1");
		return true;
	//return true;
}
bool CXminPrinter::XminUnInit()
{
	XClosePort();
	FreeLibrary(gt1Xmin);
	return true;
}
int CXminPrinter::PrintXmin2(char* printerName,const string& printStr,LONG nPrintType)
{
	int rtn,id_name = 0;
	bool bIsPrint = false;
	char buff[0x100]={0};
	string printStr1, printStr2;
	splitStrTwo(printStr, printStr1, printStr2);
	
int ret=0;
int errorcode=0;
	try{
		//AfxMessageBox("1");
		errorcode = ZM_ClearBuffer();//清空打印机缓存
	errorcode = ZM_SetPrintSpeed(5);// 设置打印机打印速度;
	errorcode = ZM_SetDarkness(10);// 设置打印机打印温度;
	//AfxMessageBox("1");
	errorcode = ZM_SetLabelWidth(800);          // 设置标签的宽度；
	errorcode = ZM_SetLabelHeight(368, 40);// 设置标签的高度和行间隙大小；
	errorcode = ZM_SetDirection('B');//设置方向
		int X = 0,Y = -10;
		//打印左边
		if (printStr1.length() > 0 && (nPrintType == 1 || nPrintType == 3)){
			bIsPrint |= printNew2_Xmin(printStr1,X,Y,id_name);
		}

		//打印右边
		if (printStr2.length() > 0 && (nPrintType == 2 || nPrintType == 3)){
			bIsPrint |= printNew2_Xmin(printStr2,X+=360,Y,id_name);
		}
		//==================================
		ret = ZM_PrintLabel(1, 1);	
		if ( ret != 0 ){
			sprintf(buff,"PTK_PrintLabel:%d",ret);
			throw(buff);
		}
		//ClosePort();
		rtn = 1;
	}
	catch (const exception& e) {
		AfxMessageBox(e.what());
		rtn = 0;
	}
	catch (...) {
		sprintf(buff,"打印机错误:%d",GetLastError());
		AfxMessageBox(buff);
		rtn = 0;
	}
	//FreeLibrary(gt1Xmin);
	return rtn;
}
int CXminPrinter::PrintXmin2_1(char* printerName,const string& printStr,LONG nPrintType)
{
	int rtn,id_name = 0;
	bool bIsPrint = false;
	char buff[0x100]={0};
	string printStr1, printStr2;
	splitStrTwo(printStr, printStr1, printStr2);
	
int ret=0;
	try{
	

		int X = 80,Y = 23;
		//打印左边
		if (printStr1.length() > 0 && (nPrintType == 1 || nPrintType == 3)){
			bIsPrint |= printNew2_Xmin_1(printStr1,X,Y,id_name);
		}

		//打印右边
		if (printStr2.length() > 0 && (nPrintType == 2 || nPrintType == 3)){
			bIsPrint |= printNew2_Xmin_1(printStr2,X+=360,Y,id_name);
		}
		//==================================
		ret = ZM_PrintLabel(1, 1);	
		if ( ret != 0 ){
			sprintf(buff,"PTK_PrintLabel:%d",ret);
			throw(buff);
		}
		//ClosePort();
		rtn = 1;
	}
	catch (const exception& e) {
		AfxMessageBox(e.what());
		rtn = 0;
	}
	catch (...) {
		sprintf(buff,"打印机错误:%d",GetLastError());
		AfxMessageBox(buff);
		rtn = 0;
	}
	//FreeLibrary(gt1Xmin);
	return rtn;
}


int CXminPrinter::PrintXmin3(char* printerName,const string& printStr,LONG nPrintType)
{
	int rtn,id_name = 0;
	bool bIsPrint = false;
	char buff[0x100]={0};
	
	string printStr1, printStr2,printStr3;
	splitStrThree(printStr, printStr1, printStr2, printStr3);

	AFX_MANAGE_STATE(AfxGetStaticModuleState());
int ret=0;
	int errorcode=0;
	try{
		errorcode = ZM_ClearBuffer();//清空打印机缓存
	errorcode = ZM_SetPrintSpeed(5);// 设置打印机打印速度;
	errorcode = ZM_SetDarkness(10);// 设置打印机打印温度;
	
	errorcode = ZM_SetLabelWidth(800);          // 设置标签的宽度；
	errorcode = ZM_SetLabelHeight(200, 24);// 设置标签的高度和行间隙大小；
	errorcode = ZM_SetDirection('B');
		//int X = 42,Y = 10;//old
		int X = 24,Y = -8;//new
		//sprintf(numBuff,"%d",num++)
		//打印左边
		if (printStr1.length() > 0 && (nPrintType == 1 || nPrintType == 4)){
			bIsPrint |= printNew3_Xmin(printStr1,X,Y,id_name);
		}

		//打印中间
		if (printStr2.length() > 0 && (nPrintType == 2 || nPrintType == 4)){
			bIsPrint |= printNew3_Xmin(printStr2,X+=260,Y,id_name);
		}

		//打印右边
		if (printStr3.length() > 0 && (nPrintType == 3 || nPrintType == 4)){
			bIsPrint |= printNew3_Xmin(printStr3,X+=260,Y,id_name);
		}
		//==================================
		if (bIsPrint){
			ret =ZM_PrintLabel(1, 1);	
			if ( ret != 0 ){
				sprintf(buff,"PTK_PrintLabel:%d",ret);
				throw(buff);
			}
		}
	
		rtn = 1;
	}
	catch (const exception& e) {
		AfxMessageBox(e.what());
		rtn = 0;
	}
	catch (...) {
		sprintf(buff,"打印机错误:%d",GetLastError());
		AfxMessageBox(buff);
		rtn = 0;
	}
	
	return rtn;
}