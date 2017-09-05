// Down.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <windows.h>

int createSocket()
{
	int sock;
	int connresult =0; //连接服务器结果
	struct sockaddr_in server;
	struct hostent *server_hosten;

	u_short port = 80;
	char *serverip ;
	//http://www.12306.cn/mormhweb/ggxxfw/wbyyzj/201106/srca12306.zip


	char *host ="www.12306.cn";//需连接的主机


	char sendBuffer[1025];
	char recvBuffer[6001];
	FILE *fp;
	char *offset =0;
	char *lenbegin =0;
	char *lenend =0;

	char *savePath ="srca12306.zip";

	int w_send = 0;//发送的字节
	int result = 0;

	//初始化socket 
	WSADATA wsaData;
	int wsaret=WSAStartup(0x101,&wsaData);
	if(wsaret !=0)
	{
		exit(EXIT_FAILURE);
		return 0 ;
	} 

	//该函数调用前必须调用WSAStartup
	server_hosten = gethostbyname(host);
	serverip =inet_ntoa(*(struct in_addr *)server_hosten->h_addr_list[0]);


	memset((char*)&server,0,sizeof(server));

	memset(sendBuffer,0,1024);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(serverip);
	server.sin_port =htons(port);

	if((sock = socket(AF_INET,SOCK_STREAM,0)) == INVALID_SOCKET)
	{
		printf("socket create error %s",strerror(errno));
		exit(0);
	}
	connresult =connect(sock,(struct sockaddr *)&server,sizeof(server));
	printf("开始连接服务器.......\n");
	if(SOCKET_ERROR == connresult)
	{
		printf("连接服务器失败%s\n",strerror(errno));
		exit(0);
	}else
	{
		printf("已连接上服务器:%s,IP:%s\n",host,serverip);
		printf("开始请求.....\n");
	}

	strcat(sendBuffer,"GET ");
	strcat(sendBuffer," /mormhweb/ggxxfw/wbyyzj/201106/srca12306.zip ");

	strcat(sendBuffer," HTTP/1.1");
	strcat(sendBuffer,"\r\n");

	strcat(sendBuffer,"Host:");
	strcat(sendBuffer,host);
	strcat(sendBuffer,"\r\n");
	strcat(sendBuffer,"Accept:*/*");
	strcat(sendBuffer,"\r\n");
	//strcat(sendBuffer,"Connection:close");
	
	strcat(sendBuffer,"Connection:Keep-Alive");
	strcat(sendBuffer,"\r\n");

	strcat(sendBuffer,"\r\n");
	/*sendBuffer = "GET /img/baidu_logo.gif HTTP/1.1\r\n \
	Host: www.baidu.com\r\n \
	Accept: *\r\n \
	Connection:close\r\n\r\n";
	*/
	printf("%s\n",sendBuffer);

	w_send =send(sock,sendBuffer,strlen(sendBuffer),0);
	if(w_send <=0)
	{
		printf("与服务器断开\n");
		exit(0);
	}
	else{
		printf("发送请求了,正在接受数据......\n");
	}

	fp =fopen(savePath,"wb"); //靠,卡在这里好久,原因是在写文件的时候老是多一个换行.后面抓包比对才看到的,只不过,找不出这从那里来,把写入格式改成"wb"(以前是w)就行了.



	//第一次接收数据
	memset(recvBuffer,0,sizeof(recvBuffer));
	result =recv(sock,recvBuffer,6000,0);

	if(result <=0)
	{
		printf("接收失败");
		return 0;
	}



	
	lenbegin = strstr(recvBuffer,"Content-Length:");   
	lenend = strstr(recvBuffer,"Content-Type: ");   

	char tolength[64]={0x00};
	memcpy(tolength,lenbegin+sizeof("Content-Length:"),lenend-lenbegin-sizeof("Content-Length:"));

	int totallength=atoi(tolength);

	printf("所下载文件长度为：%s",tolength);


	offset = strstr(recvBuffer,"\r\n\r\n");   

	if(NULL == offset){
		printf("未找到 \r\n\r\n ");
		return 0;
	}
	offset += 4;

	int truelength = recvBuffer +result-offset;

	fwrite(offset,sizeof(char),truelength,fp);
	printf("第%d次接收数据长度 == %d\n",1,truelength);

	for(int i=2;;i++)
	{
		memset(recvBuffer,0,sizeof(recvBuffer));
		result =recv(sock,recvBuffer,6000,0);	
		if(result <=0)
		{
			printf("接收数据出错\n");
			break;
		}
		
		fwrite(recvBuffer,sizeof(char),result,fp);
		printf("第%d次接收数据长度 == %d\n",i,result);
		truelength +=result;

		//为防止下载已完必后，继续跳入循环recv等待
		if(truelength==totallength)
		{
			printf("已下载完毕\n");
			break;
		}
	}  
	printf("保存于%s",savePath);
	fclose(fp);
	closesocket(sock);
	return sock;  
}



int _tmain(int argc, _TCHAR* argv[])
{
	createSocket();
	return 0;
}

