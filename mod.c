#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function_declaration.h"
void mod(inf *emp,int *people_num,char file_name[])/**�޸�**/
{
    FILE *fp;
    int i,select_num,input_num;
    char input_name[10];

    if((fp=fopen(file_name,"rb+"))==NULL)
    {
        printf("error!\n");
        return;
    }
    printf("1.��������ѯ�޸�\n2.�����Ų�ѯ�޸�\n");
    printf("��ѡ��");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("������ְ��������");
            scanf("%s",input_name);

            for(i=0; i<*people_num; i++)
            {
                if(strcmp(emp[i].name,input_name)==0)
                {
                    printf("--------------ְ����Ϣ--------------\n");
                    printf("����:%d ����:%s �Ա�:%s ����:%s ѧ��:%s ����:%.2f סַ:%s �绰:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
                    printf("1.ְ����\n2.����\n3.�Ա�\n4.����\n5.ѧ��\n6.����\n7.סַ\n8.�绰\n");
                    printf("������Ҫ�޸ĵ���Ŀ��");
                    scanf("%d",&select_num);
                    printf("����������Ϣ��");
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
                            printf("�������\n");
                            fclose(fp);/**�ر��ļ�**/
                            return;/**�������˵�����ѡ��**/
                    }//switch
                    break;//��ֹѭ��
                }//if
            }//for
            break;//case 1

        case 2:
            printf("������Ҫ�޸�ְ����Ϣ�Ĺ��ţ�");
            scanf("%d",&input_num);
            for(i=0; i<*people_num; i++)
            {
                if(emp[i].num==input_num)
                {
                    printf("--------------ְ����Ϣ--------------\n");
                    printf("����:%d ����:%s �Ա�:%s ����:%s ѧ��:%s ����:%.2f סַ:%s �绰:%s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,emp[i].pay,emp[i].add,emp[i].phone);
                    printf("1.ְ����\n2.����\n3.�Ա�\n4.����\n5.ѧ��\n6.����\n7.סַ\n8.�绰\n");
                    printf("������Ҫ�޸ĵ���Ŀ��");
                    scanf("%d",&select_num);
                    printf("����������Ϣ��");
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
                            printf("�������\n");
                            fclose(fp);/**�ر��ļ�**/
                            return;/**�������˵�����ѡ��**/
                    }//switch
                    break;//��ֹѭ��
                }//if
            }//for
            break;//case 2

        default:
            printf("�������\n");
            return;/**�������˵�����ѡ��**/
    }//switch

    /**д���ļ�**/
    for(i=0;i<*people_num;i++)
        fwrite(&emp[i],sizeof(inf),1,fp);
    printf("�޸ĳɹ���\n");/**��ʾ��Ϣ**/
    fclose(fp);/**�ر��ļ�**/
}//mod
