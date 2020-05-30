#include <stdio.h>
#include <stdlib.h>
#define row struct data
#define dataLenth 100
#define THE_WAY_TO_FILE "input.txt"
#define printThis printTable(thisTable, thisHeight)
#define sortThis sortTable(thisTable, thisHeight)
#define ARRAY_SIZE 10 //максимальная высота таблицы


//ввод и печать таблицы робят
//сравнение ключей тоже работает, но можно еще проверить
//сорт,несорт, реверс не проверял
//надеюсь, структура правильная, ждемс ответа Саныча



enum empty{
    TABLE_IS_EMPTY,
    TABLE_IS_NOT_EMPTY
};

enum sorted{
    REVERS=-1,
    UNSORTED,
    SORTED
};

row{
    char charKey[4];
    int intKey;
    char data[100];
};


int menu(){
    int menu;
    printf("Выберите необходимое действие:\n0.Выйти из программы\n1.Считать таблицу из файла \"input.txt\"\n2.Отобразить таблицу в терминале(консоле)\n3.Удалить данные таблицы из памяти\n4.Выполнить сортировку\n");
    scanf("%d",&menu);
    return menu;
}

void readTable(row**table, int *height){
    FILE *stream=fopen(THE_WAY_TO_FILE, "r");
    char trash;
    int i;
    for(i=0;;i++){
        table[i]=malloc(sizeof(row));
        if(fscanf(stream,"%c", &(table[i]->charKey[0]))==EOF){
            if(feof(stream)==1){
                printf("\nЧтение файла окончено.");
                break;
            }
            else{
                printf("\nОшибка чтения из файла\n\n");
                break;
            }
        }
        if(i>=ARRAY_SIZE) break;
        fscanf(stream, "%c%c%c", &(table[i]->charKey[1]), &(table[i]->charKey[2]), &(table[i]->charKey[3]));
        fscanf(stream, "%d", &(table[i]->intKey));
        fscanf(stream,"%c", table[i]->data);
        fscanf(stream, "%[^\n]s", table[i]->data);
        fscanf(stream,"%c", &trash);    //scanf хочет скушать перенос строки, этот треш его съедает, чтоб он не попадал в данные
    }    
    *height=i;
    fclose(stream);
}

void printTable(row** table, int height){
    int j;
    for(int i=0; i<height; i++){
        j=0;
        printf("%d)\t", i+1);
        printf("%c%c%c%c\t", table[i]->charKey[0], table[i]->charKey[1],table[i]->charKey[2],table[i]->charKey[3]);
        printf("%d\t", table[i]->intKey);
        while (table[i]->data[j]!='\0')
        {
            printf("%c", table[i]->data[j]);
            j++;
        }
        printf("\n");
    }
}

int isItLarger(row*firstRow, row*secondRow){
    for(int i=0;i<4;i++){
        if(firstRow->charKey[i]<secondRow->charKey[i]){
            return 0;
        }
        else if(firstRow->charKey[i]>secondRow->charKey[i]){
            return 1;
        }
    }
    if(firstRow->intKey>secondRow->intKey){
        return 1;
    }
    else{
        return 0;
    }
}

enum sorted isItSorted(row**table, int height){
    if(height>1){
        if(isItLarger(table[0], table[1])){
            for(int i=1;i<height-1;i++){
                if(isItLarger(table[i+1], table[i])){
                    return UNSORTED;
                }
            }
            return REVERS;
        }
        else{
            for(int i=1;i<height-1;i++){
                if(isItLarger(table[i], table[i+1])){
                    return UNSORTED;
                }
            }
            return SORTED;
        }
    }else{
        return SORTED;
    }
}

void mergeRebuild(row **table, int lt, int rt){
    int i=lt, mid=lt+(rt-lt)/2, j=mid, k=0;
    


    row**TempTable=malloc((rt-lt)*sizeof(row*));
    while (i<mid&&j<rt){
        if(isItLarger(table[i],table[j])){
            TempTable[k]=table[j];
            j++;
        }else{
            TempTable[k]=table[i];
            i++;
        }
        k++;
    }
    while (i<mid){
        TempTable[k]=table[i];
        i++;
        k++;
    }
    while (j<rt){
        TempTable[k]=table[j];
        j++;
        k++;
    }
    for(i=0;i<k;i++){
        table[lt+i]=TempTable[i];
    }
    free(TempTable);
    return;
}

void mergeSort( row** table, int lt, int rt){
    if(rt-lt==1){
        return;
    }
    mergeSort(table, lt, lt+(rt-lt)/2);
    mergeSort(table, lt+(rt-lt)/2, rt);
    mergeRebuild(table, lt, rt);
}

int main(){
    enum empty isEmpty=TABLE_IS_EMPTY;
    enum sorted isSorted=UNSORTED;
    row* thisTable[ARRAY_SIZE];
    int thisHeight, i;
    while (1)
    {
        switch (menu())
        {
        case 0:
            printf("\nПрограмма завершена\n\n");
            exit(0);
        break;
        
        case 1:                                                 //Считать таблицу из файла
            readTable(thisTable, &thisHeight);
            printf("\nТаблица считана\n\n");
            isEmpty=TABLE_IS_NOT_EMPTY;
            isSorted=isItSorted(thisTable, thisHeight);
        break;

        case 2:
            if(isEmpty!=TABLE_IS_EMPTY){
                printf("\nИсходная таблица:\n\n");
                printThis;
            }
            else{
                printf("\nТаблица не была введена в программу или была очищена\n\n");
            }
        break;

        case 3:
            for(i=0;i<thisHeight;i++){
                free(thisTable[i]);
                isEmpty=TABLE_IS_EMPTY;`
            }
            printf("\nТаблица была удалена из памяти\n\n");
        break;

        case 4:
            if(isEmpty!=TABLE_IS_EMPTY){
                if(isSorted<1){
                    if(isSorted){
                        printf("\nТаблица была отсортирована в обратном порядке");
                    }
                    else{
                        printf("\nТаблица не отсортирована");
                    }
                    printf("\nТекущая таблица:\n");
                    printThis;
                    printf("\nТаблица после сортировки:\n");
                    mergeSort(thisTable, 0, thisHeight);
                    printThis;
                    printf("\n");
                    isSorted=1;
                }
                else{
                    printf("\nТекущая таблица:\n");
                    printThis;
                    printf("\nТаблица уже отсортирована\n\n");
                }
            }
            else{
                printf("\nТаблица не была введена в программу или была очищена\n\n");
            }
        break;

        default:
            break;
        }
    }
    
}
