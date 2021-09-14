#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <assert.h>

// start from line 90is

//// 自定义strcmp,是比较字符串的，比较的是字符串的内容，不是长度
//int my_strcmp(const char* s1, const char* s2) {
//	assert(s1 && s2);
//	while (*s1 == *s2) {
//		// 需要判断，否则会继续往后比较
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	// 不相等的时候，跳出来，返回来
//	return *s1 - *s2;
//}
//
//int main() {
//
//	char arr1[] = "abcq";
//	char arr2[] = "abcwq";
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0) 
//		printf(">\n");
//	else if (ret < 0) 
//		printf("<\n");
//	else 
//		printf("=\n");
//
//	return 0;
//}

// strcpy, strcat, strcmp, 长度不受限制的字符串函数
// 一直比较到"\0"或相等为止，所以不安全

// strncpy, strncat, strncmp 长度受限制的字符串函数，
// 相对更安全(不是绝对安全)
// char * strncpy ( char * destination, const char * source, size_t num );
// 循环的次数用size_t num控制的
//int main() {
//	char arr1[20] = "abcdefghi";
//	char arr2[] = "xxxx";
//	// 相对，防止越界访问
//	strncpy(arr1, arr2, 2); // print xxcdefghi
//	strncpy(arr1, arr2, 6); // 最后两位不够的时候，加"\0"
//
//	printf("%s\n", arr1); 
//	return 0;
//}

// @1：24：00
//int main() {
//
//	char arr1[20] = "abc\0xxxxxxx"; // 加了\0调试
//	char arr2[] = "defghi";
//	// 如果count 大于arr2里面的字符，那么就append追加完了，加个“\0” 提前结束copy
//	// 模拟实现
//	strncat(arr1, arr2, 3); // copy完了，再默认在末尾加个"\0"
//
//	return 0;
//}

//int main() {
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abeqw";
//	// 模拟实现
//	int ret = strncmp(arr1, arr2, 4);
//	printf("%d\n", ret);
//
//	return 0;
//}

//int main() {
	// 不建议使用
	// VS的版本 strcpy_s(,)，不是linux或gcc下面的函数，不建议使用 -> 类似C提供 strncpy
	//return 0;
//}

//@1:50:00
// strstr字符串查找函数
// Returns a pointer to the first occurence of str2 in str1, or a null pointer if str2..
// 在一个字符串中查找子子字符串
// my_strstr()
/* char* my_strstr(const char* str1, const char* str2) {
	assert(str1 && str2);
	char* s1;
	char* s2;
	// 记录有可能匹配成功的地址
	// 主串赋值给cp
	char* cp = str1; 
	// 如果str2是空字符串，库里面return str1
	// 自己实现的话，
	if (str2 = "\0") {
		return str1;
	}

	while (*cp) {
		s1 = cp;
		s2 = str2;
		// 如果s1和s2不相等，就跳过这个while循环
		while ( *s1 != "\0" && *s2 != "\0" && *s1 == *s2) {
			s1++;
			s2++;
		}
		// 只有这种情况，是找到了
		if (*s2 != "\0") {
			return cp;
		}
		cp++;
	}
	//找不到的情况
	return NULL;
}

int main() {

	char arr1[] = "i am a good student, wow student";
	char arr2[] = "student";
	
	// 查找arr1中arr2第一次出现的位置,不是第二次出现的地址
	// 查找有三种情况
	char *ret = my_strstr(arr1, arr2);
	if (ret == NULL) {
		printf("Not found\n");
	}
	else {
		printf("%s\n", ret);
	}
	return 0;
}
*/

// KMP算法: b站，比特大博哥，终于有人。。。
// https://www.bilibili.com/video/BV1UL411E7M8/

// copy bitpg @211
//

// 无所谓先后顺序
// strtok(, "@.")
// zpw@bitedu.tech 找到@
// zpw\0bitedu.tech 返回z的地址，会改变这个字符串，所以。。。见课件
// @2:20
//int main() {
//
//	char arr1[] = "zpw@bitedu.tech";
//	char arr2[100] = { 0 }; // 临时数据,会记住这个位置
//	// zpw@bitedu.tech\0
//	char sep[] = "@.";
//	strcpy(arr2, arr1);
//	char* ret = NULL;
//	// 分割字符串
//	// 第一次调用，传非空指针,其余调用，传NULL指针,因为已经保存了地址。
//	// strtok(arr2, sep);
//	// strtok(NULL, sep);
//	for (ret = strtok(arr2, sep); ret != NULL; ret = strtok(NULL, sep)) {
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}

// @2：38：13
// 内存操作函数有4个：
/*
copies characters b/t buffers
memcpy： 内存拷贝
memmove
memset
memcmp
*/
/*
void* my_memcpy(void* dest, const void* src, size_t count) {
	//按字节copy
	void* temp = dest;
	assert(dest && src);
	while (count--) {
		*(char*)dest = *(char*)src;
		// 这种写法，很多编译器可以编译
		dest = *(char*)dest + 1;
		src = *(char*)src + 1; 
	}
	return temp;
}
*/

// 实现重叠和不重叠copy
void* my_memmove(void* dest, const void* src, size_t count) {

}

//int main() {
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//			  1.2.1.2.3.4.7.8.9.10
//	// memcpy - 只要完成了不重叠的内存copy完成任务
//	// 内存重叠，需要用memmove
//	// my_memcpy(arr+2, arr, 16);
//	memmove(arr+2, arr, 16); 
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]); // 可以实现1,2,1,2,3,4,7,8,9,10
//	}
//	return 0;
//}

//int main() {
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//	// 拷贝的是整形数据,void*表示的是data type
//	// 模拟实现
//	my_memcpy(arr2, arr1, 40); // copy 40 bytes 
//	// or memcpy(arr2, arr1, 10*sizeof(int));
//
//	for (int i = 0; i < 20; i++) {
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

