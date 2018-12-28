/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../header/point.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * serves as a constructor for the point object
 * @return a new point
 */
point newPoint(){
    point pt = {0,0, toString};
    return pt;
}

/**
 * serves as a constructor for the point object
 * @param x the x-coordinate of the point
 * @param y the y-coordinate of the point
 * @return a new point
 */
point newPointxy(int x, int y){
    point pt = {x,y, toString};
    return pt;
}

/**
 * 
 * @param self
 * @return a string representation of the point 
 */
char* toString(point *self){
    char *strPt = (char*)malloc(sizeof(char)*10);
    
    
    sprintf(strPt, "%s", "(");
    sprintf(strPt, "%s%d", strPt, self->x);
    sprintf(strPt, "%s%s", strPt, ",");
    sprintf(strPt, "%s%d", strPt, self->y);
    sprintf(strPt, "%s%s", strPt, ")");
    
    
        
    return strPt;
}


