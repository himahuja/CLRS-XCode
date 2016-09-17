//
//  main.c
//  linked-list-polynomial
//
//  Created by Himanshu Ahuja on 9/16/16.
//  Copyright © 2016 Himanshu Ahuja. All rights reserved.
//

/*Considering that the polynomial received as input is ordered that is the exponent of the previous entered term is smaller than the term currently being entered*/
/*|||||||||||||||HIMANSHU AHUJA|||||||DTU/2K15/COE/063||||||||||||||||*/
#include <stdio.h>
#include <stdlib.h>


typedef struct term{
    int coeff;
    int exp;
    struct term* next;
}term;

void getPoly(term* head){
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    for(i = 0; i < num-1; i++){
        printf("Enter the Coefficient and Exponent: ");
        scanf("%d%d", &(head->coeff), &(head->exp));
        head->next = (term*)malloc(sizeof(term));
        head = head->next;
        head->next = NULL;
    }
    printf("Enter the Coefficient and Exponent: ");
    scanf("%d%d", &(head->coeff), &(head->exp));
    head->next = NULL;
}

void disPoly(term* front){
    while(front->next != NULL){
        printf("(%d)x^%d + ", front->coeff, front->exp);
        front = front->next;
    }
    
    printf("(%d)x^%d\n", front->coeff, front->exp);
    
}



term* addPoly(term* p1, term* p2){
    term* result = (term*)malloc(sizeof(term));
    result->coeff=0; result->exp=0; result->next = NULL;
    
    term* temp = result;
    
    while(p1 && p2){
        if(p1->exp > p2->exp){
            result->exp = p1->exp;
            result->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if(p2->exp > p1->exp){
            result->exp = p2->exp;
            result->coeff = p2->coeff;
            p2 = p2->next;
        }
        else
        {
            result->exp = p1->exp;
            result->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if(p1 || p2){
            result->next = (term*)malloc(sizeof(term));
            result = result->next;
            result->next = NULL;
        }
    }
    
    while(p1 || p2){
        if(p1){
            result->coeff = p1->coeff;
            result->exp = p1->exp;
            p1 = p1->next;
        }
        if(p2){
            result->coeff = p2->coeff;
            result->exp = p2->exp;
            p2 = p2->next;
        }
        
        if(p1 || p2){
            result->next = (term*)malloc(sizeof(term));
            result = result->next;
            result ->next = NULL;
        }
    }
    return temp;
}

term* multiplyPoly(term* p1, term* p2){
    
    term* tempP2 = p2;
    term* ptr = (term*)malloc(sizeof(term));
    ptr->next = NULL;
    term* result = (term*)malloc(sizeof(term));
    result->next = NULL; result->coeff = 0; result->exp = 0;
    term* tempPtr = ptr;
    while(p1)
    {
        while(tempP2){
            ptr->coeff = p1->coeff * tempP2->coeff;
            ptr->exp = p1->exp + tempP2->exp;
            tempP2 = tempP2->next;
            
            if(tempP2){
                ptr->next = (term*)malloc(sizeof(term));
                ptr = ptr->next;
                ptr->next = NULL;
            }
        }
        
        result = addPoly(result, tempPtr);
        tempP2 = p2;
        ptr = tempPtr;
        p1 = p1 -> next;
    }
    
    ptr = tempPtr;
    
    while(ptr){
        tempPtr = ptr;
        ptr = ptr -> next;
        free(tempPtr);
    }
    
    return result;
}



int main(int argc, const char * argv[]) {
    
    term* poly1 = (term*)malloc(sizeof(term));
    term* poly2 = (term*)malloc(sizeof(term));
    
    printf("Enter the first polynomial: \n");
    getPoly(poly1);
    disPoly(poly1);
    printf("Enter the second polynomial: \n");
    getPoly(poly2);
    disPoly(poly2);
    
    printf("Sum of the two polynomials is: ");
    disPoly(addPoly(poly1, poly2));
    printf("Product of the two polynomials is: ");
    disPoly(multiplyPoly(poly1, poly2));
    
    return 0;
}
