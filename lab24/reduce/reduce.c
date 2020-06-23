#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "../data.h"
#include "reduce.h"
#include "../cleaner/cleaner.h"
#include "../builder/build.h"
void reduce(cell *tmp)
{
    cell *toClean=tmp;
   if ((tmp->type == 0) && (tmp->val.oper >= 'a') && (tmp->val.oper <= 'z') && (tmp->left)) {
       if((tmp->left->type == 0) && (tmp->left->val.oper == '*') && (tmp->left->right)){
            if((tmp->left->right->type == 0) && (tmp->left->right->val.oper == '(') && (tmp->left->right->right)){
                if(tmp->left->right->right->type == 0 && tmp->left->right->right->val.oper>='a' && tmp->left->right->right->val.oper<='z' && tmp->left->right->right->right){
                    if(tmp->left->right->right->right->type == 0 && tmp->left->right->right->right->val.oper == '-' && tmp->left->right->right->right->right){
                        if(tmp->left->right->right->right->right->type == 0 && tmp->left->right->right->right->right->val.oper>='a' && tmp->left->right->right->right->right->val.oper<='z' && tmp->left->right->right->right->right->right){
                            if(tmp->left->right->right->right->right->right->type == 0 && tmp->left->right->right->right->right->right->val.oper==')'){
                                cell *newtemp=malloc(sizeof(cell));
                                newtemp->type=0;
                                newtemp->val.oper='(';
                                newtemp->parent=tmp->parent;
                                newtemp->left=NULL;
                                newtemp->right=malloc(sizeof(cell));
                                newtemp->right->parent=newtemp;
                                newtemp->right->type=0;
                                newtemp->right->val.oper=tmp->val.oper;
                                newtemp->right->right=NULL;
                                newtemp->right->left=malloc(sizeof(cell));
                                newtemp->right->left->parent=newtemp->right;
                                newtemp->right->left->type=0;
                                newtemp->right->left->val.oper='*';
                                newtemp->right->left->left=NULL;
                                newtemp->right->left->right=malloc(sizeof(cell));
                                newtemp->right->left->right->parent=newtemp->right->left;
                                newtemp->right->left->right->type=0;
                                newtemp->right->left->right->val.oper=tmp->left->right->right->val.oper;
                                newtemp->right->left->right->left=NULL;
                                newtemp->right->left->right->right=malloc(sizeof(cell));
                                newtemp->right->left->right->right->parent=newtemp->right->left->right;
                                newtemp->right->left->right->right->type=0;
                                newtemp->right->left->right->right->val.oper=')';
                                newtemp->right->left->right->right->left=NULL;
                                newtemp->right->left->right->right->right=malloc(sizeof(cell));
                                newtemp->right->left->right->right->right->parent=newtemp->right->left->right->right;
                                newtemp->right->left->right->right->right->type=0;
                                newtemp->right->left->right->right->right->val.oper='-';
                                newtemp->right->left->right->right->right->left=NULL;
                                newtemp->right->left->right->right->right->right=malloc(sizeof(cell));
                                newtemp->right->left->right->right->right->right->parent=newtemp->right->left->right->right->right;
                                newtemp->_R->_L->_R->_R->_R->_R->type=0;
                                newtemp->_R->_L->_R->_R->_R->_R->val.oper='(';
                                newtemp->_R->_L->_R->_R->_R->_R->_L=NULL;
                                newtemp->_R->_L->_R->_R->_R->_R->_R=malloc(sizeof(cell));
                                newtemp->_R->_L->_R->_R->_R->_R->_R->parent=newtemp->_R->_L->_R->_R->_R->_R;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->type=0;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->val.oper='a';
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_R=NULL;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L=malloc(sizeof(cell));
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->parent=newtemp->_R->_L->_R->_R->_R->_R->_R;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->type=0;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->val.oper='*';
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_L=NULL;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R=malloc(sizeof(cell));
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->parent=newtemp->_R->_L->_R->_R->_R->_R->_R->_L;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->type=0;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->val.oper=tmp->left->right->right->right->right->val.oper;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_L=NULL;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_R=malloc(sizeof(cell));
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_R->parent=newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_R->type=0;
                                newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_R->val.oper=')';
                                if(tmp->_R){
                                    newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_R->_R=tmp->_R;
                                    tmp->_R->parent=newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_R;
                                }else{
                                    newtemp->_R->_L->_R->_R->_R->_R->_R->_L->_R->_R->_R=NULL;
                                }
                                if(tmp->parent){
                                    newtemp->parent=tmp->parent;
                                    newtemp->parent->_L?newtemp:NULL;
                                    newtemp->parent->_R?newtemp:NULL;
                                }
                                free(toClean->_L->_R->_R->_R->_R->_R);
                                free(toClean->_L->_R->_R->_R->_R);
                                free(toClean->_L->_R->_R->_R);
                                free(toClean->_L->_R->_R);
                                free(toClean->_L->_R);
                                free(toClean->_L);
                                free(toClean);
                                *tmp=*newtemp;
                            }
                        }
                    }
                }
            }
        }
    }else{
        if(tmp->right){
            reduce(tmp->right);
        }
    }
    return;
}