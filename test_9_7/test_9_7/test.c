#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// pointer + 1
//int main()
//{
//	//int: 4 bytes. E.g. 0x00 00 00 01 is stored in memory as follows:
//	// 	   low address(little endian)       high address(big endian)
//	// 	   |01|00|00|00|02|00|00|00|03|00|00|00|04|00|00|00|
//	//		
//	//
//	// array a starts from low address
//	int a[4] = { 1, 2, 3, 4 }; 
//
//	// &a gets the array address, &a+1 will skip 4 integers, 
//	// pointing at the end address of the array a. 
//	// &a type: int(*)[10]
//	// &a+1 type: int(*)[10], cast to (int*) type to assign to ptr2
//	// but &a+1 still points at the same address 
//	// ptr1[-1] = *(ptr1+(-1)) = *(ptr1-1), pointing at |04|00|00|00|
//	int* ptr1 = (int*)(&a + 1); // 4
//	// array name a is the address of the 1st element
//	// (int)a+1: address of a is hex, casting to int, and then add 1.
//	// 地址加了个1，相当于加了1个字节，指向了01后面的地址(|01|00|00|00|)
//	// int* ptr2相当于向后看了4个字节，为|00|00|00|02|，再以16进制打印
//	// 0x02 00 00 00 -> 2000000 
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2); //4,2000000
//	return 0;
//}

// 逗号表达式
//int main() {
//
//	// a[0]	{1,3}
//	// a[1] {5,0}
//	// a[2] {0,0}
//	
//	// int a[3][2] = {1,3,5};
//
//	// a[3][2] = {{1,2}, {3,4}, {5,6}};
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) }; 
//	int* p;
//	p = a[0]; // 第一行数组名代表首元素的地址，指向整形1
//	printf("%d", p[0]);//*(p+0) -> *p -> 1
//
//	return 0;
//}

//@34 min
//int main()
//{
//	// 数组名a，作为首元素的地址，是第一行的地址
//	// a[0]是第一行第一个元素的地址
//	int a[5][5];
//	// p可以指向4个整形元素的数组
//	int(*p)[4]; // 指针指向数组，每个元素的类型是int
//	// a的类型int(*)[5] ,p的类型int(*)[4]
//	// a数组名，表示首元素的地址。p指向a的起始位置的地址
//	p = a; 
//	//p[4][2] -> *(*(p+4)+2) -> *(p+4)指向后面的数组(4个整形)
//	// *(p+4)拿到了这个数组的数组名，因为没有&和sizeof，所以表示数组首元素的地址
//	// 如图，p[4][2](地址小) 和a[4][2](地址大)隔了4个int元素，指针-指针 = 元素的个数
//	// %d: -4以补码的形式存在的。				   补码11111111 11111111 111111111 11111100
//	// %p: 没有原反补的概念，把补码当成原码来打印。    FF		FF		 FF		   FC
//	// warning, p and a type do not match. 
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); // FF FF FF FC, -4 
//	return 0;
//}

// @53min
//int main()
//{
//	// 1 2 3 4 5
//	// 6 7 8 9 10
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	// &aa:整个二维数组+1，跳过整个2D数组，cast(int*)
//	int* ptr1 = (int*)(&aa + 1); 
//	// aa+1 拿到第二行的地址，解引用拿到第二行，得到第二行数组名
//	// *(aa + 1) -> aa[1] 是第二行首元素的地址，已经是地址了，所以line82，
//	// 不需要在cast成int*，ptr2 - 1指向5，* dereference得到5.
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1)); // 10,5
//	return 0;
//}

//@1：13：00
//				a
//char** pa ->	char* -> work\0
//pa++		->	char* -> at\0
//				char* -> alibaba\0
//
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	// 
//	// a是首元素地址，char* -> work\0
//	// 就是char*的地址，也就是char**
//	char** pa = a; 
//	// pa++指向第二个空间，char* -> at\0
//	pa++;
//	printf("%s\n", *pa); // at
//	return 0;
//}

