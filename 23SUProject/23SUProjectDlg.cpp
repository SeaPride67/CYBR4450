
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
		m_strDebug = "Beware! Someone is picking you apart with a debugger!";
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
	if (m_strProductNumber.GetLength() > 0)
		WorkerFunction();
	else
		MessageBox("Hola amigo, enter a product number, por favor");

}


int C23SUProjectDlg::WorkerFunction()
{
	// TODO: Add your implementation code here.
	ULONGLONG ticksStart = GetTickCount64();
	ULONGLONG ticksEnd;

	//
	// generate a random number as an index into the product and quantity arrays
	//
	char tmp[128];
	srand((unsigned int)time(0));
	int x = rand() % 10;

	//
	// just a loop
	//
	for (int n = 0; n < m_strProductNumber.GetLength(); n++)
	{
		_strtime_s(tmp, sizeof(tmp));
		OutputDebugString(tmp);
		sprintf_s(tmp, " debug string, x=%d, n=%d\n", x, n);
		OutputDebugString(tmp);
	} // for

	//
	// move values from arrays to control variables
	//
	m_strProductName = productNames[x];
	m_strInventory = currentInventory[x];

	//
	// move the values in the above variables to 
	// their corresponding dialog controls for display
	//
	UpdateData(false);

	//
	// calculate ticks since beginning of function
	// a large differnce indicates debugging or other
	// process impacting execution
	//
	ticksEnd = GetTickCount64();
	sprintf_s(tmp, "WorkerFunction elapsed ticks %I64d\n", ticksEnd - ticksStart);
	OutputDebugString(tmp);

	return 0;
}
