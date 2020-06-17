#include <stdio.h>
#include <stdlib.h>
#include "function_declaration.h"
/*

function_declaration.h

typedef struct
{
    int num;
    char name[20];
    char sex[20];
    char age[20];
    char deg[20];
    double pay;
    char add[20];
    char phone[20];
}inf;
void menus();
void input(inf *emp,int *people_num,char file_name[]);
void view(inf *emp,int *p);
void search_sort(inf *emp,int *people_num,char file_name[]);
void del(inf *emp,int *people_num,char file_name[]);
void mod(inf *emp,int *people_num,char file_name[]);

*/

#define N 100 /**定义最大职工人数**/
int main()
{
    char file_name[20];
    int select_num,num=N;
    int *people_num=&num;/**该指针用于记录有效职工人数**/
    inf emp[N];/**定义最大容量为N人的结构体数组**/

    menus();/**调用菜单**/
    while(1)
    {
        printf("--------------------------------\n");/**划分开便于观看**/
        printf("请输入菜单中你要的功能：");
        scanf("%d",&select_num);
        switch(select_num)
        {
            case 1:
                input(emp,people_num,file_name);
                break;
            case 2:
                view(emp,people_num);
                break;
            case 3:
                search_sort(emp,people_num,file_name);
                break;
            case 4:
                del(emp,people_num,file_name);
                break;
            case 5:
                mod(emp,people_num,file_name);
                break;
            case 6:
                system("cls");
                menus();/**清屏后返回至主菜单**/
                break;
            case 7:
                return 0;
            default:
                printf("输入错误！\n");
        }//switch
    }//while
}//main
