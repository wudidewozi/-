#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct commodity{
    short int id;
    char name[20];
    int number;
    float price;
    struct commodity *next;
}commodity;
commodity *head;
// 初始化商品链表
void init_commodity();

// 添加商品，用户可以输入商品信息，包括名称、数量、价格，将商品添加到链表中
void add_commodity();

// 显示所有商品信息，以表格形式展示商品的序号、名称、数量、价格
void print_commodity();

// 删除商品，根据用户输入的序号删除相应商品
void delete_commodity();

// 修改商品信息，用户可以选择修改商品的名称、数量或价格
void modify_commodity();

// 查询商品，用户输入商品序号，显示该商品的详细信息
void query_commodity();

// 菜单函数，提供用户选择不同的商品管理操作
void menu();

// 释放商品链表的内存，确保程序结束时没有内存泄漏
void free_commodity();
// 添加初始商品
void create_commodity(char name[], int number, float price);

void init_commodity(){
    head = (commodity *)malloc(sizeof(commodity));
    head->next = NULL;
}
void create_commodity(char name[], int number, float price){
    commodity *p, *q;
    int i = 1;

    p = (commodity *)malloc(sizeof(commodity));
    strcpy(p->name, name);
    p->number = number;
    p->price = price;
    p->next = NULL;

    if (head->next == NULL){
        p->id = 1;
        head->next = p;
    }
    else{
        q = head;
        while (q->next != NULL){
            i++;
            q = q->next;
        }
        p->id = i;
        q->next = p;
    }
}
void add_commodity(){
    int i;
    commodity *p,*q;
    while(1){
        i=1;
        p=(commodity *)malloc(sizeof(commodity));
        printf("请输入商品名:");
        scanf("%s",p->name);
        printf("请输入商品数量:");
        scanf("%d",&p->number);
        printf("请输入商品价格:");
        scanf("%f",&p->price);
        p->next=NULL;
        if(head->next==NULL){
            p->id=1;
            head->next=p;
        }
        else{
            q=head;
            while(q->next!=NULL){
               i++;
                q=q->next;
            }
           p->id=i;
          q->next=p;
        }
        printf("商品添加成功\n");
        printf("如要继续使用请输入任意字符,如要退出请按0:");
        scanf("%d",&i);
        if(i==0){
            break;
        }
    }
    getchar();
    system("cls");
}
void print_commodity(){
    commodity *p=head->next;
    printf("序号    商品名    数量    价格\n");
    while(p!=NULL){
        printf("%-8d%-10s%-8d%-8.2f\n",p->id,p->name,p->number,p->price);
        p=p->next;
    }
    if(head->next==NULL)printf("暂无商品\n");
    getchar();
    getchar();
    system("cls");
}
void delete_commodity(){
    int i;
    commodity *p,*q;
    printf("请输入要删除的序号:");
    scanf("%d",&i);
    p=head->next;
    q=head;
    while(p!=NULL){
        if(p->id==i){
            q->next=p->next;
            free(p);
            break;
        }
        q=q->next;
        p=p->next;
    }
    if(p==NULL)printf("该序号不存在\n");
    else printf("删除成功");
    getchar();
    getchar();
    system("cls");
}
void modify_commodity(){
    int i,j;
    commodity *p;
    printf("请输入要修改的序号:");
    scanf("%d",&i);
    p=head->next;
    while(p!=NULL){
        if(p->id==i){
            break;
        }
        p=p->next;
    }
    if(p==NULL){
        printf("该序号不存在\n");
        getchar();
        getchar();
        system("cls");
        return;
    }
    printf("更改商品名请输入1\n");
    printf("更改数量请输入2\n");
    printf("更改价格请输入3\n");
    printf("请输入要更改的选项:");
    scanf("%d",&j);
    switch(j){
        case 1:
            printf("请输入新的商品名:");
            scanf("%s",p->name);
            break;
        case 2:
            printf("请输入新的数量:");
            scanf("%d",&p->number);
            break;
        case 3:
            printf("请输入新的价格:");
            scanf("%f",&p->price);
            break;
        default:
            printf("输入错误\n");
            break;
    }
    printf("修改成功");
    getchar();
    getchar();
    system("cls");
}
void query_commodity(){
    int i;
    commodity *p;
    printf("请输入要查询的序号:");
    scanf("%d",&i);
    p=head->next;
    while(p!=NULL){
        if(p->id==i){
            break;
        }
        p=p->next;
    }
    if(p==NULL){
        printf("该序号不存在\n");
        getchar();
        getchar();
        system("cls");
        return;
    }
    printf("序号    商品名    数量    价格\n");
    printf("%-8d%-10s%-8d%-8.2f\n",p->id,p->name,p->number,p->price);
    getchar();
    getchar();
    system("cls");
}
void menu(){
    int i;
    while(1){
        printf("------欢迎使用简易商品管理系统------\n");
        printf("|1.添加商品                       |\n");
        printf("|2.删除商品                       |\n");
        printf("|3.修改商品                       |\n");
        printf("|4.查询商品                       |\n");
        printf("|5.显示所有商品                   |\n");
        printf("|6.退出                           |\n");
        printf("-----------------------------------\n");
        printf("请选择：");
        scanf("%d",&i);
        switch(i){
            case 1:add_commodity();
                break;
            case 2:delete_commodity();
                break;
            case 3:modify_commodity();
                break;
            case 4:query_commodity();
                break;
            case 5:print_commodity();
                break;
            case 6:return;
                break;
            default:
                printf("输入错误\n");
                break;
        }
    }
}
void free_commodity(){
    commodity *p,*q;
    p=head->next;
    while(p!=NULL){
        q=p;
        p=p->next;
        free(q);
    }
    free(head);
}
int main(){
    init_commodity();
    // 添加初始商品
    create_commodity("可乐", 20, 3.5);
    create_commodity("零食", 15, 8.75);
    create_commodity("牛奶", 12, 5.25);
    create_commodity("面包", 30, 2.0);
    create_commodity("巧克力", 18, 4.5);
    create_commodity("果汁", 25, 4.0);
    create_commodity("水果", 10, 12.99);
    create_commodity("咖啡", 8, 6.75);
    create_commodity("饼干", 22, 3.25);
    create_commodity("糖果", 17, 1.99);
    menu();
    free_commodity();
    return 0;
}