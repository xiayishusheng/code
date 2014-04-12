!include "MUI.nsh"

!define PRODUCT_NAME "测试"
!define PRODUCT_VERSION "1.0"
!define PRODUCT_PUBLISHER "company"
!define PRODUCT_WEB_SITE "www.xiayishusheng.howbbs.com"

!define MUI_ICON "pics\windows.ico"
!define MUI_UNICON "pics\uninstall.ico"
;!define MUI_HEADERIMAGE "pics\header.bmp"
!define MUI_HEADERIMAGE_BITMAP "pics\header.bmp"
;!define MUI_HEADERIMAGE_UNBITMAP  "pics\header.bmp"
!define MUI_WELCOMEFINISHPAGE_BITMAP "pics\startlogo.bmp"
;!define MUI_UNWELCOMEFINISHPAGE_BITMAP "pics\startlogo.bmp"
!define MUI_WELCOMEPAGE_TEXT "NSIS 练习\nNSIS 练习\nNSIS 练习"
; 设置为宋体14号字
SetFont 宋体 14
BrandingText "NSIS打包测试 ${__TIMESTAMP__}"
InstallColors /windows ;安装信息的颜色

/*
; 简单的检测操作系统的版本号
Function .onInit
ReadRegStr $R0 HKLM "SOFTWARE\Microsoft\Windows NT\CurrentVersion" CurrentVersion
StrCmp $R0 "5.1" startinst
StrCmp $R0 "5.2" startinst
MessageBox MB_OK "此程序只能运行在 Microsoft Windows XP 下！$\n$\n请点击 [确定] 按钮退出此安装程序."
Abort
startinst:
FunctionEnd
*/

Function .onInit
MessageBox MB_OK "请点击 [确定] 按钮."
Abort
FunctionEnd

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "resource\License.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Directory components
!insertmacro MUI_PAGE_COMPONENTS
; Directory page
!insertmacro MUI_PAGE_DIRECTORY

;Page license
;Page directory
;Page components
;Page instfiles

; Language files
!insertmacro MUI_LANGUAGE "SimpChinese"

; Out Put File
OutFile "测试.exe"

Section "主程序"
; some commands
SectionEnd

Section "un.Uninstaller Section"
; some commands
SectionEnd

/*
Function MyFunction
; some commands
FunctionEnd
*/