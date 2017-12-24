//图书管理信息系统
//暂未测试

#include <stdio.h>
#include <stdlib.h>
typedef struct BOOK * pBook;
typedef struct BOOK{
    int bookprice;//图书价格 数字
    char bookauthor[10];//作者 中文
    char bookid[15];//书目编号 字符串 e.g. G109/44-52
    char bookname[20];//书目名称 中文
    char bookpublishinghouse[30];//出版社 中文
}Book;

//四个函数实现：图书采编、图书编目、图书查询及图书流通（借、还书）
void InitBook(pBook book_0, const int N);//初始化书目的数目以及书目的详细信息 -
void SortBook_Id(pBook book_0, const int N);//通过书目的 id 对书目进行排序 -
void SortBook_Price(pBook book_0, const int N);//通过书目的 price 对书目进行排序 -
void isEmpty(pBook book_0, const int N, const int index);//判断应该放置第 i+1 个书本的位置是否为空 -
void IsEmpty(pBook book_0);//判断图书馆书架是否为空 -
void isFull(pBook book_0, const int N);//判断图书馆书架是否已满 -
void BorrowBook(pBook book_0, const int N);//借书：通过输入 id 或者 书名 或者 书的作者 来搜索书目信息并输出，确认是否借书 -
void ReturnBook(pBook book_0);//还书
void DisplayBook(pBook book_0, const int N);//显示当前书架上现有的书目 -
void Search_Price(pBook book_0, const int N);//通过书目的价格查找书目的详细信息
void Search_Author(pBook book_0, const int N);//通过书的作者查找书目的详细信息
void Search_Id(pBook book_0, const int N);//通过书目的 id 查找书目的详细信息
void Search_Name(pBook book_0, const int N);//通过书名查找书目的详细信息
void Search_PblishingHouse(pBook book_0, const int N);//通过书目的出版社查找书目的详细信息
void FreeBook(pBook book_0);//释放空间

void InitBook(pBook book_0, const int N){
    int i;
    for(i=0;i<N;i++){
        printf("bookprice: ");
        scanf("%d",&(book_0+i)->bookprice);
        printf("bookauthor: ");
        scanf("%s",(book_0+i)->bookauthor);
        printf("bookid: ");
        scanf("%s",(book_0+i)->bookid);
        printf("bookname: ");
        scanf("%s",(book_0+i)->bookname);
        printf("bookpublishinghouse: ");
        scanf("%s",(book_0+i)->bookpublishinghouse);
        printf("\n");
    }
    printf("\n");
}

void SortBook_Id(pBook book_0, const int N){
    int i,j,k;
    for(i=0; i<N-1; i++)
        for(j=i+1; j<N; j++)
            for(k=0; k<N-1; k++)
                if((book_0+i)->bookid[k] > (book_0+j)->bookid[k+1]){
                    Book temp;
                    temp = *(book_0+i);
                    *(book_0+i) = *(book_0+j);
                    *(book_0+j) = temp;
                }
}

void SortBook_Price(pBook book_0, const int N){
    int i,j;
    for(i=0; i<N-1; i++)
        for(j=i+1; j<N; j++)
            if((book_0+i)->bookprice > (book_0+j)->bookprice){
                Book temp;
                temp = *(book_0+i);
                *(book_0+i) = *(book_0+j);
                *(book_0+j) = temp;
            }
}

void isEmpty(pBook book_0, const int N, const int index){
    int i;
    for(i=0; i<N; i++)
        if(N == index){
            if((book_0+index)->bookprice)
                printf("Not empty\n");
            else
                printf("Empty\n");
        }
}

void IsEmpty(pBook book_0){
    if(book_0->bookprice)
        printf("Not empty\n");
    else
        printf("Empty\n");
}

void isFull(pBook book_0, const int N){
    if((book_0+N)->bookprice)
        printf("Full\n");
    else
        printf("Not full\n");
}

void BorrowBook(pBook book_0, const int N){//搜索函数
    int i,j,counter=0;
    char search[20],book_1;
    
    printf("搜索🔍：");
    scanf("%s",search);
    
    for(i=0; i<N; i++){
        for(j=0; j<20; j++)
            if((book_0+i)->bookname[j] == search[j]){
                counter++;
                if(counter == 20){
                    printf("您选中的书目是%s,该书的详细信息如下：\n",search);
                    printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
                    scanf("%c",&book_1);
                    getchar();
                    if(book_1 == 'y' || book_1 == 'Y')
                        printf("^_^好的，您已经成功从图书馆借出该书，请按时归还，祝您阅读愉快，有所收获！^_^\n");
                    return;
                }
            }
            else
                break;
    
    for(j=0; j<10; j++)
        if((book_0+i)->bookauthor[j] == search[j]){
            counter++;
            if(counter == 10){
                printf("您选中的书目作者是%s,该书的详细信息如下：\n",search);
                printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
                scanf("%c",&book_1);
                getchar();
                if(book_1 == 'y' || book_1 == 'Y')
                    printf("^_^好的，您已经成功从图书馆借出该书，请按时归还，祝您阅读愉快，有所收获！^_^\n");
                return;
            }
        }
            else
                break;
    
    for(j=0; j<15; j++)
        if((book_0+i)->bookid[j] == search[j]){
            counter++;
            if(counter == 15){
                printf("您选中的书目id是%s,该书的详细信息如下：\n",search);
                printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
                printf("是否借书？\n");
                scanf("%c",&book_1);
                getchar();
                if(book_1 == 'y' || book_1 == 'Y')
                    printf("^_^好的，您已经成功从图书馆借出该书，请按时归还，祝您阅读愉快，有所收获！^_^\n");
                return;
            }
        }
        else
            break;
    }
}

