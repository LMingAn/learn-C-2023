#include<stdio.h>

int main()
{
	int a = -1;
	unsigned int b = -1;
	signed int c = -1;
	char A = -1;
	unsigned char B = -1;
	signed char C = -1;
	printf("a = %d b = %d c = %d\n", a, b, c);//-1 -1 -1
	printf("A = %d B = %d C = %d\n", A, B, C);//-1 255 -1
	//因为B是无符号型数据，-1的二进制首位是1，因为无符号型数据首位为数据字节，不是符号位，又因为负数在内存中存放的是补码，所以是11111111，即为255
	return 0;
}