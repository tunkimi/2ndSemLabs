#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../data.h"
#include "../output/output.h"
#include "../re_builder/re_builder.h"

int str_equal(char *a, char *b){
    int i=0;
    while(1){
        if(a[i]=='\0'&&b[i]=='\0')return 1;
        if(a[i]!=b[i]) return 0;
        i++;
    }
}

void student_pc(info_pc *tmp)
{
    while(tmp)
    {   
        if(str_equal(tmp->proc.type, "Intel")&&tmp->video.typ==discrete) //выделил интельщиков с дикретной видеокартой (не знаю, что еще можно подобрать под критерий фирменные комплектующие, амд веьд тоже фильма  ¯\_(ツ)_/¯)
        {
	    info_pc* saver = tmp->next;
	    tmp->next = NULL;
	    output_pc(tmp);
	    tmp->next = saver; 
        }
        tmp = tmp->next;	
    }
}

