//
// Created by rosawan on 04/03/2021.
//

#ifndef LAB1_CANVAS_H
#define LAB1_CANVAS_H

const int dl[] = { 0, 1, 0 ,-1 };
const int dc[] = { 1, 0, -1, 0 };

class Canvas {
private:
    int height;
    int width;
    char ** canvasElements {nullptr};

    struct elem{
        int l, c, p;
    }queue[1000] {0};

public:

    Canvas(int width,int height);
    ~Canvas();

    void DrawCircle(int x, int y, int ray, char ch);                    //done
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);   //done
    void FillRect(int left, int top, int right, int bottom, char ch);   //done
    void SetPoint(int x, int y, char ch);                               //done
    void DrawLine(int x1, int y1, int x2, int y2, char ch);             //done
    void Print(); // shows what was printed                             //done
    void Clear(); // clears the canvas                                  //done
};



#endif //LAB1_CANVAS_H
