// HelloWorld.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HelloWorld.h"
#include "Fraction.h"
#include "Calculate.h"
#include <string>
#include <iostream>
#include <sstream>

#define MAX_LOADSTRING 100



// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    FracCalc(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_HELLOWORLD, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HELLOWORLD));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HELLOWORLD));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HELLOWORLD);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
			case IDM_FRACCALC:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_FRACCALC), hWnd, FracCalc);
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
INT_PTR CALLBACK FracCalc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	const int textLen = 50;
	WCHAR text[textLen];
	int input, output;
	//LPWSTR inputString = NULL;
	//LPWSTR outputString = NULL;
    LPWSTR inputWide = NULL;
    LPSTR outputString = NULL;
    LPWSTR outputWide = NULL;
    LPSTR inputString = NULL;

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;


		case IDC_CALCULATE:
			GetDlgItemTextW(hDlg, IDC_INPUTBOX, text, textLen);
			wscanf_s(text, L"^-? ((\\d + ) ? \\d + / \\d + | \\d + )", &inputString);  //set to regex input the calculator takes.
			//WideCharToMultiByte(CP_UTF8, 0, inputString, -1, NULL, 0, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, inputWide, -1, inputString, 0, NULL, NULL);
            MultiByteToWideChar(CP_ACP, 0, outputString, -1, outputWide, NULL);
            //wsprintf(text, outputString);
			outputString = inputString;
			//wsprintf(text, L"%i", output);
			SetDlgItemTextW(hDlg, IDC_OUTPUTBOX, text);
			return (INT_PTR)true;
			
			
			/*
			MessageBoxW(hDlg, L"Calculate Clicked", L"Alert", MB_OK);
			return (INT_PTR)TRUE;
			*/

		case IDC_TESTBUTTON:
			MessageBoxW(hDlg, L"test Clicked", L"Alert", MB_OK);
			return (INT_PTR)TRUE;
			
		}
		break;
	}
	return (INT_PTR)FALSE;
}



/*
//cStringW -> cStringA

CStringA ConvertUnicodeToUTF8(const CStringW& uni)
{
if (uni.IsEmpty()) return ""; // nothing to do
CStringA utf8;
int cc=0;
// get length (cc) of the new multibyte string excluding the \0 terminator first
if ((cc = WideCharToMultiByte(CP_UTF8, 0, uni, -1, NULL, 0, 0, 0) - 1) > 0)
{
// convert
char *buf = utf8.GetBuffer(cc);
if (buf) WideCharToMultiByte(CP_UTF8, 0, uni, -1, buf, cc, 0, 0);
utf8.ReleaseBuffer();
}
return utf8;
}




//cstringa -> Cstringw
CStringW ConvertUTF8ToUnicode(const CStringA& utf8)
{
if (utf8.IsEmpty()) return L""; // nothing to do
CStringW uni;
int cc=0;
// get length (cc) of the new widechar excluding the \0 terminator first
if ((cc = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0) - 1) > 0)
{
// convert
wchar_t *buf = uni.GetBuffer(cc);
if (buf) MultiByteToWideChar(CP_UTF8, 0, utf8, -1, buf, cc);
uni.ReleaseBuffer();
}
return uni;
}







*/
