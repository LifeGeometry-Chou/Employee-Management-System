#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function_declaration.h"
void del(inf *emp,int *people_num,char file_name[])/**删除**/
{
    FILE *fp;
    char name[20];
    int i,j,select_num;

    /**以wb+方式打开文件，覆盖原有内容**/
    if((fp=fopen(file_name,"wb+"))==NULL)
    {
        printf("error!\n");
        return;
    }
    printf("1.按工号删除\n2.按姓名删除\n");
    printf("请选择：");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("请输入要删除职工信息的工号：");
            scanf("%d",&select_num);

            for(i=0;i<*people_num;i++)
            {
                if(emp[i].num==select_num)
                {
                    for(j=i;j<*people_num;j++)
                        emp[j]=emp[j+1];/**用后面的信息覆盖前面的信息**/
                    *people_num=*people_num-1;/**人数减一,修改主函数指针存放的内容**/
                }
            }
            break;
        case 2:
            printf("请输入要删除职工信息的姓名：");
            scanf("%s",name);
            getchar();

            for(i=0;i<*people_num;i++)
            {
                if(strcmp(emp[i].name,name)==0)
                {
                    for(j=i;j<*people_num;j++)
                        emp[j]=emp[j+1];
                    *people_num=*people_num-1;
                }
            }
            break;
        default:
            printf("输入错误！\n");
            fclose(fp);/**关闭文件**/
            return;/**返回至菜单功能选择**/
    }//switch
    /**写入文件**/
    for(i=0;i<*people_num;i++)
        fwrite(&emp[i],sizeof(inf),1,fp);
    printf("删除成功！\n");/**提示信息**/
    fclose(fp);/**关闭文件**/
}//del
