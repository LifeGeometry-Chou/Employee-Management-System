#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function_declaration.h"
void del(inf *emp,int *people_num,char file_name[])/**ɾ��**/
{
    FILE *fp;
    char name[20];
    int i,j,select_num;

    /**��wb+��ʽ���ļ�������ԭ������**/
    if((fp=fopen(file_name,"wb+"))==NULL)
    {
        printf("error!\n");
        return;
    }
    printf("1.������ɾ��\n2.������ɾ��\n");
    printf("��ѡ��");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("������Ҫɾ��ְ����Ϣ�Ĺ��ţ�");
            scanf("%d",&select_num);

            for(i=0;i<*people_num;i++)
            {
                if(emp[i].num==select_num)
                {
                    for(j=i;j<*people_num;j++)
                        emp[j]=emp[j+1];/**�ú������Ϣ����ǰ�����Ϣ**/
                    *people_num=*people_num-1;/**������һ,�޸�������ָ���ŵ�����**/
                }
            }
            break;
        case 2:
            printf("������Ҫɾ��ְ����Ϣ��������");
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
            printf("�������\n");
            fclose(fp);/**�ر��ļ�**/
            return;/**�������˵�����ѡ��**/
    }//switch
    /**д���ļ�**/
    for(i=0;i<*people_num;i++)
        fwrite(&emp[i],sizeof(inf),1,fp);
    printf("ɾ���ɹ���\n");/**��ʾ��Ϣ**/
    fclose(fp);/**�ر��ļ�**/
}//del
