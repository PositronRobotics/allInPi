#include <linux/i2c-dev.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define I2C_ADDR 0x08
#define LED_ON  0xEF
#define LED_OFF 0xFF

int getch(void)
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}


int main (void)
{
	int in=0;
	int value=65;
	int fd;

	printf("bala:7may:101.0\n");

	fd = open("/dev/i2c-1", O_RDWR);

	if (fd < 0) {
		printf("Error opening file: %s\n", strerror(errno));
		return 1;
	}   
	if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
		printf("ioctl error: %s\n", strerror(errno));
		return 1;
	}   

	while(1)
	{   

		in=getch();

		if( write( fd , &in, 1 ) != 1) {
			printf("Error writing file: %s\n", strerror(errno));
		}    

		if(value++>=100)
		{
			value=65;
		}

		usleep(1000000); 
	}

	return 0;
}
