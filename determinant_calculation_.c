//
//  n x n 行列式计算工具 v_1.1.c
//  1
//
//  Created by Apple on 2018/3/10.
//  Copyright © 2018年 test. All rights reserved.
//
// ps : 目前只能计算 3 x 3 阶的数字行列式


#include "n x n 行列式计算工具 v_1.1.h"

#include <stdio.h>

// 函数声明

// 菜单函数
void menu (void);
// 退出函数
void exit_ (void);

// 2 x 2 行列式
// 输入数据
void input_nums_tw (int tmp[][2]);
// 以行列式的形式演示
void show_determinant_tw (int tmp[][2]);
// 计算 2 x 2 行列式
void calculate_determinant_tw (int tmp[][2]);
// 2 x 2 行列式展示
void sub_menu_tw (int tmp[][2]);

// 3 x 3 行列式
// 输入数据
void input_nums_th (int tmp[][3]);
// 以行列式的形式演示
void show_determinant_th (int tmp[][3]);
// 计算 3 x 3 行列式
void calculate_determinant_th (int tmp[][3]);
// 3 x 3 行列式展示
void sub_menu_th (int tmp[][3]);


void sub_menu_tw (int tmp[][2]) {
    char if_show;
    
    printf("--------------------------------------------------\n");
    printf("是否演示行列式图 ?\n");
    printf("--in (y/ n):");
    scanf(" %c", &if_show);
    if (if_show == 'y') {
        printf("\n");
        show_determinant_tw (tmp);
    }
    else {
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
    }
}

void exit_ (void) {
    printf(" --------------------------------------------------\n");
    printf("|               exited successfully!               |\n");
    printf(" --------------------------------------------------\n");
}

// 函数定义
void menu (void) {
    int sel;
    int nums_tw[2][2];
    int nums_th[3][3];
    
    while (1) {
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
        printf("       I.   2 x 2 determinant calculation         \n");
        printf("       II.  3 x 3 determinant calculation         \n");
        printf("       III. exit the program                      \n");
        printf("--------------------------------------------------\n");
        printf("select(1 - 3): ");
        scanf(" %d", &sel);
        
        switch (sel) {
            case 1:
                input_nums_tw (nums_tw);
                sub_menu_tw (nums_tw);
                calculate_determinant_tw (nums_tw);
                break;
            case 2:
                input_nums_th (nums_th);
                sub_menu_th (nums_th);
                calculate_determinant_th (nums_th);
                break;
            case 3:
                exit_ ();
                return;
            default:
                printf("error input, again!\n\n");
                printf("--------------------------------------------------\n\n");
                break;
        }
    }
}

void input_nums_tw (int tmp[][2]) {
    int i;
    
    for (i = 0; i < 2; i++) {
        printf("第 %d 行数据(first line): ", i + 1);
        scanf("%d %d", &tmp[i][0], &tmp[i][1]);
    }
}

void show_determinant_tw (int tmp[][2]) {
    int i;
    
    for (i = 0; i < 2; i++) {
        // 四位数max
        printf("|  %-4d%-4d  |\n", tmp[i][0], tmp[i][1]);
    }
    
    printf("\n");
    printf("--------------------------------------------------\n\n");
}

void calculate_determinant_tw (int tmp[][2]) {
    int result;
    
    // 按对角线法则计算
    result = ( tmp[0][0] * tmp[1][1] ) - ( tmp[0][1] * tmp[1][0] );
    // 计算过程演示
    printf("计算过程 (calculation process): ");
    printf("(%d x %d) - (%d x %d) = %d;\n", tmp[0][0], tmp[1][1], tmp[0][1], tmp[1][0], result);
    // 结果演示
    printf("The final result: %d;\n", result);
    // 分割线
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n\n\n\n\n\n");
}

// 3 x 3 行列式
void input_nums_th (int tmp[][3]) {
    int i;
    
    for (i = 0; i < 3; i++) {
        printf("第 %d 行数据(first line): ", i + 1);
        scanf("%d %d %d", &tmp[i][0], &tmp[i][1], &tmp[i][2]);
    }
}

void show_determinant_th (int tmp[][3]) {
    int i;
    
    for (i = 0; i < 3; i++) {
        // 四位数max
        printf("|  %-4d%-4d%-4d  |\n", tmp[i][0], tmp[i][1], tmp[i][2]);
    }
    
    printf("\n");
    printf("--------------------------------------------------\n\n");
}

void calculate_determinant_th (int tmp[][3]) {
    int result;
    
    // 按对角线法则计算
    result = ( tmp[0][0] * tmp[1][1] * tmp[2][2]) + ( tmp[0][1] * tmp[1][2] * tmp[2][0] ) + ( tmp[1][0] * tmp[2][1] * tmp[0][2] ) - ( tmp[0][2] * tmp[1][1] * tmp[2][0]) - ( tmp[0][1] * tmp[1][2] * tmp[2][0] ) - ( tmp[1][0] * tmp[2][1] * tmp[0][2] );
    // 计算过程演示
    printf("计算过程 (calculation process): \n");
    printf("(%d x %d x %d) + (%d x %d x %d) + (%d x %d x %d) - (%d x %d x %d) - (%d x %d x %d) - (%d x %d x %d) = %d;\n", tmp[0][0], tmp[1][1], tmp[2][2], tmp[0][1], tmp[1][2], tmp[2][0], tmp[1][0], tmp[2][1], tmp[0][2], tmp[0][2], tmp[1][1], tmp[2][0], tmp[0][1], tmp[1][2], tmp[2][0], tmp[1][0], tmp[2][1], tmp[0][2], result);
    // 结果演示
    printf("The final result: %d;\n", result);
    // 分割线
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n\n\n\n\n\n");
}

void sub_menu_th (int tmp[][3]) {
    char if_show;
    
    printf("--------------------------------------------------\n");
    printf("是否演示行列式图 ?\n");
    printf("--in (y/ n):");
    scanf(" %c", &if_show);
    if (if_show == 'y') {
        printf("\n");
        show_determinant_th (tmp);
    }
    else {
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
    }
}

// 主程序
int main() {
    menu ();
    return 0;
}
