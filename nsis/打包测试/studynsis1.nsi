!include "MUI.nsh"

!define PRODUCT_NAME "����"
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
!define MUI_WELCOMEPAGE_TEXT "NSIS ��ϰ\nNSIS ��ϰ\nNSIS ��ϰ"
; ����Ϊ����14����
SetFont ���� 14
BrandingText "NSIS������� ${__TIMESTAMP__}"
InstallColors /windows ;��װ��Ϣ����ɫ

/*
; �򵥵ļ�����ϵͳ�İ汾��
Function .onInit
ReadRegStr $R0 HKLM "SOFTWARE\Microsoft\Windows NT\CurrentVersion" CurrentVersion
StrCmp $R0 "5.1" startinst
StrCmp $R0 "5.2" startinst
MessageBox MB_OK "�˳���ֻ�������� Microsoft Windows XP �£�$\n$\n���� [ȷ��] ��ť�˳��˰�װ����."
Abort
startinst:
FunctionEnd
*/

Function .onInit
MessageBox MB_OK "���� [ȷ��] ��ť."
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
OutFile "����.exe"

Section "������"
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