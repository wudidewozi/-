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
// ��ʼ����Ʒ����
void init_commodity();

// �����Ʒ���û�����������Ʒ��Ϣ���������ơ��������۸񣬽���Ʒ��ӵ�������
void add_commodity();

// ��ʾ������Ʒ��Ϣ���Ա����ʽչʾ��Ʒ����š����ơ��������۸�
void print_commodity();

// ɾ����Ʒ�������û���������ɾ����Ӧ��Ʒ
void delete_commodity();

// �޸���Ʒ��Ϣ���û�����ѡ���޸���Ʒ�����ơ�������۸�
void modify_commodity();

// ��ѯ��Ʒ���û�������Ʒ��ţ���ʾ����Ʒ����ϸ��Ϣ
void query_commodity();

// �˵��������ṩ�û�ѡ��ͬ����Ʒ�������
void menu();

// �ͷ���Ʒ������ڴ棬ȷ���������ʱû���ڴ�й©
void free_commodity();
// ��ӳ�ʼ��Ʒ
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
        printf("��������Ʒ��:");
        scanf("%s",p->name);
        printf("��������Ʒ����:");
        scanf("%d",&p->number);
        printf("��������Ʒ�۸�:");
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
        printf("��Ʒ��ӳɹ�\n");
        printf("��Ҫ����ʹ�������������ַ�,��Ҫ�˳��밴0:");
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
    printf("���    ��Ʒ��    ����    �۸�\n");
    while(p!=NULL){
        printf("%-8d%-10s%-8d%-8.2f\n",p->id,p->name,p->number,p->price);
        p=p->next;
    }
    if(head->next==NULL)printf("������Ʒ\n");
    getchar();
    getchar();
    system("cls");
}
void delete_commodity(){
    int i;
    commodity *p,*q;
    printf("������Ҫɾ�������:");
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
    if(p==NULL)printf("����Ų�����\n");
    else printf("ɾ���ɹ�");
    getchar();
    getchar();
    system("cls");
}
void modify_commodity(){
    int i,j;
    commodity *p;
    printf("������Ҫ�޸ĵ����:");
    scanf("%d",&i);
    p=head->next;
    while(p!=NULL){
        if(p->id==i){
            break;
        }
        p=p->next;
    }
    if(p==NULL){
        printf("����Ų�����\n");
        getchar();
        getchar();
        system("cls");
        return;
    }
    printf("������Ʒ��������1\n");
    printf("��������������2\n");
    printf("���ļ۸�������3\n");
    printf("������Ҫ���ĵ�ѡ��:");
    scanf("%d",&j);
    switch(j){
        case 1:
            printf("�������µ���Ʒ��:");
            scanf("%s",p->name);
            break;
        case 2:
            printf("�������µ�����:");
            scanf("%d",&p->number);
            break;
        case 3:
            printf("�������µļ۸�:");
            scanf("%f",&p->price);
            break;
        default:
            printf("�������\n");
            break;
    }
    printf("�޸ĳɹ�");
    getchar();
    getchar();
    system("cls");
}
void query_commodity(){
    int i;
    commodity *p;
    printf("������Ҫ��ѯ�����:");
    scanf("%d",&i);
    p=head->next;
    while(p!=NULL){
        if(p->id==i){
            break;
        }
        p=p->next;
    }
    if(p==NULL){
        printf("����Ų�����\n");
        getchar();
        getchar();
        system("cls");
        return;
    }
    printf("���    ��Ʒ��    ����    �۸�\n");
    printf("%-8d%-10s%-8d%-8.2f\n",p->id,p->name,p->number,p->price);
    getchar();
    getchar();
    system("cls");
}
void menu(){
    int i;
    while(1){
        printf("------��ӭʹ�ü�����Ʒ����ϵͳ------\n");
        printf("|1.�����Ʒ                       |\n");
        printf("|2.ɾ����Ʒ                       |\n");
        printf("|3.�޸���Ʒ                       |\n");
        printf("|4.��ѯ��Ʒ                       |\n");
        printf("|5.��ʾ������Ʒ                   |\n");
        printf("|6.�˳�                           |\n");
        printf("-----------------------------------\n");
        printf("��ѡ��");
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
                printf("�������\n");
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
    // ��ӳ�ʼ��Ʒ
    create_commodity("����", 20, 3.5);
    create_commodity("��ʳ", 15, 8.75);
    create_commodity("ţ��", 12, 5.25);
    create_commodity("���", 30, 2.0);
    create_commodity("�ɿ���", 18, 4.5);
    create_commodity("��֭", 25, 4.0);
    create_commodity("ˮ��", 10, 12.99);
    create_commodity("����", 8, 6.75);
    create_commodity("����", 22, 3.25);
    create_commodity("�ǹ�", 17, 1.99);
    menu();
    free_commodity();
    return 0;
}