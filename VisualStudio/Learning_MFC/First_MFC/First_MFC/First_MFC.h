
// First_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFirst_MFCApp: 
// �йش����ʵ�֣������ First_MFC.cpp
//

class CFirst_MFCApp : public CWinApp
{
public:
	CFirst_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFirst_MFCApp theApp;