﻿#include<stdio.h> 
#include<string.h>

//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char a = *left;
//		*left = *right;
//		*right = a;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char a[101] = { 0 };
//	//输入
//	gets(a);
//
//	//逆置
//	int len = strlen(a);
//	reverse(a, a + len - 1);
//
//	//逆序
//	char* start = a;
//	while (*start)
//	{
//		char* end = start;
//		while (*end != ' ' && *end != '\0')
//			end++;
//		reverse(start, end - 1);
//		if (*end != '\0')
//			end++;
//		start = end;
//	}
//
//	//输出
//	printf("%s", a);
//	return 0;
//}

//数值有不同的表现形式
//2进制、8进制、10进制、16进制
//例 - 21：
//2进制：0b10101  8进制：025  10进制：21  16进制：0x15

/*
同样，数值（整数）的2进制表示形式也有三种：原码（直接根据正负形式的2进制形式），反码（原码的符号位不变（若此数值为signed型），其他位取反），补码（反码+1）
正的整数，三码相同/负的整数，三码需要计算
对于整形：数据存放内存中的其实是补码
*/

//例：
int main()
{
	int a = 20;
	//00000000000000000000000000010100
	//0x00000014
	//00000000000000000000000000010100
	//00000000000000000000000000010100

	int b = -10;
	//因为是负数，即高位是1（2进制表示时第一位为符号位）
	//10000000000000000000000000001010
	//0x8000000a
	//11111111111111111111111111110101
	//0xfffffff5
	//11111111111111111111111111110110
	//0xfffffff6
	return 0;
}


/*
在计算机系统中，数值一律用补码来表示和存储，因为使用补码可以将符号位和数值域统一处理
同时，加减法也可以统一处理（CPU只有加法器）此外，补码与原码相互转化，其运算过程是相同的，不需要额外的硬件
例:1 + (-1)
1的原码：00000000000000000000000000000001
-1的原码：10000000000000000000000000000001
两者相加为：10000000000000000000000000000010 -- 结果为-2不符合逻辑
所以用补码计算
1的补码：00000000000000000000000000000001
-1的补码：11111111111111111111111111111111
两者相加为：100000000000000000000000000000000 -- 结果为0 -- 由于两个补码相加有32个0，首位的符号位溢出
*/

/*
大小端存储方式：
0x11 22 33 44存放于内存中
11为高位字节 44为最低位字节
11 22 33 44（正序存放）为大端字节序存放
低地址  -->  高地址/高地址  -->  低地址
大端：把一个数据的高位字节序的内容存放在低地址处，把低字节序的内容放在高地址处，即为大端存储（即地址从低到高存放的数据字节序从高到低，为反序）

44 33 22 11（倒序存放）为小端字节序存放
小端：把一个数据的高位字节序的内容存放在高地址处，把低字节序的内容放在低地址处，即为小端存储（即地址从低到高存放的数据字节序从低到高，为正序）
*/

/*
同时，对于char型的单个数据，因为只有1个字节，故没有大小端存储的说法，即没有存放顺序一说
但对于short型、float型，long型等的具有多个字节的数据类型，就有存放顺序一说，存在大小端存储
*/


void check(int a)
{
	if (*(char*)&a == 1)
		printf("小端");
	else
		printf("大端");
}

int main()
{
	int a = 1;
	check(a);
	return 0;
}


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


int main()
{
	char a = -128, b = 128;
	//a
	//-128原码：10000000000000000000000010000000
	//反码：11111111111111111111111101111111
	//补码：11111111111111111111111110000000 - 反码+1
	//由于char型只能存8个比特位，所以是10000000 - a -- 发生截断
	//又因为char型为有符号型，首位为1，且打印形式为u，所以高位提升，前面全补1 -- 11111111111111111111111110000000
	//且无符号数，没有原反补码的概念（即为正数），所以%u直接输出11111111111111111111111110000000即为4294967168

	//b
	//128原码：00000000000000000000000010000000
	//10000000 - b -- 截断（char型）
	//因为打印形式为%u，为整数，要进行整型提升，且b为char型，有符号，所以b -- 11111111111111111111111110000000
	//随后因为无符号，没有原反补码的概念（即为正数），所以%u直接输出11111111111111111111111110000000
	printf("%u %u\n", a, b);
	printf("%d\n", b);
	//因为打印类型为d，有符号，且char类型数值范围为-128 - 127，所以b的补码 -- 11111111111111111111111110000000转化为原码
	//补码来历：打印类型为d时，将char型数据b的内存中的截断（数字类型数据转化为字符类型数据）后再提升（打印形式为d，由char型整型提升为d）的值作为补码
	//b的原码为10000000000000000000000010000000 -- 即为-128

	int c = -20;
	//10000000000000000000000000010100 -- 原码
	//11111111111111111111111111101011 -- 反码
	//11111111111111111111111111101100 -- 补码

	unsigned int d = 10;
	//00000000000000000000000000001010 -- 原码 -- 正数的原反补码相同

	printf("%d\n", c + d);
	//c的补码与d的原码相加
	//11111111111111111111111111110110 -- 补码
	//10000000000000000000000000001001 -- 反码
	//10000000000000000000000000001010 -- 原码 --> -10
	return 0;
}