﻿// OptionDlg.h : header file
//

#if !defined(AFX_OPTIONDLG_H__4A33FB17_F101_4D7A_ABAB_CC542891E12D__INCLUDED_)
#define AFX_OPTIONDLG_H__4A33FB17_F101_4D7A_ABAB_CC542891E12D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COptionDlg dialog
struct __GameOption
{
	int		iTexLOD_Chr;		// Texture LOD
	int		iTexLOD_Shape;		// Texture LOD
	int		iTexLOD_Terrain;	// Texture LOD
	int		iUseShadow;			// 그림자 사용 0 사용안함 1 사용
	int		iViewDist;			// 가시거리..
	int		iViewWidth;			// 화면 길이
	int		iViewHeight;		// 화면 너비
	int		iViewColorDepth;	// 색상수..
	int		iEffectSndDist;		// 이펙트 사운드 거리
	bool	bSndDuplicated;		// 중복된 음원 사용
	bool	bSoundEnable;		// 사운드 사용
	bool	bWindowCursor;		// 윈도우 커서 사용

	void InitDefault()
	{
		iUseShadow = true;
		iTexLOD_Chr = 0;
		iTexLOD_Shape = 0;
		iTexLOD_Terrain = 0;
		iViewColorDepth = 16;
		iViewWidth = 1024;
		iViewHeight = 768;
		iViewDist = 512;
		iEffectSndDist = 48;
		bSndDuplicated = false;
		bSoundEnable = true;
		bWindowCursor = true;
	}

	__GameOption() { InitDefault(); }
};

class COptionDlg : public CDialog
{
protected:
	CString m_szInstalledPath;
	CString m_szExeName;
	__GameOption m_Option;

// Construction
public:
	void SettingUpdate();
	void SettingLoad(CString szIniFile);
	void SettingSave(CString szIniFile);
	COptionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COptionDlg)
	enum { IDD = IDD_OPTION_DIALOG };
	CSliderCtrl	m_SldEffectSoundDist;
	CComboBox	m_CB_ColorDepth;
	CComboBox	m_CB_Resolution;
	CSliderCtrl	m_SldViewDist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COptionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBApplyAndExecute();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBVersion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONDLG_H__4A33FB17_F101_4D7A_ABAB_CC542891E12D__INCLUDED_)
