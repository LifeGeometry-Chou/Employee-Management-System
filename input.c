#include<stdio.h>
#include<stdlib.h>
#include"function_declaration.h"
void input(inf *emp,int *people_num,char file_name[])/**¼��**/
{
    FILE *fp;
    int i,select_num,add_num;

    printf("1.�½�ְ����Ϣ\n2.¼������ְ����Ϣ\n3.�����ְ����Ϣ\n");
    printf("��ѡ��");
    scanf("%d",&select_num);
    switch(select_num)
    {
        case 1:
            printf("�������½��ļ�����");
            scanf("%s",file_name);
            if((fp=fopen(file_name,"wb+"))==NULL)
            {
                printf("���ܴ�����ļ���\n");
                return;
            }

            printf("���������ְ��������");
            scanf("%d",&add_num);
            *people_num=add_num;/**����������*p**/

            /**������Ϣ��д���ļ�**/
            for(i=0;i<*people_num;i++)
            {
                printf("�밴ְ���š��������Ա����䡢ѧ�������ʡ�סַ���绰˳��������Ϣ���ո��������\n");
                scanf("%d %s %s %s %s %lf %s %s",&emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].deg,&emp[i].pay,emp[i].add,emp[i].phone);
                fwrite(&emp[i],sizeof(inf),1,fp);
            }

            printf("��Ϣ��¼�벢���棡\n");
            break;//case 1
        case 2:
            printf("�����������ļ�����");
            scanf("%s",file_name);
            if((fp=fopen(file_name,"rb+"))==NULL)
            {
                printf("���ܴ�����ļ���\n");
                return;
            }

            fseek(fp,0L,2);/**ʹ�ļ���������ļ�ĩβ**/
            *people_num=ftell(fp)/sizeof(inf);/**�����ļ������������������������ѽ������*p **/

            rewind(fp);/**ʹ�ļ���������ļ���ͷ**/
            for(i=0;i<*people_num;i++)
            {
                fread(&emp[i],sizeof(inf),1,fp);
            }

            printf("��Ϣ��¼�룡\n");
            break;//case 2
        case 3:
            printf("�����������ļ�����");
            scanf("%s",file_name);
            if((fp=fopen(file_name,"rb+"))==NULL)
            {
                printf("���ܴ�����ļ���\n");
                return;
            }

            fseek(fp,0L,2);/**ʹ�ļ���������ļ�ĩβ**/
            *people_num=ftell(fp)/sizeof(inf);/**�����ļ������������������������ѽ������*p **/

            rewind(fp);/**ʹ�ļ���������ļ���ͷ**/
            for(i=0;i<*people_num;i++)
                fread(&emp[i],sizeof(inf),1,fp);

            *people_num=*people_num+1;/**�����Ϣ��������һ**/
            printf("����������ӵ�ְ����Ϣ(ְ���š��������Ա����䡢ѧ�������ʡ�סַ���绰˳��������Ϣ)\n");
            /**������Ϣ��д���ļ�**/
            scanf("%d %s %s %s %s %lf %s %s",&emp[*people_num-1].num,emp[*people_num-1].name,emp[*people_num-1].sex,emp[*people_num-1].age,emp[*people_num-1].deg,&emp[*people_num-1].pay,emp[*people_num-1].add,emp[*people_num-1].phone);

            fseek(fp,0L,2);/**ʹ�ļ���������ļ�ĩβ**/
            fwrite(&emp[*people_num-1],sizeof(inf),1,fp);

            rewind(fp);/**ʹ�ļ���ǻص��ļ���ͷ**/
            /**�ٴζ�ȡ�ļ����ڴ�**/
            for(i=0;i<*people_num;i++)
                fread(&emp[i],sizeof(inf),1,fp);

            printf("��Ϣ��¼�벢���棡\n");
            break;//case 3
        default:
            printf("�������\n");
            return;/**�������˵�����ѡ��**/
    }//switch
    fclose(fp);/**�ر��ļ�**/
}//input
