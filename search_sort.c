#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function_declaration.h"
void search_sort(inf *emp,int *people_num,char file_name[])/**��ѯ������**/
{
    FILE *fp;
    double wage1,wage2;/**wage1,wage2�ֱ�Ϊ���ʷ�Χ��������**/
    int select_num,record_position;
    int i,j;
    char input_degree[10];
    inf temp;/**�ṹ������������м����**/

    printf("1.�����ʲ�ѯ\n2.��ѧ����ѯ\n3.����������\n");
    printf("��ѡ���ܣ�");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("�����빤�ʷ�Χ(�ո������)��");
            scanf("%lf %lf",&wage1,&wage2);
            printf("--------------���ʷ�Χ��%.2f~%.2f��ְ����Ϣ--------------\n",wage1,wage2);
            for(i=0;i<*people_num;i++)
            {
                if((emp[i].pay>=wage1&&emp[i].pay<=wage2)||(emp[i].pay>=wage2&&emp[i].pay<=wage1))
                    printf("����:%d ����:%s �Ա�:%s ����:%s ѧ��:%s ����:%.2f סַ:%s �绰:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
            }
            break;

        case 2:
            printf("������ѧ����");
            scanf("%s",input_degree);
            printf("--------------����%sѧ����ְ����Ϣ--------------\n",input_degree);
            /**�ҳ���Ӧѧ����ְ���������Щְ������Ϣ**/
            for(i=0;i<*people_num;i++)
            {
                if(strcmp(emp[i].deg,input_degree)==0)
                    printf("����:%d ����:%s �Ա�:%s ����:%s ѧ��:%s ����:%.2f סַ:%s �绰:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
            }
            break;

        case 3:
            if((fp=fopen(file_name,"wb"))==NULL)
            {
                printf("error!\n");
                return;
            }
            printf("1.����\n2.����\n");
            printf("��ѡ�����򷽷���");
            scanf("%d",&select_num);
            switch(select_num)
            {
                /***ѡ������***/
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
                    printf("�������\n");
                    fclose(fp);/**�ر��ļ�**/
                    return;/**�������˵�����ѡ��**/
            }//switch

            /**д���ļ�**/
            for(i=0;i<*people_num;i++)
                fwrite(&emp[i],sizeof(inf),1,fp);
            printf("������!\n");/**��ʾ��Ϣ**/
            fclose(fp);/**�ر��ļ�**/
            break;/**����case 3**/
        default:
            printf("�������\n");
    }//switch
}//search_sort
