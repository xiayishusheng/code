// Down.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <windows.h>

int createSocket()
{
	int sock;
	int connresult =0; //���ӷ��������
	struct sockaddr_in server;
	struct hostent *server_hosten;

	u_short port = 80;
	char *serverip ;
	//http://www.12306.cn/mormhweb/ggxxfw/wbyyzj/201106/srca12306.zip


	char *host ="www.12306.cn";//�����ӵ�����


	char sendBuffer[1025];
	char recvBuffer[6001];
	FILE *fp;
	char *offset =0;
	char *lenbegin =0;
	char *lenend =0;

	char *savePath ="srca12306.zip";

	int w_send = 0;//���͵��ֽ�
	int result = 0;

	//��ʼ��socket 
	WSADATA wsaData;
	int wsaret=WSAStartup(0x101,&wsaData);
	if(wsaret !=0)
	{
		exit(EXIT_FAILURE);
		return 0 ;
	} 

	//�ú�������ǰ�������WSAStartup
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
	printf("��ʼ���ӷ�����.......\n");
	if(SOCKET_ERROR == connresult)
	{
		printf("���ӷ�����ʧ��%s\n",strerror(errno));
		exit(0);
	}else
	{
		printf("�������Ϸ�����:%s,IP:%s\n",host,serverip);
		printf("��ʼ����.....\n");
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
		printf("��������Ͽ�\n");
		exit(0);
	}
	else{
		printf("����������,���ڽ�������......\n");
	}

	fp =fopen(savePath,"wb"); //��,��������þ�,ԭ������д�ļ���ʱ�����Ƕ�һ������.����ץ���ȶԲſ�����,ֻ����,�Ҳ������������,��д���ʽ�ĳ�"wb"(��ǰ��w)������.



	//��һ�ν�������
	memset(recvBuffer,0,sizeof(recvBuffer));
	result =recv(sock,recvBuffer,6000,0);

	if(result <=0)
	{
		printf("����ʧ��");
		return 0;
	}



	
	lenbegin = strstr(recvBuffer,"Content-Length:");   
	lenend = strstr(recvBuffer,"Content-Type: ");   

	char tolength[64]={0x00};
	memcpy(tolength,lenbegin+sizeof("Content-Length:"),lenend-lenbegin-sizeof("Content-Length:"));

	int totallength=atoi(tolength);

	printf("�������ļ�����Ϊ��%s",tolength);


	offset = strstr(recvBuffer,"\r\n\r\n");   

	if(NULL == offset){
		printf("δ�ҵ� \r\n\r\n ");
		return 0;
	}
	offset += 4;

	int truelength = recvBuffer +result-offset;

	fwrite(offset,sizeof(char),truelength,fp);
	printf("��%d�ν������ݳ��� == %d\n",1,truelength);

	for(int i=2;;i++)
	{
		memset(recvBuffer,0,sizeof(recvBuffer));
		result =recv(sock,recvBuffer,6000,0);	
		if(result <=0)
		{
			printf("�������ݳ���\n");
			break;
		}
		
		fwrite(recvBuffer,sizeof(char),result,fp);
		printf("��%d�ν������ݳ��� == %d\n",i,result);
		truelength +=result;

		//Ϊ��ֹ��������غ󣬼�������ѭ��recv�ȴ�
		if(truelength==totallength)
		{
			printf("���������\n");
			break;
		}
	}  
	printf("������%s",savePath);
	fclose(fp);
	closesocket(sock);
	return sock;  
}



int _tmain(int argc, _TCHAR* argv[])
{
	createSocket();
	return 0;
}

