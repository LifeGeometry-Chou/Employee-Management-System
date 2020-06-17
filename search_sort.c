#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function_declaration.h"
void search_sort(inf *emp,int *people_num,char file_name[])/**查询和排序**/
{
    FILE *fp;
    double wage1,wage2;/**wage1,wage2分别为工资范围的上下限**/
    int select_num,record_position;
    int i,j;
    char input_degree[10];
    inf temp;/**结构体变量交换的中间变量**/

    printf("1.按工资查询\n2.按学历查询\n3.按工号排序\n");
    printf("请选择功能：");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("请输入工资范围(空格键隔开)：");
            scanf("%lf %lf",&wage1,&wage2);
            printf("--------------工资范围在%.2f~%.2f的职工信息--------------\n",wage1,wage2);
            for(i=0;i<*people_num;i++)
            {
                if((emp[i].pay>=wage1&&emp[i].pay<=wage2)||(emp[i].pay>=wage2&&emp[i].pay<=wage1))
                    printf("工号:%d 姓名:%s 性别:%s 年龄:%s 学历:%s 工资:%.2f 住址:%s 电话:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
            }
            break;

        case 2:
            printf("请输入学历：");
            scanf("%s",input_degree);
            printf("--------------具有%s学历的职工信息--------------\n",input_degree);
            /**找出对应学历的职工并输出这些职工的信息**/
            for(i=0;i<*people_num;i++)
            {
                if(strcmp(emp[i].deg,input_degree)==0)
                    printf("工号:%d 姓名:%s 性别:%s 年龄:%s 学历:%s 工资:%.2f 住址:%s 电话:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
            }
            break;

        case 3:
            if((fp=fopen(file_name,"wb"))==NULL)
            {
                printf("error!\n");
                return;
            }
            printf("1.升序\n2.降序\n");
            printf("请选择排序方法：");
            scanf("%d",&select_num);
            switch(select_num)
            {
                /***选择法排序***/
                case 1:
                    for(i=0;i<*people_num-1;i++)
                    {
                        record_position=i;
                        for(j=i+1;j<*people_num;j++)
                        {
                            if(emp[j].num<emp[record_position].num)
                                record_position=j;
                        }
                        temp=emp[i];
                        emp[i]=emp[record_position];
                        emp[record_position]=temp;
                    }
                    break;

                case 2:
                    for(i=0;i<*people_num-1;i++)
                    {
                        record_position=i;
                        for(j=i+1;j<*people_num;j++)
                        {
                            if(emp[j].num>emp[record_position].num)
                                record_position=j;
                        }
                        temp=emp[i];
                        emp[i]=emp[record_position];
                        emp[record_position]=temp;
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
            printf("已排序!\n");/**提示信息**/
            fclose(fp);/**关闭文件**/
            break;/**属于case 3**/
        default:
            printf("输入错误！\n");
    }//switch
}//search_sort
