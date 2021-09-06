#include <stdio.h>


// %s print string
// %c print character
// %d print integer
// %p print value of a pointer
// int main() {

//     // 向内存申请4个字节的空间，里面存放10
//     int a = 10;
//     // printf("%p\n", &a); &取地址操作符
//     // 0x0012ff44, * pointer, int data type that pa point to a is int
//     // pa pointer store the address of a.
//     int* pa = &a; // 0x0012ff44, &取地址操作符
//     *pa = 20; // * - dereference, 解引用操作符，通过pa里面存的地址，找到a
//     printf("%d\n", a); // 20

//     // pa 是一个存放地址的变量，这样的变量就被成为指针变量
//     // sizeof(int) - 4


// }

// #include <stdio.h>

// int main() {

//     // all print out 4. 32位机器，32根地址线
//     // 32/8 = 4 指针变量的大小用来存放地址的，地址是32bits，所以指针变量的大小是4
//     // 64位的机器上，那么sizeof 是8
//     printf("%d\n", sizeof(char*));
//     printf("%d\n", sizeof(short*));
//     printf("%d\n", sizeof(int*));
//     printf("%d\n", sizeof(long*));
//     printf("%d\n", sizeof(float*));
//     printf("%d\n", sizeof(double*));

//     return 0;
// }


// 声明一个学生的类型struct
struct Student {
    // 成员变量
    char name[20];
    int age;
    char gender[7];
    char id[12];
};


// struct book
struct Book {
    char name[20];
    int price;
    char author[20];
};
#include <stdio.h>

int main() {
    // 创建结构体变量
    struct Student s1 = { "Jack", 20, "male", "B001212" };
    struct Student s2 = { "May", 21, "female", "1234" };
    struct Book b1 = { "C Primer Plus", 55, "Stephen" };

    // . 操作符。结构体变量.成员名
    printf("name: %s age: %d gender: %s id: %s", s1.name, s1.age, s1.gender, s1.gender);

    struct Book* pb = &b1;
    // this is correct, but -> is more common
    printf("book: %s price: %d author: %s\n", (*pb).name, (*pb).price, (*pb).author);
    // -> 结构体指针->成员名
    printf("book: %s price: %d author: %s\n", pb->name, pb->price, pb->author);
    return 0;
}

