#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function_declaration.h"
void mod(inf *emp,int *people_num,char file_name[])/**修改**/
{
    FILE *fp;
    int i,select_num,input_num;
    char input_name[10];

    if((fp=fopen(file_name,"rb+"))==NULL)
    {
        printf("error!\n");
        return;
    }
    printf("1.按姓名查询修改\n2.按工号查询修改\n");
    printf("请选择：");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("请输入职工姓名：");
            scanf("%s",input_name);

            for(i=0; i<*people_num; i++)
            {
                if(strcmp(emp[i].name,input_name)==0)
                {
                    printf("--------------职工信息--------------\n");
                    printf("工号:%d 姓名:%s 性别:%s 年龄:%s 学历:%s 工资:%.2f 住址:%s 电话:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
                    printf("1.职工号\n2.姓名\n3.性别\n4.年龄\n5.学历\n6.工资\n7.住址\n8.电话\n");
                    printf("请输入要修改的项目：");
                    scanf("%d",&select_num);
                    printf("请输入新信息：");
                    switch(select_num)
                    {
                        case 1:
                            scanf("%d",&emp[i].num);
                            break;
                        case 2:
                            scanf("%s",emp[i].name);
                            break;
                        case 3:
                            scanf("%s",emp[i].sex);
                            break;
                        case 4:
                            scanf("%s",emp[i].age);
                            break;
                        case 5:
                            scanf("%s",emp[i].deg);
                            break;
                        case 6:
                            scanf("%lf",&emp[i].pay);
                            break;
                        case 7:
                            scanf("%s",emp[i].add);
                            break;
                        case 8:
                            scanf("%s",emp[i].phone);
                            break;
                        default:
                            printf("输入错误！\n");
                            fclose(fp);/**关闭文件**/
                            return;/**返回至菜单功能选择**/
                    }//switch
                    break;//终止循环
                }//if
            }//for
            break;//case 1

        case 2:
            printf("请输入要修改职工信息的工号：");
            scanf("%d",&input_num);
            for(i=0; i<*people_num; i++)
            {
                if(emp[i].num==input_num)
                {
                    printf("--------------职工信息--------------\n");
                    printf("工号:%d 姓名:%s 性别:%s 年龄:%s 学历:%s 工资:%.2f 住址:%s 电话:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
                    printf("1.职工号\n2.姓名\n3.性别\n4.年龄\n5.学历\n6.工资\n7.住址\n8.电话\n");
                    printf("请输入要修改的项目：");
                    scanf("%d",&select_num);
                    printf("请输入新信息：");
                    switch(select_num)
                    {
                        case 1:
                            scanf("%d",&emp[i].num);
                            break;
                        case 2:
                            scanf("%s",emp[i].name);
                            break;
                        case 3:
                            scanf("%s",emp[i].sex);
                            break;
                        case 4:
                            scanf("%s",emp[i].age);
                            break;
                        case 5:
                            scanf("%s",emp[i].deg);
                            break;
                        case 6:
                            scanf("%lf",&emp[i].pay);
                            break;
                        case 7:
                            scanf("%s",emp[i].add);
                            break;
                        case 8:
                            scanf("%s",emp[i].phone);
                            break;
                        default:
                            printf("输入错误！\n");
                            fclose(fp);/**关闭文件**/
                            return;/**返回至菜单功能选择**/
                    }//switch
                    break;//终止循环
                }//if
            }//for
            break;//case 2

        default:
            printf("输入错误！\n");
            return;/**返回至菜单功能选择**/
    }//switch

    /**写入文件**/
    for(i=0;i<*people_num;i++)
        fwrite(&emp[i],sizeof(inf),1,fp);
    printf("修改成功！\n");/**提示信息**/
    fclose(fp);/**关闭文件**/
}//mod
