/// QuotePDF
/// M. H. Beals (2017) v.1.0.6 [Software]

/// MIT License
/// Copyright(c) 2017 M. H. Beals
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files(the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions :
/// The above copyright notice and this permission notice shall be included in all
/// copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#include "stdafx.h"
#include "Main.h"
#include "C_PDFQuotation.h"
#include "C_Citations.h"

#define MAX_LOADSTRING 100

// Global Menu Variables
HWND hInput;
HWND hOutput;
HWND hAuthor;
HWND hTitle;
HWND hYear;
HWND hPage;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

												// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void				AddMenus(HWND);
void				AddControls(HWND);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_QuotePDF, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_QuotePDF));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_QuotePDF));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_QuotePDF);	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		AddControls(hWnd);
		AddMenus(hWnd);
	}
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case 1:
		{
			C_PDFQuotation PDFQuotation;
			PDFQuotation.RemoveLineBreaks();
			break;
		}
		case 2:
		{
			C_PDFQuotation PDFQuotation;
			PDFQuotation.RemoveCitations();
			break;
		}
		case 3:
		{
			C_PDFQuotation PDFQuotation;
			PDFQuotation.RemoveFootnotes();
			break;
		}
		case 4:
		{
			C_Citations Citation;
			
			GetWindowTextW(hPage, Citation.w_pageBuffer, 25);
			Citation.parsePageNumber(true);
			SetWindowTextW(hPage, Citation.w_pageBuffer);
			break;
		}
		case 5:
		{
			C_Citations Citation;
			
			GetWindowTextW(hPage, Citation.w_pageBuffer, 25);
			Citation.parsePageNumber(false);
			SetWindowTextW(hPage, Citation.w_pageBuffer);
			break;
		}
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


void AddMenus(HWND hWnd)
{
	// Create File sub-menu
	HMENU hMenu;
	HMENU hFileMenu = CreateMenu();
	AppendMenuW(hFileMenu, MF_STRING, IDM_ABOUT, L"About");
	AppendMenuW(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenuW(hFileMenu, MF_STRING, IDM_EXIT, L"Exit");

	// Create main menu
	hMenu = CreateMenu();
	AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");

	// Draw the menus
	SetMenu(hWnd, hMenu);
};

// Function to create buttons and boxes
void AddControls(HWND hWnd)
{
	hInput = CreateWindowW(L"edit", L"To remove line breaks from a piece of copied text,\r\nsimply paste the text into this box and press\r\n\"Line Breaks\".\r\n\r\nOnce you have removed the line breaks, you can also remove in-text citations or footnotes by pressing the\r\nappropriate button(s).\r\n\r\nPage numbers can be entered in arabic (1, 2, 3) or \r\nroman (i, ii, iii) numerals, and incremented using the +/- buttons.", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOVSCROLL | ES_MULTILINE, 50, 25, 400, 415, hWnd, NULL, NULL, NULL);
	hOutput = CreateWindowW(L"edit", L"Your text will appear here, with quotation marks and a\r\ncitation attached.", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOVSCROLL | ES_MULTILINE, 460, 25, 400, 415, hWnd, NULL, NULL, NULL);

	hAuthor = CreateWindowW(L"edit", L"Name", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 870, 25, 100, 25, hWnd, NULL, NULL, NULL);
	hTitle = CreateWindowW(L"edit", L"Title", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 870, 55, 100, 25, hWnd, NULL, NULL, NULL);
	hYear = CreateWindowW(L"edit", L"Year", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 870, 85, 100, 25, hWnd, NULL, NULL, NULL);
	hPage = CreateWindowW(L"edit", L"##", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 870, 115, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"BUTTON", L"+", WS_VISIBLE | WS_CHILD, 975, 115, 10, 10, hWnd, (HMENU)4, NULL, NULL);
	CreateWindowW(L"BUTTON", L"-", WS_VISIBLE | WS_CHILD, 975, 127, 10, 10, hWnd, (HMENU)5, NULL, NULL);

	CreateWindowW(L"BUTTON", L"Line Breaks", WS_VISIBLE | WS_CHILD, 870, 170, 100, 50, hWnd, (HMENU)1, NULL, NULL);
	CreateWindowW(L"BUTTON", L"Citations", WS_VISIBLE | WS_CHILD, 870, 225, 100, 50, hWnd, (HMENU)2, NULL, NULL);
	CreateWindowW(L"BUTTON", L"Footnotes", WS_VISIBLE | WS_CHILD, 870, 280, 100, 50, hWnd, (HMENU)3, NULL, NULL);
}
