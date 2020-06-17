#include<stdio.h>
#include<stdlib.h>
#include"function_declaration.h"
void input(inf *emp,int *people_num,char file_name[])/**录入**/
{
    FILE *fp;
    int i,select_num,add_num;

    printf("1.新建职工信息\n2.录入已有职工信息\n3.添加新职工信息\n");
    printf("请选择：");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("请输入新建文件名：");
            scanf("%s",file_name);
            if((fp=fopen(file_name,"wb+"))==NULL)
            {
                printf("不能打开这个文件！\n");
                return;
            }

            printf("请输入添加职工人数：");
            scanf("%d",&add_num);
            *people_num=add_num;/**将人数赋给*p**/

            /**输入信息，写入文件**/
            for(i=0;i<*people_num;i++)
            {
                printf("请按职工号、姓名、性别、年龄、学历、工资、住址、电话顺序输入信息（空格键隔开）\n");
                scanf("%d %s %s %s %s %lf %s %s",&emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,&emp[i].pay,emp[i].add,emp[i].phone);
                fwrite(&emp[i],sizeof(inf),1,fp);
            }

            printf("信息已录入并保存！\n");
            break;//case 1
        case 2:
            printf("请输入已有文件名：");
            scanf("%s",file_name);
            if((fp=fopen(file_name,"rb+"))==NULL)
            {
                printf("不能打开这个文件！\n");
                return;
            }

            fseek(fp,0L,2);/**使文件标记移至文件末尾**/
            *people_num=ftell(fp)/sizeof(inf);/**计算文件数据组数（即人数），并把结果赋给*p **/

            rewind(fp);/**使文件标记移至文件开头**/
            for(i=0;i<*people_num;i++)
            {
                fread(&emp[i],sizeof(inf),1,fp);
            }

            printf("信息已录入！\n");
            break;//case 2
        case 3:
            printf("请输入已有文件名：");
            scanf("%s",file_name);
            if((fp=fopen(file_name,"rb+"))==NULL)
            {
                printf("不能打开这个文件！\n");
                return;
            }

            fseek(fp,0L,2);/**使文件标记移至文件末尾**/
            *people_num=ftell(fp)/sizeof(inf);/**计算文件数据组数（即人数），并把结果赋给*p **/

            rewind(fp);/**使文件标记移至文件开头**/
            for(i=0;i<*people_num;i++)
                fread(&emp[i],sizeof(inf),1,fp);

            *people_num=*people_num+1;/**添加信息，人数加一**/
            printf("请输入新添加的职工信息(职工号、姓名、性别、年龄、学历、工资、住址、电话顺序输入信息)\n");
            /**输入信息，写入文件**/
            scanf("%d %s %s %s %s %lf %s %s",&emp[*people_num-1].num,emp[*people_num-1].name,emp[*people_num-1].sex,emp[*people_num-1].age,emp[*people_num-1].deg,&emp[*people_num-1].pay,emp[*people_num-1].add,emp[*people_num-1].phone);

            fseek(fp,0L,2);/**使文件标记移至文件末尾**/
            fwrite(&emp[*people_num-1],sizeof(inf),1,fp);

            rewind(fp);/**使文件标记回到文件开头**/
            /**再次读取文件到内存**/
            for(i=0;i<*people_num;i++)
                fread(&emp[i],sizeof(inf),1,fp);

            printf("信息已录入并保存！\n");
            break;//case 3
        default:
            printf("输入错误！\n");
            return;/**返回至菜单功能选择**/
    }//switch
    fclose(fp);/**关闭文件**/
}//input
