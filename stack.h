/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: wade
 *
 * Created on November 11, 2018, 12:47 PM
 */
#include "point.h"
#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

struct stack{
    int size;
    void (*push)(stack*, point);
    point (*pop)(stack*);
    int (*isEmpty)(stack*);
    char* (*toString)(stack*);
    point items[];
};

point pop(stack *self);

void push(stack *self, point item);

int isEmpty(stack *self);

char* toStringStack(stack *self);

stack* newStack();

#endif /* STACK_H */