//@1：35：50
/*
int main()
{
	// E, N, P and F的地址放到char* c[]里面  
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3, c + 2, c + 1, c };
				  //FIRST  POINT  NEW	 ENTER

	// c[]				
	// char*	ENTER	char**	c	  
	// char*	NEW		char**	c+1	
	// char*	POINT	char**	c+2	
	// char*	FIRST	char**	c+3	 <-cpp char***
	//					cp[]

	char*** cpp = cp;
	// POINT. ++cpp此时cpp指向第二个元素(c+2), 8++cpp解引用，得到了
	// c+2，c+2是指向了POINT首元素地址，再*解引用，相当于拿到了这个里面的值
	// 即P的地址，以%s的形式打印，从P开始，打印字符串，一直到POINT后面的"\0"。
	printf("%s\n", **++cpp); 
	// cpp的值在第一次print里面，就已经改变，会影响下面的printf里面的值
	// ++cpp，拿到c+1的地址，*解引用，拿到了这个地址c+1所指向的空间，再--，相当于
	// 这个空间的值被改成(c+1)-1 = c(char** type)。这个空间的地址不再指向char*(NEW)，
	// 而是指向char*(ENTER)。再对c解引用，通过c找到char*->(ENTER)的这块空间，
	// *-- * ++cpp 表达式拿到的是E的地址。*-- * ++cpp + 3指向第二个E的地址，得到ER
	// ++ 和 --的优先级比 + 高
	printf("%s\n", *-- * ++cpp + 3); // ER
	//		char**
	//		c+3
	//		c+2
	//cpp->	c
	//		c
	// cpp[-2] = *(cpp-2)	解引用 找到char**(c+3)的空间
	// *cpp[-2] = **(cpp-2) 再解引用 找到char*(FIRST)的空间，放的是F的地址
	// *cpp[-2] + 3，得到的S的地址（指向了S），%s打印字符串，是ST
	printf("%s\n", *cpp[-2] + 3); 
	//		char**
	//		c+3
	//		c+2
	//cpp->	c
	//		c
	//	cpp[-1] = *(cpp-1)	cpp-1得到c+2，*(cpp-1)得到char*(POINT)
	//	cpp[-1][-1] = *(*(cpp-1)-1), *(cpp-1)-1,指向char*(NEW)，*(*(cpp-1)-1)得到元素，是NEW里
	// 	N的地址。这个char*就是N的地址。+1，指向E的地址，%s打印出EW
	//	cpp[-1][-1] +1 = *(*(cpp-1)-1) + 1
	// arr[i][j] <==> *(*(arr+i)+j)
	printf("%s\n", cpp[-1][-1] + 1); // NEW中E的地址
	return 0;
}
*/

/*
KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，
计算这一年这个月有多少天。
*/ 
/*
int main() {
	int year = 0;
	int month = 0;
	// array
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// multi input, scanf的返回值是读取到完整数据的个数 
	// EOF end of file
	// EOF -> -1
	// leap year Feb is 29 days
	while (scanf("%d %d", &year, &month) != EOF) {
		int day = days[month - 1];
		// leap year
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (month == 2) {
				day++;
			}
			printf("%d\n", day);
		}
	}
	return 0;
}
*/

/*
杨辉三角
pascal's triangle
*/
//1
//1 1
//1 2 1 
//1 3 3 1 
//1 4 6 4 1
//int main() {
//	int arr[10][10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < i; j++) {
//			// column 0
//			if (j == 0)
//				arr[i][j] = 1;
//			// diagonal
//			if (i == j)
//				arr[i][j] = 1;
//			// calculate 
//			if (i >= 2 && j >=1) 
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//
//	// print
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < i; j++) {
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*
猜凶手
凶杀案
*/ 
//int main() {
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++) {
//		// 用c语言的判断表达式表达逻辑
//		if ((killer != 'A') + 
//			(killer == 'C') + 
//			(killer == 'D') + 
//			(killer != 'D') == 3) {
//			break;
//		}
//	}
//	printf("%c\n", killer); // c
//	return 0;
//}

/*
用智力题 盘点面试中常见的智力题【精品贴，准备面试的小比特都看看，
欢迎大家在评论区补充】
*/
/*
5位运动员参加10米跳台比赛，预测比赛结果
*/
// 只能穷举
//int main() {
//
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int d = 1;
//	int e = 1;
//
//	for (a = 1; a <= 5; a++) {
//		for (b = 1; b <= 5; b++) {
//			for (c = 1; c <= 5; c++) {
//				for (d = 1; d <= 5; d++) {
//					for (e = 1; e <= 5; e++) {
//						if( ((b == 2) + (a == 3)==1) &&
//							((b == 2) + (e == 4)==1) &&
//							((c == 1) + (d == 2)==1) &&
//							((c == 5) + (d == 3)==1) &&
//							((e == 4) + (a == 1)==1)) {
//							if (a * b * c * d * e == 120)
//								printf("a=%d b=%d c=%d d=%d e=%d",a,b,c,d,e);// 3,1,5,2,4
//								goto end;
//						}
//					}
//				}
//			}
//		}
//	}
//	end;
//	return 0;
//}