void ReturnBook(pBook book_0){
    
}

void DisplayBook(pBook book_0, const int N){
    int i;
    for(i=0; i<N; i++){
        printf("bookprice: %d\n",(book_0+i)->bookprice);
        printf("bookauthor: %s\n",(book_0+i)->bookauthor);
        printf("bookid: %s\n",(book_0+i)->bookid);
        printf("bookname: %s\n",(book_0+i)->bookname);
        printf("bookpublishinghouse: %s\n",(book_0+i)->bookpublishinghouse);
        printf("\n");
    }
}

void Search_Price(pBook book_0, const int N){
    int i,price;
    scanf("%d",&price);
    for(i=0; i<N; i++)
        if((book_0+i)->bookprice == price){
            printf("您选中的书目是%s,该书的详细信息如下：\n",(book_0+i)->bookname);
            printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
        }
}

void Search_Author(pBook book_0, const int N){
    int i,j,counter=0;
    char search[20],book_1;
    
    printf("搜索🔍：");
    scanf("%s",search);
    for(i=0; i<N; i++)
        for(j=0; j<10; j++)
            if((book_0+i)->bookauthor[j] == search[j]){
                counter++;
                if(counter == 10){
                    printf("您选中的书目作者是%s,该书的详细信息如下：\n",search);
                    printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
                    scanf("%c",&book_1);
                    getchar();
                    if(book_1 == 'y' || book_1 == 'Y')
                        printf("^_^好的，您已经成功从图书馆借出该书，请按时归还，祝您阅读愉快，有所收获！^_^\n");
                    return;
                }
            }
            else
                break;
}

void Search_Id(pBook book_0, const int N){
    int i,j,counter=0;
    char search[20],book_1;
    
    printf("搜索🔍：");
    scanf("%s",search);
    
    for(i=0; i<N; i++)
        for(j=0; j<15; j++)
            if((book_0+i)->bookid[j] == search[j]){
                counter++;
                if(counter == 15){
                    printf("您选中的书目id是%s,该书的详细信息如下：\n",search);
                    printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
                    printf("是否借书？\n");
                    scanf("%c",&book_1);
                    getchar();
                    if(book_1 == 'y' || book_1 == 'Y')
                        printf("^_^好的，您已经成功从图书馆借出该书，请按时归还，祝您阅读愉快，有所收获！^_^\n");
                    return;
                }
            }
            else
                break;
}

void Search_Name(pBook book_0, const int N){
    int i,j,counter=0;
    char search[20],book_1;
    
    printf("搜索🔍：");
    scanf("%s",search);
    
    for(i=0; i<N; i++)
        for(j=0; j<20; j++)
            if((book_0+i)->bookname[j] == search[j]){
                counter++;
                if(counter == 20){
                    printf("您选中的书目是%s,该书的详细信息如下：\n",search);
                    printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
                    scanf("%c",&book_1);
                    getchar();
                    if(book_1 == 'y' || book_1 == 'Y')
                        printf("^_^好的，您已经成功从图书馆借出该书，请按时归还，祝您阅读愉快，有所收获！^_^\n");
                    return;
                }
            }
            else
                break;
}

void Search_PblishingHouse(pBook book_0, const int N){
    int i,j,counter=0;
    char search[20],book_1;
    
    printf("搜索🔍：");
    scanf("%s",search);
    
    for(i=0; i<N; i++)
        for(j=0; j<20; j++)
            if((book_0+i)->bookpublishinghouse[j] == search[j]){
                counter++;
                if(counter == 20){
                    printf("您选中的书目的出版社是%s,该书的详细信息如下：\n",search);
                    printf("%d %s %s %s %s\n",(book_0+i)->bookprice,(book_0+i)->bookauthor,(book_0+i)->bookid,(book_0+i)->bookname,(book_0+i)->bookpublishinghouse);
                    scanf("%c",&book_1);
                    getchar();
                    if(book_1 == 'y' || book_1 == 'Y')
                        printf("^_^好的，您已经成功从图书馆借出该书，请按时归还，祝您阅读愉快，有所收获！^_^\n");
                    return;
                }
            }
            else
                break;
}

void FreeBook(pBook book_0){
    free(book_0);
    book_0 = NULL;
}

int main(){
    int n;
    printf("请输入您要放置的书的数目：");
    scanf("%d",&n);
    printf("\n");

    pBook book = (pBook)malloc(n*sizeof(Book));

    InitBook(book, n);
    DisplayBook(book, n);
    return 0;
}
