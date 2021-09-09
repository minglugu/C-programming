#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

// 实现一个函数，可以左旋转字符串中的k个字符。
// 第一个字符左旋转k次
// 指针的各种解引用
// 剑指offer，leetcode都有此题
//void left_move(char arr[], int k) {
//
//	assert(arr);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++) {
//		// k %= len; 如果k的数值太大，超过了len的长度 
//		//左旋转1次
//		// 1. 保存第一个字符，temp
//		char temp = *arr;
//		// 2. 把后续的字符往前挪一位
//		for (int j = 0; j < len - 1; j++) {
//			*(arr + j) = *(arr + j + 1);
//		}
//		// 3. 把保存的第一个字符存放在最后
//		*(arr + len - 1) = temp;
//	}
//}
//

// method 2
// 逆序字符串,知道从哪里开始，到哪里结束
// 1. 逆序前半部分的字符串
// 2. 逆序后半部分的字符串
// 3. 逆序全部字符串

//void reverse(char* left, char* right) {
//	assert(left && right);
//
//	while (left < right) {
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//
//		left++;
//		right--;
//	}
//}
//
//void left_move(char* arr, int k) {
//
//	assert(arr);
//
//	int len = strlen(arr);
//	k %= len; // when k > len
//	
//	reverse(arr, arr+k-1); // 逆序左半边字符串
//	reverse(arr+k, arr+len-1); // 逆序右半边字符串
//	reverse(arr, arr+len-1); // 逆序整个字符串
//}
//
//int main() {
//
//	// char* p = "abcd"; // err, const
//
//	char arr[] = "abcdef";
//
//	// 左旋转字符串
//	left_move(arr, 3);
//
//	printf("%s\n", arr);// 打印字符串
//	return 0;
//}

// 判断arr2是否是arr1旋转得到的？
//int is_left_move(char arr1[], char arr2[]) {
//
//	int len = strlen(arr1);
//	int i = 0;
//	for (i = 0; i < len; i++) {
//		left_move(arr1, 1); // left move once
//		if (strcmp(arr1, arr2) == 0)
//			return 1; // is left move
//	}
//	return 0; // is not left move
//	
//}
//
//int isLeftMove(char arr1[], char arr2[]) {
//
//	int len = strlen(arr1);
//	// 1. 给arr1的后面 追加一个arr1中的字符串
//	strncat(arr1, arr1, len);
//	// 2. 判断arr2是否是arr1的子串(substring)
//	if (NULL == strstr(arr1, arr2)) 
//		return 0;
//	else
//		return 1;
//}

// method 1.
// 写一个函数，判断一个字符串是否维另外一个字符串旋转之后的字符串
//int main() {
//	
//	char arr1[] = "AABCD";
//	char arr2[] = "BCDAA";
//
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//
//	return 0;
//}

// method 2.
//int main() {
//	// char arr1[20] = "abc";
//	// strcat(arr1, "def");
//	// strncat(arr1, arr1, 3); // adding string to itself
//
//	// strstr查找substring
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "def";
//	char* ret = strstr(arr1, arr2);// 返回substring第一次出现的位置
//	
//	if (ret == NULL) {
//		printf("Not found\n");
//	}
//
//	else
//		printf("%s", ret);
//
//	// printf("%s\n", arr1);
//
//	return 0;
//}

// 杨氏矩阵
// 2D array
// 1 2 3
// 4 5 6
// 7 8 9 

// method 1
//void find_k(int arr[3][3], int k, int row, int col) {
//	// 右上角的坐标
//	int x = 0;
//	int y = col - 1;
//	while (x < row && y >= 0) {
//		if (arr[x][y] < k)
//			x++;
//		else if (arr[x][y] > k)
//			y--;
//		else
//			printf("Found: %d %d\n", x, y);
//		return;
//	}
//	printf("Not found.\n");
//}

// method 2 using pointer
//void find_k(int arr[3][3], int k, int *px, int *py) {
//	// 右上角的坐标
//	int x = 0;
//	int y = *py - 1;
//	while (x < *px && y >= 0) {
//		if (arr[x][y] < k)
//			x++;
//		else if (arr[x][y] > k)
//			y--;
//		else {
//			*px = x;
//			*py = y;
//			return;
//		}
//	}
//	*px = -1;
//	*py = -1;
//}
//// m 2
//int main() {
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	int x = 3;
//	int y = 3;
//	// &x, &y
//	// 返回形参数
//	find_k(arr, k, &x, &y);
//
//	if (x == -1 && y == -1) {
//		printf("Not found.\n");
//	}
//	else {
//		printf("%d %d\n", x, y);
//	}
//	
//
//	return 0;
//}

// m 1 
//int main() {
//
//	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
//	// N= n*n
//	// < O(N): 遍历O(n^2) big O
//	// 查找一次，删除一行或一列，那就不再遍历
//	// 左上角或右下角都可以
//	int k = 7;
//	find_k(arr, k, 3, 3);
//
//
//	return 0;
//}

// 字符函数
//int main() {
//	// strlen return size_t which is unsigned int
//	// char arr[] = "abcdef"; // \0
//	// 
//	// might not have \0 after 'c', so it is a random length
//	char arr[] = {'a', 'b', 'c'}; // err
//	size_t sz = strlen("abcdef"); 
//	printf("%u\n", sz);
//
//	return 0;
//}

//int main() {
//	// 3-6 = -3
//	// returns size_t which is unsigned int, always > 0,
//	// so print "hehe". 
//	if (strlen("abc") - strlen("abcedf") > 0) {
//		printf("hehe\n");
//	}
//	else {
//		printf("haha\n");
//	}
//
//	return 0;
//}

// strlen的模拟实现
// 1 计数，指针-指针，递归（在不创建临时变量的情况下）

// sizeof(操作符) 和strlen(函数)，返回都是unsigned int

// 字符串函数
/*
strcpy注意点
源字符串必须以'\0' 结束。
会将源字符串中的'\0' 拷贝到目标空间。
目标空间必须足够大，以确保能存放源字符串。
目标空间必须可变。
学会模拟实现。
*/

//#include <assert.h>
//char* my_strcpy(char* dest, const char* scr) {
//
//	assert(dest && scr);
//	// save the original pointer before copying for the return value
//	char* ret = dest;
//	// \0, it is false, then it stops copying.
//	// it is "=" for assigning src to dest， not "==". 
//	while (*dest++ = *scr++) {
//		;
//	}
//	return ret;
//}
//
//int main() {
//
//	char arr1[] = "xxxxxxxx";
//	char arr2[] = "abc";
//	
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}

