/*
 * 游戏角色属性分析系统 *
 */
 
#include <stdio.h>
#include <stdlib.h>
typedef double type;

typedef struct GCAA{
    int id;//编号
    char type[10];//类型
    char name[20];//名字
    type attack;//攻击力
    type defense;//防御力
    type movespeed;//移动速度
    type compsive_value;//综合值
}GCAA;//Game_Character_Attributions_Analyze 游戏角色属性分析

typedef struct gcaa{
    GCAA * Character;
    int size;
    int max;
}gcaa;

void Init_Gamer(gcaa * Gamer, int N);//初始化游戏角色数组
void Free_Gamer(gcaa * Gamer);//释放数组空间
//void Insert_Rear(gcaa Gamer, int index);//尾部插入游戏角色属性
//void Insert(gcaa Gamer, int index, int item);//定点插入游戏角色属性
//void Delete_Rear(gcaa Gamer);//尾部删除游戏角色
void Delete(gcaa * Gamer, int index);//定点删除游戏角色
void Clear(gcaa * Gamer);//清空游戏角色属性
void isEmpty(const gcaa * Gamer);//判断游戏角色数目（数组）是否为 0
void isFull(const gcaa * Gamer);//判断游戏角色数目（数组）是否为 max，即数组已满
int getSize(const gcaa Gamer);//获取游戏角色数目 size
void Search_by_id(const gcaa * Gamer, const int id, const int N);//根据游戏角色编号查询该游戏角色所有属性
void Search_by_Type(const gcaa * Gamer, const char * ptype, const int N);//根据游戏角色类型查询该游戏角色所有属性
void Search_by_name(const gcaa * Gamer, const char * pname, const int N);//根据游戏角色名称查询该游戏角色所有属性
void Search_by_atk_def_mov_comva(const gcaa * Gamer, const int atk_def_mov_comva, const int N);//根据游戏角色 攻击力 或者 防御力 或者 综合值 查询该游戏角色所有属性
void Sort_by_Attack(const gcaa * Gamer, const int N);//直接插入排序，根据游戏角色攻击力对游戏角色排序
void Sort_by_Defense(const gcaa * Gamer, const int N);//冒泡排序，根据游戏角色防御力对游戏角色排序
void Sort_by_Movespeed(const gcaa * Gamer, const int N);//直接选择排序，根据游戏角色移动速度对游戏角色排序
void Sort_by_CompsiveValue(const gcaa * Gamer, const int N);//冒泡排序，根据游戏角色综合值对游戏角色排序
void ShowAll(const gcaa * Gamer, const int N);

void Init_Gamer(gcaa * Gamer, int N){
    int i;
    for(i=0; i<N; i++){
        printf("请输入第 %d 个角色的属性：\n",i+1);
        printf("游戏角色编号：\n");
        scanf("%d",&Gamer->Character[i].id);
        printf("游戏角色类型：\n");
        scanf("%s",Gamer->Character[i].type);
        printf("游戏角色名称：\n");
        scanf("%s",Gamer->Character[i].name);
        printf("游戏角色攻击力：\n");
        scanf("%lf",&Gamer->Character[i].attack);
        printf("游戏角色防御力：\n");
        scanf("%lf",&Gamer->Character[i].defense);
        printf("游戏角色移动速度：\n");
        scanf("%lf",&Gamer->Character[i].movespeed);
        
        Gamer->Character[i].compsive_value = (Gamer->Character[i].attack+Gamer->Character[i].defense+Gamer->Character[i].movespeed)/3.0;
        Gamer->size++;
        printf("\n");
    }
    printf("\n");
}

void Free_Gamer(gcaa * Gamer){
    free(Gamer->Character);
}

void Delete(gcaa * Gamer, int index){
    int i;
    if(index<0 || index>Gamer->size-1){
        printf("Delete: index is illegal or list is empty!\n");
        exit(1);
    }
    for(i=index+1; i<Gamer->size; i++)
        Gamer->Character[i-1] = Gamer->Character[i];
    Gamer->size--;
    printf("下标为 %d 的游戏角色已被删除!\n",index);
}

void Clear(gcaa * Gamer){
    Gamer->size = 0;
    printf("游戏角色全部消除完毕!\n");
}

void isEmpty(const gcaa * Gamer){
    if(Gamer->size == 0)
        printf("Yes\n");
    else
        printf("No\n");
    printf("\n");
}

void isFull(const gcaa * Gamer){
    if(Gamer->size == Gamer->max)
        printf("Yes\n");
    else
        printf("No\n");
    printf("\n");
}

int getSize(gcaa Gamer){
    return Gamer.size;
}

