#include "Program4.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main() {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Program4::Program4 form;
   Application::Run(%form);
}