﻿#include<stdio.h>

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