#include <linux/i2c-dev.h>
#include <errno.h>
#include <fcntl.h>
#define I2C_ADDR 0x08
#define LED_ON  0xEF
#define LED_OFF 0xFF
int main (void)
{
    int value=65;
    int fd; 

	printf("bala:23apr:100\n");
   
    fd = open("/dev/i2c-1", O_RDWR);
	
printf("bala:23apr:101\n");

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
        if( write( fd , &value, 1 ) != 1) {
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
