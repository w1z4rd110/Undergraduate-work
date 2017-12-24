//操作系统周转时间
#include <stdio.h>
struct{
    float ArriveTime;
    float RunningTime;
}Job[10];

void Gettask(){
    int i,j,a,n,q,w,e,g,h;
    float b,c,t,z;
    float L=0;
    float sum=0;
    float ALL=0;
    float K=0;
    float TT;
    float ATT;
    float Y;
    printf("请输入进程个数（小于10）：");
    scanf("%d",&a);
    j = a;
    for(i=0; i<j; i++){
        printf("请输入 Job[%d] 的到达时间：",j+1);
        scanf("%f",&b);
        Job[i].ArriveTime = b;
        printf("请输入 Job[%d] 的运行时间：",i+1);
        scanf("%f",&c);
        Job[i].RunningTime = c;
    }
    printf("\n");
    for(n=0; n<(a-1); n++)
        for(i=0; i<(a-n-1); i++)
            if(Job[i].ArriveTime > Job[i+1].ArriveTime){
                t = Job[i].ArriveTime;
                Job[i].ArriveTime = Job[i+1].ArriveTime;
                Job[i+1].ArriveTime = t;
                z = Job[i].RunningTime;
                Job[i].RunningTime = Job[i+1].RunningTime;
                Job[i+1].RunningTime = z;
            }
    printf("(按从上到下次序运行)\n");
    printf("到达时间\t\t运行时间\n");
    for(i=0; i<a; i++)
        printf("%f\t\t%f\n",Job[i].ArriveTime,Job[i].RunningTime);
    printf("\n");
    printf("开始时间\t\t结束时间\n");
    for(g=0; g<a; g++){
        for(h=0; h<g+1; h++)
            L += Job[h].RunningTime;
        Y = L+Job[0].ArriveTime;
        printf("%f\t\t%f\n",Y-Job[g].RunningTime,Y);
        L = 0;
    }
    printf("\n");
    for(q=0; q<a; q++)
        sum += Job[q].ArriveTime;
    for(w=0; w<a;w++){
        for(e=0; e<w+1; e++)
            K += Job[e].RunningTime;
        ALL += K;
        K = 0;
    }
    TT = a*Job[0].ArriveTime+ALL-sum;
    ATT = TT/a;
    printf("周转时间：%f\n",TT);
    printf("平均周转时间：%f\n",ATT);
}
int main(){
    Gettask();
    return 0;
}
