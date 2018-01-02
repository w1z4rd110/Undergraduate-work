///学生试卷分析统计
#include <stdio.h>
#include <string.h>
typedef struct Text_Analyze TA;
struct Text_Analyze {
    char id[11];//学号
    char name[20];//姓名
    int attendscore;//出勤成绩 10分制
    int assignscore;//作业成绩 10分制
    int finalexamscore;// 期末考试成绩 100分
    int totalscore;//总成绩 100分
    char scorerank_3[10];//成绩等级
                         //优：89<score<=100
                         //良：79<score<=89
                         //中：69<score<=79
                         //及格：59<score<=69
                         //不及格：<59
};

void Init (TA pta[]);      //输入学生信息，进行初始化
void Totalscore (TA pta[]);//计算所有学生的总成绩并返回数组首地址
void Display_0 (TA pta[]); //输出所有学生的信息
void Display_1 (TA pta[]); //输出总分最低分学生的分数、学号、姓名
void Display_2 (TA pta[]); //输出编写程序作者自己的信息
void Rank (TA pta[]);
void Sort (TA pta[]);      //先对所有人的总分进行升序排序（冒泡排序法），排好后第一个人的总分最低，最后一个人总分最高
void Sata (TA pta[]);      //统计

void Display_2(TA pta[]) {
    char search[11] = "3216008955";
    int i = 0;
    while (1) {
        if((pta+i)->id[9] == search[9] && (pta+i)->id[10] == search[10]) {
            printf("学号        姓名  出勤成绩 作业成绩 期末成绩 总成绩 成绩等级\n");
            printf("%s %s    %d       %d       %d     %d    %s\n",(pta+i)->id, (pta+i)->name, (pta+i)->attendscore, (pta+i)->assignscore, (pta+i)->finalexamscore, (pta+i)->totalscore, (pta+i)->scorerank_3);
            break;
        }
        i++;
    }
}

void Sata (TA pta[]) {//分别统计优、良、中、及格、不及格的人数和百分比
    int i;
    double rank_0, rank_1, rank_2, rank_3, rank_4;//百分比
    int pp_0 = 0, pp_1 = 0, pp_2 = 0, pp_3 = 0, pp_4 = 0;//人数

    for (i=0; i<39; i++) {
        //判断总分等级
        if (89 < (pta+i)->totalscore && (pta+i)->totalscore <= 100)
            pp_0++;
        else if (79 < (pta+i)->totalscore && (pta+i)->totalscore <= 89)
            pp_1++;
        else if (69 < (pta+i)->totalscore && (pta+i)->totalscore <= 79)
            pp_2++;
        else if (59 < (pta+i)->totalscore && (pta+i)->totalscore <= 69)
            pp_3++;
        else if ((pta+i)->totalscore < 59)
            pp_4++;
    }

    rank_0 = 100 * (double)(pp_0) / 3.0;
    rank_1 = 100 * (double)(pp_1) / 3.0;
    rank_2 = 100 * (double)(pp_2) / 3.0;
    rank_3 = 100 * (double)(pp_3) / 3.0;
    rank_4 = 100 * (double)(pp_4) / 3.0;

    printf("优 百分比         良 百分比       中 百分比       及格 百分比       不及格 百分比\n");
    printf("%d %lf   %d %lf   %d %lf    %d %lf    %d  %lf\n", pp_0, rank_0, pp_1, rank_1, pp_2, rank_2, pp_3, rank_3, pp_4, rank_4);
}

void Sort (TA pta[]) {//冒泡排序
    int i,j;

    for (i=0; i<38; i++)
        for (j=i+1; j<10; j++)
            if((pta+i)->totalscore < (pta+j)->totalscore) {
                TA temp;
                temp = *(pta+i);
                *(pta+i) = *(pta+j);
                *(pta+j) = temp;
            }
}

void Display_1 (TA pta[]) {
    printf("最高分  学号         姓名      最低分  学号         姓名\n");
    printf("%d     %s  %s     %d    %s  %s\n", pta->totalscore, pta->id, pta->name, (pta+2)->totalscore, (pta+38)->id, (pta+38)->name);
}

void Init (TA pta[]) {
    int i;
    for (i=0; i<10; i++) {
//        printf("请输入第%d名同学的学号，姓名，出勤成绩，作业成绩， 期末成绩:\n",i+1);
        scanf("%s %s %d %d %d", (pta+i)->id, (pta+i)->name, &(pta+i)->attendscore, &(pta+i)->assignscore, &(pta+i)->finalexamscore);
    }
}

void Totalscore (TA pta[]) {
    int i;
    for (i=0; i<10; i++)
        (pta+i)->totalscore = (pta+i)->assignscore + (pta+i)->attendscore + (double)(pta+i)->finalexamscore * 0.8;
}

void Display_0 (TA pta[]) {//全部输出
    int i;
    
    printf("学号        姓名    出勤成绩  作业成绩   期末成绩   总成绩   成绩等级\n");
    for (i=0; i<10; i++) {
        printf("%s %s %4d     %4d       %4d     %4d      %s\n", (pta+i)->id, (pta+i)->name, (pta+i)->attendscore, (pta+i)->assignscore, (pta+i)->finalexamscore, (pta+i)->totalscore,  (pta+i)->scorerank_3);
    }
}

void Rank(TA pta[]) {
    int i;
    for (i=0; i<10; i++) {
        //判断总分等级
        if (89 < (pta+i)->totalscore && (pta+i)->totalscore <= 100)
            strcpy((pta+i)->scorerank_3,"优秀");
        else if (79 < (pta+i)->totalscore && (pta+i)->totalscore <= 89)
            strcpy((pta+i)->scorerank_3,"良");
        else if (69 < (pta+i)->totalscore && (pta+i)->totalscore <= 79)
            strcpy((pta+i)->scorerank_3,"中");
        else if (59 < (pta+i)->totalscore && (pta+i)->totalscore <= 69)
            strcpy((pta+i)->scorerank_3,"及格");
        else if ((pta+i)->totalscore < 59)
            strcpy((pta+i)->scorerank_3,"不及格");
    }
}

int main() {
    TA ta[10];
    Init (ta);//输入学生信息

    Totalscore (ta);//统计总分
    Rank (ta);//成绩等级
    Display_0 (ta);//（1）
    printf("\n\n");

    Sort(ta);//成绩排序
    Display_1(ta);//（2）
    printf("\n\n");

    Sata(ta);//统计人数、百分比
    printf("\n\n");

    Display_2(ta);//输出作者成绩单信息
    printf("\n\n");

    Display_0(ta);
    return 0;
}
