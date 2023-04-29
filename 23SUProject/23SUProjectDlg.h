
// 23SUProjectDlg.h : header file
//

#pragma once


// C23SUProjectDlg dialog
class C23SUProjectDlg : public CDialogEx
{
// Construction
public:
	C23SUProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_23SUPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strDebug;
	afx_msg void OnBnClickedOk();
	int WorkerFunction();
	CString m_strProductNumber;
	CString m_strProductName;
	CString m_strInventory;
protected:
	int ValidationFunction();
	int CalcCheckDigit(int sumIn);
	int CalcEven(int digitIn);
	int CalcOdd(int digitIn);
};
