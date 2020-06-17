#include <stdio.h>
#include <stdlib.h>
#define __NAME__ "input.txt"
#define vector struct Vector
#define findWeith find_weith(thisWeith)

struct Vector{
    vector *next;
    int _1st, _2nd;
};

// struct elem{
//     int data;
//     struct elem *nextelem;
// };

// struct row{
//     struct elem *elems;
//     struct row *nextrow
// }


vector* read_matrix( int weith, int heith){
    FILE* stream;
    if((stream = fopen(__NAME__, "r")) == NULL){        
        printf("Не удалось открыть файл");
        exit(1);
    }
    int i, j, *check=(int*)calloc(heith, sizeof(int)), **matr;
    matr=(int**)malloc(sizeof(int*)*heith);
    for(i=0;i<heith;i++){
        matr[i]=(int*)malloc(sizeof(int)*weith);
    }
    vector *this=(vector*)malloc(sizeof(vector)), *rat=this;
    for(i=0;i<heith;i++){
        for(j=0;j<weith;j++){
            fscanf(stream, "%d", &matr[i][j]);
            if(matr[i][j]&&!check[i]){
                check[i]=1;
                this->_1st=0;
                this->_2nd=i+1;
                this->next=malloc(sizeof(vector));
        printf("%d - %d\n", this->_1st, this->_2nd);
                this=this->next;
            }
            if(matr[i][j]){
                this->_1st=j+1;
                this->_2nd=matr[i][j];
                this->next=malloc(sizeof(vector));
        printf("%d - %d\n", this->_1st, this->_2nd);
                this=this->next;
            }
        }
    }
    this=NULL;
    return rat;
}


void find_weith(int *weith){
    FILE* stream;
    if((stream = fopen(__NAME__, "r")) == NULL){        
        printf("Не удалось открыть файл");
        return;
    }
    char sym;
    *weith=1;
    int afterspace;
    fscanf(stream,"%c", &sym);
    while(sym!='\n'){
        if(sym==' '){
            if(afterspace){
                continue;
            }
            (*weith)++;
            afterspace=1;
        }else{
            afterspace=0;
        }
        fscanf(stream, "%c", &sym);
    }
}

void find_heigth(int *heigth, int weith){
    FILE* stream;
    if((stream = fopen(__NAME__, "r")) == NULL){        
        printf("Не удалось открыть файл");
        return;
    }
    int sym;
    *heigth=1;
    while(fscanf(stream, "%d", &sym)!=EOF){
        (*heigth)++;
    }
    *heigth/=weith;
}

int menu(){
    int a;
    printf("Выберите необходимое действие:\n\t0. Выйти из программы\n\t1. Ввеstи матрицу из таблицы\n\t2. Печать матрицы в двух видах размещения\n\t3. Вычислить матрочлен\n");
    scanf("%d", &a);
    return a;
}

void print_vector(vector *this){
    while(this->next!=NULL){
        printf("%d - %d\n", this->_1st, this->_2nd);
        this=this->next;
    }
    printf("\n\n");
}

void print_matrix(vector *this, int weith){
    int prev_i=weith;
    while(this->next!=NULL){
        if(!this->_1st){
            if(this->_2nd){
                while(prev_i!=weith){
                    prev_i++;
                    printf("0\t");
                }
                printf("\n");
            }
            prev_i=0;
        }
        else{
            while(prev_i+1!=this->_1st){
                printf("0\t");
                prev_i++;
            }
            printf("%d\t", this->_2nd);
            prev_i++;
        }
        this=this->next;
    }
    while(prev_i!=weith){
        prev_i++;
        printf("0\t");
    }
    printf("\n");
}
void matrochlen(vector *root, int a, int b, int heigth){
    vector *temp=root, *new;
    int is_row=999, *check=(int*)calloc(sizeof(int), heigth), oneskip=0, start=0;
    while(temp->next!=NULL){
        if(temp->_1st){
            temp->_2nd*=a;
        }
        temp=temp->next;
    }
    temp=root;
    while(root->next!=NULL){
        if(!root->_1st){
            if(check[is_row-1]==0&&start){
                new=(vector*)malloc(sizeof(vector));
                new->next=temp->next;
                new->_1st=is_row;
                new->_2nd=b;
                temp->next=new;
                check[is_row-1]=1;
            }
            is_row=root->_2nd;
            start=1;
        }
        else{
            if(is_row==root->_1st&&!check[is_row-1]){
                root->_2nd+=b;
                check[is_row-1]=1;
            }
            else if(root->_1st>is_row&&!check[is_row-1]){
                new=(vector*)malloc(sizeof(vector));
                new->next=temp->next;
                new->_1st=is_row;
                new->_2nd=b;
                temp->next=new;
                check[is_row-1]=1;
            }
        }
        temp=root;
        root=root->next;
    }
    if(check[is_row-1]==0){
                new=(vector*)malloc(sizeof(vector));
                new->next=temp->next;
                new->_1st=is_row;
                new->_2nd=b;
                temp->next=new;
    }
}

int main(){
    vector *root=NULL;
    int heith, weith, a, b;
    while(1){
        switch(menu()){
            case 0:
                exit(1);
            break;
            case 1:
                find_weith(&weith);
                find_heigth(&heith, weith);
                root=read_matrix(weith, heith);        
            break;
            case 2:
                print_vector(root);
                print_matrix(root, weith);
            break;
            case 3:
                printf("\n Найдем матрочлен a*M+b*E, где M - введенная матрица, а Е - единичкая матрица\nВведите коэффициент a: ");
                scanf("%d", &a);
                printf("Введите коэффициент b:");
                scanf("%d", &b);
                matrochlen(root, a, b, heith);
            break;
        }
    }
}