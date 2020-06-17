#ifndef FUNCTION_DECLARATION_H_INCLUDED
#define FUNCTION_DECLARATION_H_INCLUDED

typedef struct
{
    /***职工号、姓名、性别、年龄、学历、工资、住址、电话***/
    int num;
    char name[20];
    char sex[20];
    char age[20];
    char deg[20];
    double pay;
    char add[20];
    char phone[20];
}inf;/**定义结构体并命名新类型为inf**/
void menus();/**菜单**/
void input(inf *emp,int *people_num,char file_name[]);/**录入**/
void view(inf *emp,int *people_num);/**浏览**/
void search_sort(inf *emp,int *people_num,char file_name[]);/**查询和排序**/
void del(inf *emp,int *people_num,char file_name[]);/**删除**/
void mod(inf *emp,int *people_num,char file_name[]);/**修改**/

#endif // FUNCTION_DECLARATION_H_INCLUDED
