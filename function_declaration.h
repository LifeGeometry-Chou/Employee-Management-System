#ifndef FUNCTION_DECLARATION_H_INCLUDED
#define FUNCTION_DECLARATION_H_INCLUDED

typedef struct
{
    /***ְ���š��������Ա����䡢ѧ�������ʡ�סַ���绰***/
    int num;
    char name[20];
    char sex[20];
    char age[20];
    char deg[20];
    double pay;
    char add[20];
    char phone[20];
}inf;/**����ṹ�岢����������Ϊinf**/
void menus();/**�˵�**/
void input(inf *emp,int *people_num,char file_name[]);/**¼��**/
void view(inf *emp,int *people_num);/**���**/
void search_sort(inf *emp,int *people_num,char file_name[]);/**��ѯ������**/
void del(inf *emp,int *people_num,char file_name[]);/**ɾ��**/
void mod(inf *emp,int *people_num,char file_name[]);/**�޸�**/

#endif // FUNCTION_DECLARATION_H_INCLUDED
