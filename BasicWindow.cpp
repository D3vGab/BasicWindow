#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wndclass;

	// Definindo a classe "BasicWindow"
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WinProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = "BasicWindow";

	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, "Erro na criação da janela!", "Erro", MB_ICONERROR);

		return 0;
	}
	// Criando a janela

	hwnd = CreateWindow(
		"BasicWindow",				// Classe
		"Aplicação",				// Título
		WS_OVERLAPPEDWINDOW,		// Tipo de janela
		CW_USEDEFAULT,				// Posição x inicial
		CW_USEDEFAULT,				// Posição y inicial
		CW_USEDEFAULT,				// Largura inicial
		CW_USEDEFAULT,				// Altura Inicial
		NULL,						// Identificador da janela pai
		NULL,						// Identificador do menu
		hInstance,					// Identificador da aplicação
		NULL);						// Parâmetros de criação

	// Mostra e atualiza a janela
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);


	// Tratamento das mensagens destinadas à janela

	while (GetMessage(&msg, NULL, NULL, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return int(msg.wParam);
}
	// Procedimentos da janela

	LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
		HDC					hdc;	// Representa o dispositivo grafico
		PAINTSTRUCT			ps;		// Região invalidada da janela
		RECT				rect;	// Retângulo

		switch (message) {

			case WM_PAINT:
				hdc = BeginPaint(hwnd, &ps);

				GetClientRect(hwnd, &rect);
				DrawText(hdc, "Hello Dev Gab, Good Job!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

				EndPaint(hwnd, &ps);

				return 0;

			case WM_DESTROY:
				PostQuitMessage(0);

			return 0;
		}
		return DefWindowProc(hwnd, message, wParam, lParam);
	}