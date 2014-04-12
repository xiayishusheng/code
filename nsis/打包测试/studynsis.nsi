!include "MUI.nsh"
!include "StrFunc.nsh"
!include "Library.nsh"

!define PRODUCT_NAME "产品名称"
!define PRODUCT_VERSION "版本号1.0"
!define PRODUCT_PUBLISHER "发布者"
!define PRODUCT_WEB_SITE "www.xiayishusheng.howbbs.com"
Name ${PRODUCT_NAME} ${PRODUCT_VERSION}

SetFont 宋体 14                                          ; 设置为宋体14号字
!define MUI_ICON "pics\windows.ico"						 ; 安装程序图标
!define MUI_UNICON "pics\uninstall.ico"					 ; 卸载程序图标

!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "pics\header.bmp"		 ; 安装程序图片
!define MUI_HEADERIMAGE_UNBITMAP  "pics\header.bmp"
!define MUI_WELCOMEFINISHPAGE_BITMAP "pics\startlogo.bmp"; 安装程序右边图标
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "pics\startlogo.bmp"

!define MUI_WELCOMEPAGE_TITLE "安装向导欢迎界面"
!define MUI_WELCOMEPAGE_TEXT "安装向导。"

!define MUI_PAGE_HEADER_TEXT "License许可协议标题头信息"
!define MUI_PAGE_HEADER_SUBTEXT "License许可协议子标题信息"
!define MUI_LICENSEPAGE_TEXT_TOP "License上方信息"
!define MUI_LICENSEPAGE_TEXT_BOTTOM "License下方信息"

InstallDir "$PROGRAMFILES\NsisTest"						 ; 设置默认安装路径

BrandingText "NSIS打包测试 ${__TIMESTAMP__}"			 ; 安装程序时底部显示的信息

!insertmacro MUI_PAGE_WELCOME                            ; 该向导页面显示欢迎信息
!insertmacro MUI_PAGE_LICENSE "resource\License.txt"     ; 该向导页面显示软件授权申明
!insertmacro MUI_PAGE_COMPONENTS                         ; 该向导页面显示安装组件选择
!insertmacro MUI_PAGE_DIRECTORY                          ; 该向导页面显示安转目录选择
!insertmacro MUI_PAGE_INSTFILES                          ; 该向导页面显示安装进度
!insertmacro MUI_PAGE_FINISH                             ; 该向导页面显示安装结束
!insertmacro MUI_LANGUAGE "SimpChinese"                  ; Language files

Function .onInit
;MessageBox MB_OK "$PROGRAMFILES"
;Abort
FunctionEnd

; Out Put File
OutFile "测试.exe"

Section "主程序" SEC01
; some commands
MessageBox MB_OK "主程序"
SectionEnd

Section "可选程序" SEC02
; some commands
MessageBox MB_OK "可选程序"
SectionEnd

Section "un.Uninstaller Section"
; some commands
SectionEnd