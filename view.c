#include<stdio.h>
#include<stdlib.h>
#include"function_declaration.h"
void view(inf *emp,int *people_num)/**浏览**/
{
    printf("--------------职工信息--------------\n");
    for(int i=0;i<*people_num;i++)
        printf("工号:%d 姓名:%s 性别:%s 年龄:%s 学历:%s 工资:%.2f 住址:%s 电话:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
}//view
