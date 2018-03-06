// --    2018- 3 -6
// --    author: 李亮星
// --    adrr: HGD

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 需要调用 strlen(char * argument) 函数, 参数为字符串首地址
// ascii: '0' - '9' -- 48 - 57


// 函数声明
char * set_num (char *p);   // 输入字符串 num 并返回其值
void re(char *p);           // num 排列的逆序数
void each_re (char *p);     // num 的每个位的逆序数
void parity (char *p);      // num 排列的奇偶性


// 全局 vars 声明

// count 变量存储逆序数
int count = 0;
// cou 数组存储过程中每位的逆序数，由于排列由 0 - 9 组合而成，故数组长度最大为 10
int cou[10];

//函数定义
char * set_num (char *p) {
    
    // 输入提示
    printf("input a num : ");
    scanf("%s", p); // such as : '213'
    
    // 返回其值
    return p;
}

// 逆序数演示
void re(char *p) {
    
    // 思想：1. 从左边第一个数字开始，依次与第二个、第三个数直到最后一个数比较，如果第一个数的数值要大，那么 count 的值 ++;
    //      2. 接着从第二个数开始，重复上一步;
    //      3. 直到倒数第二个数为止比较完成后停止比较.
    // ps : 基于以上思路，需要通过至少两层循环嵌套来实现该功能
    
    int i, j;
    
    for (i = 0; i < strlen(p) - 1; i++) {
        for (j = i + 1; j < strlen(p); j++) {
            if (p[i] > p[j]) {
                count++;
            }
        }
    }
    
    // 打印结果
    printf("num 排列的逆序数为 %d\n", count);
}

// 过程演示
void each_re (char *p) {
    int i, j;
    char *tmp = p;

    for (i = 0; i < strlen(p) - 1; i++) {
        for (j = i + 1; j < strlen(p); j++) {
            if (p[i] > p[j]) {
                cou[i]++;
            }
        }
    }
    
    // 依次打印结果
    for (i = 0; i < strlen(p) - 1; i++, tmp++) {
        printf("%c 的逆序数总数 : %d\n", *tmp, cou[i]);
    }
}

// 奇偶性演示
void parity (char *p) {
    
    // 如果 count 的值，即逆序数的值为偶数，则该排列为偶排列;
    if (count % 2 == 0) {
        printf("%s 为偶排列\n", p);
    }
    // 否则为奇排列.
    else {
        printf("%s 为奇排列\n", p);
    }
}

int main() {
    // 为排列申请存储空间
    char *num = (char *)malloc(sizeof(char));
    
    // 定一个临时变量获取用户输入的排列
    char *tmp = NULL;
    
    // 初始化 cou 数组
    for (int i = 0; i < 10; i++) {
        cou[i] = 0;
    }
    
    // 调用函数
    
    // 获取输入的排列
    tmp =  set_num (num);
    // 演示逆序数
    re (tmp);
    // 演示获得结果的过程
    each_re (tmp);
    // 演示排列的奇偶性
    parity (num);
    
    // 释放存储排列的空间
    free (num);

    return 0;
}



