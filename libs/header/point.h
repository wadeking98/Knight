/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   point.h
 * Author: wade
 *
 * Created on November 10, 2018, 9:23 PM
 */

#ifndef POINT_H
#define POINT_H

typedef struct point point;

struct point{
    int x;
    int y;
    char* (*toString)(point *);
};

char* toString(point *self);

point newPoint();

point newPointxy(int x, int y);




#endif /* POINT_H */

