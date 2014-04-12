OutFile "ScreenRes.exe"
Name "Get User Screen Resolution"
Caption "Screen Resolution"
XPStyle "on"

Function ".onInit"
System::Call 'user32::GetSystemMetrics(i 0) i .r0'
System::Call 'user32::GetSystemMetrics(i 1) i .r1'
MessageBox MB_OK|MB_ICONINFORMATION "Screen Resolution: $\r$\n$0 X $1"
Quit
FunctionEnd

Section "-boo"
SectionEnd