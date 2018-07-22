#pragma once
#ifndef XMIN_PRINTER_H
#define XMIN_PRINTER_H
#include "Funcs.h"


class CXminPrinter
{
public:
	CXminPrinter(void);
	~CXminPrinter(void);

	bool XminInit(char* printerName);
	bool XminUnInit();
	int PrintXmin2(char* printerName,const string& printStr,LONG nPrintType);
	int PrintXmin2_1(char* printerName,const string& printStr,LONG nPrintType);
	int PrintXmin3(char* printerName,const string& printStr,LONG nPrintType);
};

#endif
