//
// Created by rosawan on 04/03/2021.
//
#include <iostream>
#include <cstring>
#include <cmath>
#include "Canvas.h"

Canvas::Canvas(int width, int height): width(width), height(height) {
    this->canvasElements = new char * [height];

    for ( int i = 0; i < height; i++ ) {
        this->canvasElements[i] = new char[width];
        std::memset ( this->canvasElements[i], ' ', width);
    }
}

Canvas::~Canvas() {
    for(int i = 0; i < this ->height; i++)
        delete [] this->canvasElements[i];
    delete [] this -> canvasElements;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {

    for(int deg = 0; deg < 360; deg ++) {
        float rad = deg * 180 / M_PI;


        static auto closestInt = [] (float value) -> int {
            int lowerBound = (int) value;
            int upperBound = (int) value + 1;

            if (value - (float) lowerBound < (float) upperBound - value)
                return lowerBound;
            return upperBound;
        };

        int xNew = closestInt((float) x + cosf(rad) * (float) ray);
        int yNew = closestInt((float) y + sinf(rad) * (float) ray);

        this->canvasElements[yNew][xNew] = ch;
    }

}

void Canvas::FillCircle(int x, int y, int ray, char ch) {

   for(int i = -ray; i < ray; i++){
       for(int j = - ray; j < ray; j++){
           if(i*i + j*j < ray * ray)
               this->SetPoint(x + j, y + i, ch);
       }
   }
}

/*
 *  A_______B
 *  |       |
 *  D_______C
 */


void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    this->DrawLine(left, top, right, top, ch);          //A -> B
    this->DrawLine(right, top, right, bottom, ch);      //B -> C
    this->DrawLine(left, bottom, right, bottom, ch);    //C -> D
    this->DrawLine(left, top, left, bottom, ch);        //A -> D
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    while(top != bottom - 1){
        this->DrawLine(left+1, top+1, right-1, top+1, ch);
        top++;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;

    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;

    int err = dx + dy;
    while (true) {
        this -> SetPoint(y1, x1,ch);

        if (x1 == x2 && y1 == y2)    break;
        if (2 * err >= dy)           err+=dy, x1 +=sx;
        if (2 * err <= dx)           err+=dx, y1 +=sy;
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    this->canvasElements[x][y] = ch;
}

void Canvas::Print() {
    std::cout << '\n';
    for(int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++)
            std::cout << this->canvasElements[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear() {
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++)
            this->canvasElements[i][j] = ' ';
}
