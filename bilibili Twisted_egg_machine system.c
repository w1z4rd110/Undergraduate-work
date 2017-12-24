#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
//初始化十个礼物
typedef struct Twisted_egg_machine{
    char gift_1[15];
    char gift_2[10];
    char gift_3[10];
    char gift_4[10];
    char gift_5[15];
    char gift_6[15];
    char gift_7[20];
    char gift_8[15];
    char gift_9[35];
    char gift_10[20];
}Tem, *pTem;

typedef struct tem{
    pTem data;
    unsigned size;
}tem;

void INIT_GIFT(pTem gift_1, const int N);//初始化礼物
void GET_RANDOM(pTem gift_1, const int N);//随机抽取礼物
void DISPLAY_GIFT(pTem gift_1, const int index);//打印抽取到的礼物
void WRITE_INTO_FILE(pTem gift_1, const int index);//写入桌面文件保存

void INIT_GIFT(pTem gift_1, const int N){
    int i;
    for(i=0; i<N; i++){
        printf("开始初始化第 %d 个礼物!\n",i+1);
        sleep(1);
        printf("请稍等");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".\n");
        //初始化礼物名称
        strcpy((gift_1+i)->gift_1,"蓝白胖次");
        strcpy((gift_1+i)->gift_2,"B坷垃");
        strcpy((gift_1+i)->gift_3,"亿圆");
        strcpy((gift_1+i)->gift_4,"辣条");
        strcpy((gift_1+i)->gift_5,"经验曜石");
        strcpy((gift_1+i)->gift_6,"经验原石");
        strcpy((gift_1+i)->gift_7,"全场最佳头衔");
        strcpy((gift_1+i)->gift_8,"爱心便当");
        strcpy((gift_1+i)->gift_9,"哔哩哔哩直播2018官方台历");
        strcpy((gift_1+i)->gift_10,"小号小电视");
//        printf("^_^第 %d 个礼物初始化完毕!^_^\n",i+1);
    }
    printf("\n");
}

void GET_RANDOM(pTem gift_1, const int N){
    int i,random;
    char click;

    srand((unsigned)time(0));//随机播种

    for(i=0; i<N; i++){
        printf("扭一次？\n");
        scanf("%c",&click);
        click = getchar();//读取缓冲区，避免由于scanf只能读取一个字符而因此自动跳过
        if(click == 'Y' || click == 'y'){
            random = rand()%10;//生成一个随机数
            switch(random){
                case 0:
                    DISPLAY_GIFT(gift_1, 0);
                    break;
                case 1:
                    DISPLAY_GIFT(gift_1, 1);
                    break;
                case 2:
                    DISPLAY_GIFT(gift_1, 2);
                    break;
                case 3:
                    DISPLAY_GIFT(gift_1, 3);
                    break;
                case 4:
                    DISPLAY_GIFT(gift_1, 4);
                    break;
                case 5:
                    DISPLAY_GIFT(gift_1, 5);
                    break;
                case 6:
                    DISPLAY_GIFT(gift_1, 6);
                    break;
                case 7:
                    DISPLAY_GIFT(gift_1, 7);
                    break;
                case 8:
                    DISPLAY_GIFT(gift_1, 8);
                    break;
                case 9:
                    DISPLAY_GIFT(gift_1, 9);
                    break;

                default:
                    break;
            }
        }
        printf("\n");
    }
}

void DISPLAY_GIFT(pTem gift_1, const int index){
    if(index == 0){
        printf("恭喜您！获得了%s\n",gift_1->gift_1);
//        printf("您还剩下 %d 次机会\n",);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 1){
        printf("恭喜您！获得了%s\n",gift_1->gift_2);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 2){
        printf("恭喜您！获得了%s\n",gift_1->gift_3);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 3){
        printf("恭喜您！获得了%s\n",gift_1->gift_4);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 4){
        printf("恭喜您！获得了%s\n",gift_1->gift_5);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 5){
        printf("恭喜您！获得了%s\n",gift_1->gift_6);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 6){
        printf("恭喜您！获得了%s\n",gift_1->gift_7);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 7){
        printf("恭喜您！获得了%s\n",gift_1->gift_8);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 8){
        printf("恭喜您！获得了%s\n",gift_1->gift_9);
        WRITE_INTO_FILE(gift_1, index);
    }
    else if(index == 9){
        printf("恭喜您！获得了%s\n",gift_1->gift_10);
        WRITE_INTO_FILE(gift_1, index);
    }
}

void WRITE_INTO_FILE(pTem gift_1, const int index){//写入本地文件
    FILE * fp;
    fp = fopen("/Users/apple/Desktop/myloop-1.txt", "a");//文件路径一定不要写错
                                                         //"/Users/apple/Desktop/myloop-1.txt"是我电脑上的文件名，你可以改为自己的
    if(index == 0)
        fprintf(fp, "%s\n", gift_1->gift_1);
    else if(index == 1)
        fprintf(fp, "%s\n", gift_1->gift_2);
    else if(index == 2)
        fprintf(fp, "%s\n", gift_1->gift_3);
    else if(index == 3)
        fprintf(fp, "%s\n", gift_1->gift_4);
    else if(index == 4)
        fprintf(fp, "%s\n", gift_1->gift_5);
    else if(index == 5)
        fprintf(fp, "%s\n", gift_1->gift_6);
    else if(index == 6)
        fprintf(fp, "%s\n", gift_1->gift_7);
    else if(index == 7)
        fprintf(fp, "%s\n", gift_1->gift_8);
    else if(index == 8)
        fprintf(fp, "%s\n", gift_1->gift_9);
    else if(index == 9)
        fprintf(fp, "%s\n", gift_1->gift_10);
    fclose(fp);
}

int main(){
    int n;
    tem tem_1;

    printf("请输入抽奖机会的次数：\n");
    scanf("%d",&n);
    printf("\n");

    tem_1.size = n;
    tem_1.data = (pTem)malloc(n * sizeof(Tem));

    //调用函数
    INIT_GIFT(tem_1.data, n);
    GET_RANDOM(tem_1.data, n);
    DISPLAY_GIFT(tem_1.data, n);

    return 0;
}


