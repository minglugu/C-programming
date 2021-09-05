#include <stdio.h>
#include <string.h>

// find a larger integer b/t two numbers
/*int get_max(int a, int b) {
	if (a > b) 
		return a;
	else 
		return b;
}

int main() {
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
	int max = get_max(x, y);
	printf("%d\n", max);
	return 0;
}*/

// if statement
/*
int main() {
	int number;

	printf("Enter an integer: ");
	scanf("%d", &number);

	// negative if number is less than 0
	if (number < 0) {
		printf("You entered %d.\n", number);
	}

	printf("The number is negative.");

	return 0;
}
*/

// use extern to use global variable
// extern int g_val;

// int main() {

//     // 字面常量
//     float a = 3.14; //浮点型的常量

//     printf("%d\n", g_val);
//     return 0;
// }

// ctrl+K +C to comment 
// int main() {
//     //const int a = 100; // const variable
//     // a is const, so its value cannot be changed. 
//     // array
//     // const 修饰的常变量
//     int n = 100;
//     int arr[n] = {0};// can't write this way,b/c n is variable
//                     // n 需要是常量。即使const修饰n，n也不是常量，
//                     // 只是具有常属性，不能被修改而已
// }

// #define 定义的标识符常量
// #define MAX 100
// int main() {
//     int a = MAX;
//     printf("a=%d\n", a);
// }

// 枚举常量 keyword enum 
// enum Color{
//     //枚举的可能取值 - 三个值是枚举常量,不能该值，可以赋值
//     RED, // 0
//     GREEN, // 1
//     BLUE// 2
// };

// int main(){
//     enum Color c= RED;
//     // RED = 5;// ERROR
//     printf("%d %d %d\n", RED, GREEN, BLUE);
//     return 0;
// }

// various data type
int main()
{
	char arr1[] = "bit";
	char arr2[] = { 'b', 'i', 't' };
	char arr3[] = { 'b', 'i', 't', '\0' };
	printf("arr1 %s\n", arr1);// default with \0
	printf("arr2 %s\n", arr2);// no \0 to terminate when finish printing bit
	printf("arr3 %s\n", arr3);// \0 in the end means to terminate
	printf("%d\n", strlen("c:\test\121")); // 7, string is "c:  esty", \121 is y in ASCII table

	float a = 5 / 2; // 2.000000
	float a = 5 / 2.0; // 2.500000 one of the number need to be float to get 2.5 
	int b = 7 % 2; // mod, b is the remainder

	// operator: >> right shift, << left shift for bit operation

	return 0;
}