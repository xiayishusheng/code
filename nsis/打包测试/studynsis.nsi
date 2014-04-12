!include "MUI.nsh"
!include "StrFunc.nsh"
!include "Library.nsh"

!define PRODUCT_NAME "��Ʒ����"
!define PRODUCT_VERSION "�汾��1.0"
!define PRODUCT_PUBLISHER "������"
!define PRODUCT_WEB_SITE "www.xiayishusheng.howbbs.com"
Name ${PRODUCT_NAME} ${PRODUCT_VERSION}

SetFont ���� 14                                          ; ����Ϊ����14����
!define MUI_ICON "pics\windows.ico"						 ; ��װ����ͼ��
!define MUI_UNICON "pics\uninstall.ico"					 ; ж�س���ͼ��

!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "pics\header.bmp"		 ; ��װ����ͼƬ
!define MUI_HEADERIMAGE_UNBITMAP  "pics\header.bmp"
!define MUI_WELCOMEFINISHPAGE_BITMAP "pics\startlogo.bmp"; ��װ�����ұ�ͼ��
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "pics\startlogo.bmp"

!define MUI_WELCOMEPAGE_TITLE "��װ�򵼻�ӭ����"
!define MUI_WELCOMEPAGE_TEXT "��װ�򵼡�"

!define MUI_PAGE_HEADER_TEXT "License���Э�����ͷ��Ϣ"
!define MUI_PAGE_HEADER_SUBTEXT "License���Э���ӱ�����Ϣ"
!define MUI_LICENSEPAGE_TEXT_TOP "License�Ϸ���Ϣ"
!define MUI_LICENSEPAGE_TEXT_BOTTOM "License�·���Ϣ"

InstallDir "$PROGRAMFILES\NsisTest"						 ; ����Ĭ�ϰ�װ·��

BrandingText "NSIS������� ${__TIMESTAMP__}"			 ; ��װ����ʱ�ײ���ʾ����Ϣ

!insertmacro MUI_PAGE_WELCOME                            ; ����ҳ����ʾ��ӭ��Ϣ
!insertmacro MUI_PAGE_LICENSE "resource\License.txt"     ; ����ҳ����ʾ�����Ȩ����
!insertmacro MUI_PAGE_COMPONENTS                         ; ����ҳ����ʾ��װ���ѡ��
!insertmacro MUI_PAGE_DIRECTORY                          ; ����ҳ����ʾ��תĿ¼ѡ��
!insertmacro MUI_PAGE_INSTFILES                          ; ����ҳ����ʾ��װ����
!insertmacro MUI_PAGE_FINISH                             ; ����ҳ����ʾ��װ����
!insertmacro MUI_LANGUAGE "SimpChinese"                  ; Language files

Function .onInit
;MessageBox MB_OK "$PROGRAMFILES"
;Abort
FunctionEnd

; Out Put File
OutFile "����.exe"

Section "������" SEC01
; some commands
MessageBox MB_OK "������"
SectionEnd

Section "��ѡ����" SEC02
; some commands
MessageBox MB_OK "��ѡ����"
SectionEnd

Section "un.Uninstaller Section"
; some commands
SectionEnd