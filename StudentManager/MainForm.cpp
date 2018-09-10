#include "MainForm.h"
#include "Win32.h"



using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array <String^> ^ args) {
#ifdef _DEBUG
	Win32::AllocConsole();
#endif // _DEBUG

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	StudentManager::MainForm form;
	Application::Run(%form);

#ifdef _DEBUG
	Win32::FreeConsole();
#endif // _DEBUG
	return 0;
}