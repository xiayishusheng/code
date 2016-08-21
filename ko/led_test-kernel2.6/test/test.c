#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DEV_NAME "/dev/test"
#define FLAGS (O_RDWR | O_CREAT)

int main(void)
{
	int fd = -1;
	int i = -1;
	int cnt = -1;
	unsigned char led = 0xff;
	
	//open
	fd = open(DEV_NAME, FLAGS);
	if(0 > fd)
	{
		perror("open err:");
		goto _out;
	}	
	
	//Á÷Ë®µÆ
	while(1)
	{
		for(i = 0; i < 8; i++)
		{
			led &= ~(1 << i);
			cnt = write(fd, &led, 1);
			if(0 > cnt)
			{
				perror("write err:");
				goto _out;
			}
			led = 0xff;
			sleep(1);
		}
	}

	//close
	close(fd);

	return 0;
_out:
	return -1;
}
