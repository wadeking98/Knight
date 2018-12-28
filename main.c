/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: wade
 *
 * Created on November 9, 2018, 3:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "point.h"
#include "stack.h"

/**
 * defines a point data structure
 */





/**
 * 
 * @param pt a given point of the board
 * @return 1 if the point is already marked on the board
 */
int inBounds(point pt){
    int x = pt.x;
    int y = pt.y;
    return (x < BOARD_DIM && x >= 0) && (y < BOARD_DIM && y >= 0);
}

/**
 * 
 * @param pt a given point on the board
 * @return 1 if the point is already marked on the board
 */
int isMarked(point pt){
    int x = pt.x;
    int y = pt.y;
    return board[x][y];
}




/**
 * 
 * @param dest the destination point of night move
 * @return true if tile is not marked and is in the bounds of the board
 */
int canMove(point dest){
    return !isMarked(dest) && inBounds(dest);
}

/**
 * The main logic of the program, calculates the nights tour around the chess board
 * @param pt the starting point of the tour
 * @param path the stack for the function to save the path to
 * @return 1 if path successfully found
 */
int knight(point pt, stack *path){
    board[pt.x][pt.y] = 1;
    numPt++;
    
    //base case board solved
    if(numPt == BOARD_DIM*BOARD_DIM){
        //printf("basecase Reached: %d\n", BOARD_DIM*BOARD_DIM);
        path->push(path, pt);
        return 1;
    }
    
    point topR = newPointxy(pt.x+1, pt.y+2);
    point topL = newPointxy(pt.x-1, pt.y+2);
    
    point rightT = newPointxy(pt.x+2, pt.y+1);
    point leftT = newPointxy(pt.x-2, pt.y+1);
    
    point rightB = newPointxy(pt.x+2, pt.y-1);
    point leftB = newPointxy(pt.x-2, pt.y-1);
    
    point bottomR = newPointxy(pt.x+1, pt.y-2);
    point bottomL = newPointxy(pt.x-1, pt.y-2);
    
    point pointArr[] = {topR, topL, rightT, leftT, rightB, leftB, bottomR, bottomL};
    
    int i;
    for(i = 0; i<8; i++){
        if(canMove(pointArr[i]) && knight(pointArr[i], path)){
            path->push(path, pt);
            return 1;
        }
    }
    //base case: cannot move from point and board is not completed
    board[pt.x][pt.y] = 0;
    numPt --;
    return 0;
    
}

/**
 * Used primarily for testing, prints each value on the board
 */
void printBoard(){
    int i,j;
    for(i = 0; i<BOARD_DIM; i++){
        for(j = 0; j<BOARD_DIM; j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

/**
 * The main interface of the program
 * @return 1
 */ 
int main() {
    
    
    
    printf("+-------------+\n");
    printf("|KNIGHT'S TOUR|\n");
    printf("+-------------+\n\n");
    
  
    
    int x;
    int y;
    int err = 0;
    
    do{
        if(err == 1){
            printf("Error, invalid x, or y coordinate, choose a value between 0 and 7\n");
        }
        
        printf("Enter the x-coordinate of the starting point of the knight on the board, (integer between 0 and 7): ");
        scanf("%d", &x);

        printf("Enter the y-coordinate of the starting point of the knight on the board, (integer between 0 and 7): ");
        scanf("%d", &y);
        
        err = 1;
    }while(x>=BOARD_DIM || y>=BOARD_DIM ||x<0 ||y<0);
    
    point startPt = newPointxy(x,y);
    stack *path = newStack();
    int status = knight(startPt, path);
    
    if(status == 1){
        printf("Success!\n");
        printf("Path: ");
        while(!path->isEmpty(path)){
            point pt = path->pop(path);
            printf("%s ", pt.toString(&pt));
        }
        printf("\n");
    }else{
        printf("Failure\n");
    }
    
    

    return (EXIT_SUCCESS);
}