void Search_by_id(const gcaa * Gamer, const int id, const int N){
    int i;
    for(i=0; i<N; i++)
        if(id == Gamer->Character[i].id){
            printf("%d %s %s %lf %lf %lf %lf",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
            break;
        }
}

void Search_by_Type(const gcaa * Gamer, const char * ptype, const int N){
    int i,j,counter=0;
    for(i=0; i<N; i++)
        for(j=0; j<10; j++)
            if(ptype[j] == Gamer->Character[i].type[j])
                counter++;
            else
                break;
    if(counter == 10)
        printf("%d %s %s %lf %lf %lf %lf",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
}

void Search_by_name(const gcaa * Gamer, const char * pname, const int N){
    int i,j,counter=0;
    for(i=0; i<N; i++)
        for(j=0; j<20; j++)
            if(pname[j] == Gamer->Character[i].name[j])
                counter++;
            else
                break;
    if(counter == 20)
        printf("%d %s %s %lf %lf %lf %lf",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
}

void Search_by_atk_def_mov_comva(const gcaa * Gamer, const int atk_def_mov_comva, const int N){
    int i;
    for(i=0; i<N; i++)
        if(atk_def_mov_comva == Gamer->Character[i].attack)
            printf("%d %s %s %lf %lf %lf %lf",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
        else if (atk_def_mov_comva == Gamer->Character[i].defense)
            printf("%d %s %s %lf %lf %lf %lf",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
        else if(atk_def_mov_comva == Gamer->Character[i].movespeed)
            printf("%d %s %s %lf %lf %lf %lf",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
        else if (atk_def_mov_comva == Gamer->Character[i].compsive_value)
            printf("%d %s %s %lf %lf %lf %lf",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
}

void Sort_by_Attack(const gcaa * Gamer, const int N){
    int i,j;
    GCAA temp_0;
    for(i=1; i<N; i++){
        temp_0 = Gamer->Character[i];//temp_0 为要插入的元素
        j = i-1;
        while(j>=0 && temp_0.attack<Gamer->Character[j].attack){
            Gamer->Character[j+1] = Gamer->Character[j];
            j--;
        }
        Gamer->Character[j+1] = temp_0;
    }
}

void Sort_by_Defense(const gcaa * Gamer, const int N){
    int i,j;
    for(i=0; i<N-1; i++)
        for(j=i+1; j<N; j++)
            if(Gamer->Character[i].defense < Gamer->Character[i].defense){
                GCAA temp;
                temp = Gamer->Character[i];
                Gamer->Character[i] = Gamer->Character[j];
                Gamer->Character[j] = temp;
            }
}

void Sort_by_Movespeed(const gcaa * Gamer, const int N){
    int i,j,k;
    GCAA temp_1;
    for(i=0; i<N-1; i++){
        k=i;
        for(j=i+1; j<N; j++)
            if(Gamer->Character[k].movespeed > Gamer->Character[j].movespeed)
                k = j;
        if(i != k){
            temp_1 = Gamer->Character[i];
            Gamer->Character[i] = Gamer->Character[k];
            Gamer->Character[k] = temp_1;
        }
    }
}

void Sort_by_CompsiveValue(const gcaa * Gamer, const int N){
    int i,j,k;
    GCAA shell;
    k =(int)N/2;
    while(k >= 1){
        for(i=k; i<N; i++){
            shell = Gamer->Character[i];
            j = i-k;
            while(j>=0 && shell.compsive_value<Gamer->Character[j].compsive_value){
                Gamer->Character[j+k] = Gamer->Character[j];
                j -= k;
            }
            Gamer->Character[j+k] = shell;
        }
        k /= 2;
    }
}

void ShowAll(const gcaa * Gamer, const int N){
    int i;
    for(i=0; i<N; i++){
        printf("第 %d 个游戏角色的属性如下：\n",i+1);
        printf("id: %d\t type: %s\t name: %s\t attack:%lf\t defense: %lf\t movespeed: %lf\t compsive_value: %lf\n",Gamer->Character[i].id,Gamer->Character[i].type,Gamer->Character[i].name,Gamer->Character[i].attack,Gamer->Character[i].defense,Gamer->Character[i].movespeed,Gamer->Character[i].compsive_value);
    }
}

int main(){
    gcaa gamer;
    int n,index;//几个角色
    printf("请输入角色数目:\n");
    scanf("%d",&n);
    
    gamer.Character = (GCAA *)malloc(sizeof(GCAA)*n);
    gamer.max = n;
    gamer.size = 0;
    
    isEmpty(&gamer);
    Init_Gamer(&gamer, n);
    printf("Size: %d\n",getSize(gamer));
    isFull(&gamer);
//    printf("请输入你想要删除的游戏角色的下标：\n");
//    scanf("%d",&index);
//    Delete(&gamer, index);
    Sort_by_Attack(&gamer, n);
    Sort_by_Defense(&gamer, n);
    Sort_by_Movespeed(&gamer, n);
    Sort_by_CompsiveValue(&gamer, n);
    ShowAll(&gamer, n);
    Free_Gamer(&gamer);
    
    return 0;
}
