//学分系统
#include <stdio.h>

typedef double Type;
typedef struct ScoreManage {
    char id[11];//学号
    char name[15];//姓名
    Type maths;//高等数学 -5学分
    Type maths_1;//学费统一用 _1后缀 表示
    Type Cprogram;//C语言程序设计 -3.5
    Type Cprogram_1;
    Type PE;//体育 -2
    Type PE_1;
    Type English;//英语 -3
    Type English_1;
    Type Chinahistory;//中国革命史 -2
    Type Chinahistory_1;
    double gpa;//学分
    Type total;//总分
    double average;//平均分
} SM;

void Init_SM (SM Stu[]);//成绩录入
void Total_SM (SM Stu[]);//总分
void Aver_SM (SM Stu[]);//平均分
void GPA_SM (SM Stu[]);//学分 >=60才有学分，否则为0
void Sort_by_GAP (SM Stu[]);//根据学分排序 -冒泡排序
void Sort_by_Aver (SM Stu[]);//根据平均分排序
void Search_by_ID (SM Stu[]);//根据 id 查询学生信息
void Display (SM Stu[]);//输出学生信息

void Init_SM (SM Stu[]) {//成绩录入
    int i;
    for (i=0; i<3; i++)
        scanf("%s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", (Stu+i)->id, (Stu+i)->name, &(Stu+i)->maths, &(Stu+i)->maths_1, &(Stu+i)->Cprogram, &(Stu+i)->Cprogram_1, &(Stu+i)->PE, &(Stu+i)->PE_1, &(Stu+i)->English, &(Stu+i)->English_1, &(Stu+i)->Chinahistory, &(Stu+i)->Chinahistory_1);
    printf("\n");
}

void Total_SM (SM Stu[]) {
    int i;
    for (i=0; i<3; i++)
        (Stu+i)->total = (Stu+i)->maths + (Stu+i)->Cprogram + (Stu+i)->Chinahistory + (Stu+i)->PE + (Stu+i)->English;//五门课总成绩
}

void Aver_SM (SM Stu[]) {
    int i;
    for (i=0; i<3; i++)
        (Stu+i)->average = (Stu+i)->total / 5.0;
}

void GPA_SM (SM Stu[]) {
    int i;
    for (i=0; i<3; i++) {
        if ((Stu+i)->maths < 60)
            (Stu+i)->maths_1 = 0;
        if ((Stu+i)->English < 60)
            (Stu+i)->English_1 = 0;
        if ((Stu+i)->Cprogram < 60)
            (Stu+i)->Cprogram_1 = 0;
        if ((Stu+i)->Chinahistory < 60)
            (Stu+i)->Chinahistory_1 = 0;
        if((Stu+i)->PE < 60)
            (Stu+i)->PE_1 = 0;
        
        (Stu+i)->gpa = (Stu+i)->maths_1 + (Stu+i)->Cprogram_1 + (Stu+i)->English_1 + (Stu+i)->PE_1 + (Stu+i)->Chinahistory_1;
    }

}

void Sort_by_GAP (SM Stu[]) {
    int i, j;
    for (i=0; i<2; i++)
        for (j=i+1; j<3; j++)
            if((Stu+i)->gpa > (Stu+j)->gpa) {
                SM tmp;
                tmp = *(Stu+i);
                *(Stu+i) = *(Stu+j);
                *(Stu+j) = tmp;
            }
}

void Sort_by_Aver (SM Stu[]) {
    int i, j;
    for (i=0; i<2; i++)
        for (j=i+1; j<3; j++)
            if((Stu+i)->average > (Stu+j)->average) {
                SM tmp;
                tmp = *(Stu+i);
                *(Stu+i) = *(Stu+j);
                *(Stu+j) = tmp;
            }
}

void Search_by_ID (SM Stu[]) {
    int i;
    char search[11];

    printf("请输入您要查询的学生的id:\n");
    scanf("%s", search);

    for (i=0; i<3; i++)
        if ((Stu+i)->id[9] == search[9] && (Stu+i)->id[10] == search[10]) {
            printf("id         name   math math_1    Cprogram Cprogram_1    PE PE_1        English  English_1      Chinahistory Chinahistory_1   Total    GPA        Average\n");
            printf("%s %s    %d   %lf  %d       %lf      %d %lf    %d       %lf       %d           %lf         %d      %lf   %lf\n\n", (Stu+i)->id, (Stu+i)->name, (int)(Stu+i)->maths, (Stu+i)->maths_1, (int)(Stu+i)->Cprogram, (Stu+i)->Cprogram_1, (int)(Stu+i)->PE, (Stu+i)->PE_1, (int)(Stu+i)->English, (Stu+i)->English_1, (int)(Stu+i)->Chinahistory, (Stu+i)->Chinahistory_1, (int)(Stu+i)->total, (Stu+i)->gpa,(Stu+i)->average);
            return;
        }
}

void Display (SM Stu[]) {
    int i;
    
    printf("id         name   math math_1    Cprogram Cprogram_1    PE PE_1        English  English_1      Chinahistory Chinahistory_1   Total    GPA         Average\n");
    
    for (i=0; i<3; i++) {
        printf("%s %s    %d   %lf  %d       %lf      %d %lf    %d       %lf       %d           %lf         %d      %lf   %lf\n", (Stu+i)->id, (Stu+i)->name, (int)(Stu+i)->maths, (Stu+i)->maths_1, (int)(Stu+i)->Cprogram, (Stu+i)->Cprogram_1, (int)(Stu+i)->PE, (Stu+i)->PE_1, (int)(Stu+i)->English, (Stu+i)->English_1, (int)(Stu+i)->Chinahistory, (Stu+i)->Chinahistory_1, (int)(Stu+i)->total, (Stu+i)->gpa,(Stu+i)->average);
    }
    printf("\n");
}

int main() {
    SM stu[3];
    Init_SM (stu);
    Total_SM (stu);
    Aver_SM (stu);
    GPA_SM (stu);
    Display (stu);
    
    Sort_by_Aver(stu);
    Display (stu);
    
    Sort_by_Aver (stu);
    Display (stu);
    
    Search_by_ID (stu);
    
    return 0;
}
