//
//  main.c
//  2_2_7
//
//  Created by Himanshu Ahuja on 01/05/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//
//Two Stacks in a sing
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

typedef struct {
    int items[STACKSIZE];
    int top, bottom;
}stacks;

void settop(stacks *ps)
{
    ps->top=-1;
    ps->bottom=STACKSIZE;
}


void push1(stacks *ps, int x)
{
    if((ps->top)-(ps->bottom) == -1)
    {
        printf("Overflow. Nothing was added.\n");
    }
    else{
        ps->items[++(ps->top)]=x;
        printf("Number Pushed in 1.\n");
        
    }
}

void push2(stacks *ps, int x)
{
    if((ps->top)-(ps->bottom) == -1)
    {
        printf("Overflow. Nothing was added.\n");
    }
    else{
        ps->items[--(ps->bottom)]=x;
        printf("Number Pushed in 2.\n");
    }
}


int pop1(stacks *ps)
{
    if(ps->top==-1){
        printf("Nothing to pop\n");
        return -1;
    }
    else{
        return (ps->items[ps->top--]);
    }
    
}

int pop2(stacks *ps)
{
    if(ps->bottom==STACKSIZE){
        printf("Nothing to pop\n");
        return -1;
    }
    else{
        return (ps->items[ps->bottom++]);
    }
}



int main(){
    stacks s;
    settop(&s);
    
    int choice, num;
    
    while(1){
        printf("Chose from the following:\n");
        printf("1. Push 1\n");
        printf("2. Push 2\n");
        printf("3. Pop 1\n");
        printf("4. Pop 2\n");
        printf("5. Exit\n");
        
        
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter the number to be pushed");
                scanf("%d", &num);
                push1(&s, num);
                break;
                
            case 2:
                printf("Enter the Number to be pushed");
                scanf("%d", &num);
                push2(&s, num);
                break;
            
            case 3:
                printf("Popped from 1: %d", pop1(&s));
                break;
            case 4:
                printf("Popped from 2: %d", pop2(&s));
                break;
            case 5:
                exit(0);
            default:
                printf("Try Again");
        }
        
    }
    
    return 0;
}



