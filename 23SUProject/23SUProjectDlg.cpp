
// 23SUProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "23SUProject.h"
#include "23SUProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MSGBOX_TITLE "Los Pollos Hermanos - Branch1"

CString productNames[] = { "Tortillas", "Refried Beans", "Salsa", "Nacho Chips", "Jalapenos", "Green Peppers", "Monterey Jack Cheese", "Rice", "Ground Beef", "Eggs" };
CString currentInventory[] = { "256", "402", "515", "712", "90,210", "1024", "32,767", "911", "420", "4450" };

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C23SUProjectDlg dialog



C23SUProjectDlg::C23SUProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_23SUPROJECT_DIALOG, pParent)
	, m_strDebug(_T(""))
	, m_strProductNumber(_T(""))
	, m_strProductName(_T(""))
	, m_strInventory(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C23SUProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_DEBUG, m_strDebug);
	DDX_Text(pDX, IDC_EDIT_PRODUCT_NUMBER, m_strProductNumber);
	DDV_MaxChars(pDX, m_strProductNumber, 10);
	DDX_Text(pDX, IDC_STATIC_PRODUCT_NAME, m_strProductName);
	DDX_Text(pDX, IDC_STATIC_INVENTORY, m_strInventory);
}

BEGIN_MESSAGE_MAP(C23SUProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &C23SUProjectDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// C23SUProjectDlg message handlers

BOOL C23SUProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	if (IsDebuggerPresent())
	{
		m_strDebug = "Oooh, do you smell that? I think it's be a debugger!";
		UpdateData(false);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void C23SUProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void C23SUProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR C23SUProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C23SUProjectDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	UpdateData(true);	// this pulls the text entered in the "Product Number" field into m_strProductNumber
	if (m_strProductNumber.GetLength() <= 0)
	{
		MessageBox("Hola amigo, enter a product number, por favor", MSGBOX_TITLE);
		return;
	} 

	WorkerFunction();

}


int C23SUProjectDlg::WorkerFunction()
{
	// TODO: Add your implementation code here.
	// 
	//
	// generate a random number 
	//
	srand((unsigned int)time(0));

	ULONGLONG ticksStart = GetTickCount64();
	ULONGLONG ticksEnd;
	int idx = 0;
	int x = rand() % 10;
	char tmp[128];

	//
	// just a loop
	//
	for (int n = 0; n < m_strProductNumber.GetLength(); n++)
	{
		_strtime_s(tmp, sizeof(tmp));
		OutputDebugString(tmp);
		sprintf_s(tmp, sizeof(tmp), " debug string, x=%d, n=%d\n", x, n);
		OutputDebugString(tmp);
	} // for

	//
	// Reset display values
	//
	m_strProductName = "";
	m_strInventory = "";

	//
	// Validate product number
	//
	idx = ValidationFunction();
	if (idx != -1)
	{
		// move values from arrays to control variables
		m_strProductName = productNames[idx];
		m_strInventory = currentInventory[idx];
	} // if

	//
	// moves the value from the display variables to
	// their corresponding dialog controls for display
	//
	UpdateData(false);

	//
	// calculate ticks since beginning of function
	// a large differnce indicates debugging or other
	// process impacting execution
	//
	ticksEnd = GetTickCount64();
	sprintf_s(tmp, sizeof(tmp), "WorkerFunction elapsed ticks %I64d\n", ticksEnd - ticksStart);
	OutputDebugString(tmp);

	return 0;
}


int C23SUProjectDlg::ValidationFunction()
{
	// TODO: Add your implementation code here.
	int sum = 0;
	int n = 0;
	int ch;

	//
	// calculate check digit, positions - through len-1
	// multiply even positions by 2, add to sum
	// add odd positions to sum
	// at end, mod 10 the sum
	// subtract the remainder from 10
	// the resulting value should equal last digit in number
	// return the number, which will be the index into the
	//  product and inventory arrays, else display message
	//  and return -1
	//
	for (int x = 0; x < m_strProductNumber.GetLength() - 1; x++)
	{
		ch = m_strProductNumber.GetAt(x) - '0';
		if (x % 2 == 0)
			sum += CalcEven(ch);
		else
			sum += CalcOdd(ch);
	}

	ch = (m_strProductNumber.GetAt(m_strProductNumber.GetLength() - 1)) - '0';
	if (CalcCheckDigit(sum) == ch)
		return(ch);

	MessageBox("Oh no mi amigo, that is not a valid product number, retry, por favor", MSGBOX_TITLE);

	return(-1);
}


int C23SUProjectDlg::CalcOdd(int digitIn)
{
	// TODO: Add your implementation code here.
	int n;

	n = digitIn * 1;

	return(n);
}


int C23SUProjectDlg::CalcEven(int digitIn)
{
	// TODO: Add your implementation code here.
	int n;

	n = digitIn * 2;
	if (n > 9) n -= 9;
	
	return(n);
}


int C23SUProjectDlg::CalcCheckDigit(int sumIn)
{
	// TODO: Add your implementation code here.
	int n; 

	n = sumIn % 10;

	return(10 - n);

}
