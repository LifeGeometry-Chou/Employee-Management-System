#include<stdio.h>
#include<stdlib.h>
#include"function_declaration.h"
void view(inf *emp,int *people_num)/**���**/
{
    printf("--------------ְ����Ϣ--------------\n");
    for(int i=0;i<*people_num;i++)
        printf("����:%d ����:%s �Ա�:%s ����:%s ѧ��:%s ����:%.2f סַ:%s �绰:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
}//view
