#include <stdio.h>
#include <stdlib.h>
#define list struct data
#define lenthRefresh lenth=listLenth(barrier, barrier)


enum color {
    RED,
    BLUE,
    GREEN,
    BLACK,
    WHITE,
    BROWN,
    YELLOW
};

list{
    enum color thiscolor;
    list *next, *prev;
};

int menu(){
    static int a;
    printf("Выберите вариант действия:\n1. Печать списка\n2. Вставка нового элемента в список\n3. Удаление элемента из списка\n4. Подсчет длины списка\n5. Переставить элементы в обратном порядке\n6. Удалить весь список\n7. Выйти из программы\n");
    scanf("%d", &a);
    return a;
}

void addElement(list *cur, int index){
    while (index!=1){
        cur=cur->next;
        index--;
    }
    list *new=malloc(sizeof(list));
    new->prev=cur;
    new->next=cur->next;
    cur->next->prev=new;
    cur->next=new;
    int a;
    printf("Выберите цвет:\n1.RED\n2.BLUE\n3.GREEN\n4.BLACK\n5.WHITE\n6.BROWN\n7.YELLOW\n"); 
    scanf("%d", &a);
    new->thiscolor=a-1;
}

int listLenth(list* cur, list* barrier){
    int a=0;
    while (1){
        if(cur->next==barrier) return a;
        else{
            cur=cur->next;
            a++;
        }
    }
}

void listPrint(list *cur, list *barrier){
    cur=cur->next;
    while (cur!=barrier){
        switch (cur->thiscolor){
            case 0:
                printf("RED ");
                break;
            case 1:
                printf("BLUE ");
                break;
            case 2:
                printf("GREEN ");
                break;
            case 3:
                printf("BLACK ");
                break;
            case 4:
                printf("WHITE ");
                break;
            case 5:
                printf("BROWN ");
                break;
            case 6:
                printf("YELLOW ");
                break;
        }
        cur=cur->next;
    }
    
}

void swapElements(list *left, list *right){
    left->prev->next=right;
    left->next->prev=right;
    right->prev->next=left;
    right->next->prev=left;
    list *temp;
    temp=left->prev;
    left->prev=right->prev;
    right->prev=temp;
    temp=left->next;
    left->next=right->next;
    right->next=temp;
}

void deleteElement(list *cur, int index){
    while (index!=0){
        index--;
        cur=cur->next;
    }
    cur->prev->next=cur->next;
    cur->next->prev=cur->prev;
    free(cur);
}

list* chooseNext(list *cur, int index){
    while (index!=0)
    {
        index--;
        cur=cur->next;
    }
    return cur;    
}

list* choosePrev(list *cur, int index){
    while (index!=0)
    {
        index--;
        cur=cur->prev;
    }
    return cur;    
}

int main(){
    list *barrier=malloc(sizeof(list));
    barrier->next=barrier->prev=barrier;
    barrier->thiscolor=-1;
    int a, lenth, choise, index;
    while(1)
    {
        a=menu();
        switch (a)
        {
            case 1:
            lenthRefresh;
            if(lenth!=0){
                printf("\n");
                listPrint(barrier,barrier);    
                printf("\n\n");
            }            
            else{
                printf("\nНо ведь... Вы ещё ничего не ввели \n\n");
            }
            break;

            case 2:
                lenthRefresh;
                printf("\nВедите индекс добавляемого элемента:\n");
                scanf("%d", &index);
                if(index==0){
                    printf("Пожалуйста, введите натураьлный индекс\n\n");
                    break;
                }
                if(index>lenth+1){
                    printf("Индекс не может превышать длину списка более, чем на 1, текущая длина списка: %d\n\n", lenth);
                    break;
                }
                addElement(barrier, index);
            break;

            case 3:
                lenthRefresh;
                if(lenth!=0){
                    printf("\nВедите индекс удаляемого элемента:\n");
                    scanf("%d", &index);
                    if(index==0){
                        printf("Пожалуйста, введите натураьлный индекс\n\n");
                        break;
                    }
                    if(index>lenth){
                        printf("Индекс не может быть больше длины списка, это ведь не циклический список. Вот Вам длина списка: %d\n\n", lenth);
                        break;
                    }
                    deleteElement(barrier, index);
                }
                else{
                    printf("\nНо ведь... Вы ещё ничего не ввели \n\n");
                }
            break;

            case 4:
                lenthRefresh;
                printf("\nДлина списка: %d\n\n", lenth);
            break;

            case 5:
                lenthRefresh;
                choise=(int)lenth/2;
                printf("%d", choise);
                for (index = 1; index < choise; index++)
                {
                    swapElements(chooseNext(barrier, index), choosePrev(barrier, index));
                }
                if(lenth%2){
                    swapElements(chooseNext(barrier, index), choosePrev(barrier, index));
                }else{
                    list *midleft=chooseNext(barrier, index), *midright=choosePrev(barrier, index);
                    midright->next->prev=midleft;
                    midleft->prev->next=midright;
                    midleft->next=midright->next;
                    midright->prev=midleft->prev;
                    midright->next=midleft;
                    midleft->prev=midright;
                }
                printf("\nСписок был перестроен в обратном порядке\n\n");
            break;

            case 6:
                while (barrier->next!=barrier){
                    deleteElement(barrier, 1);
                }
                printf("Список был удалён\n\n");
            break;

            case 7:
                printf("\nПрограмма завершена\n\n");
                return 0;
            default:
                printf("Повторите ввод\n");
            break;
        }
    }
}