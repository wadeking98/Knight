/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../header/stack.h"
#include "../header/point.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
stack* newStack(){
    stack *s = malloc(sizeof(stack) + sizeof(point));
    s->size = 0;
    s->pop = pop;
    s->push = push;
    s->isEmpty = isEmpty;
    s->toString = toStringStack;
    return s;
}

/**
 * dynamically adds an item to the stack
 * @param self this stack
 * @param item item being added
 */
void push(stack *self, point item){
    self->size++;
    self = realloc(self, sizeof(stack) + self->size*sizeof(point));
    if(!self){
        printf("error: push realloc returned null");
    }
    self->items[self->size-1] = item;
}

/**
 * deletes an item from the stack
 * @param self this stack
 * @return the item being removed from the stack
 */
point pop(stack *self){
    point popItem = self->items[self->size-1];
    self->size--;
    self = realloc(self, sizeof(stack) + (self->size)*sizeof(point));
    return popItem;
}

/**printf("Stack: %s\n", st->toString(st));
 * 
 * @param self this stack
 * @return 1 if stack is empty
 */
int isEmpty(stack* self){
    return self->size == 0;
}

/**
 * 
 * @param self this stack
 * @return a string representing the stack
 */
char* toStringStack(stack *self){
    
    char* strSt = malloc(0);
    char* strPt;
    
    
    sprintf(strSt, "%s", "");
    int i;
    for(i = 0; i<self->size; i++){
        strPt = self->items[i].toString(&(self->items[i]));
        strSt = realloc(strSt, sizeof(strSt)+(sizeof(char)*5));
        sprintf(strSt, "%s%s", strSt, strPt);
    }
    
    printf("\n");
    return strSt;
}
