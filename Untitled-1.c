#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 25
#define COLS 50

char canvas[ROWS][COLS];

void clearCanvas() {
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            canvas[i][j] = '_';
}

void displayCanvas() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}

void drawLine(int x1,int y1,int x2,int y2) {
    int dx = abs(x2-x1), dy = abs(y2-y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while(1) {
        if(x1>=0 && x1<ROWS && y1>=0 && y1<COLS)
            canvas[x1][y1] = '*';

        if(x1==x2 && y1==y2) break;

        int e2 = 2*err;

        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRectangle(int x,int y,int w,int h) {
    for(int i=y;i<y+w;i++) {
        canvas[x][i] = '*';
        canvas[x+h-1][i] = '*';
    }

    for(int i=x;i<x+h;i++) {
        canvas[i][y] = '*';
        canvas[i][y+w-1] = '*';
    }
}

void drawTriangle(int x,int y,int size) {
    drawLine(x,y,x+size,y-size);
    drawLine(x,y,x+size,y+size);
    drawLine(x+size,y-size,x+size,y+size);
}

void drawCircle(int xc,int yc,int r) {
    for(int angle=0; angle<360; angle++) {
        double rad = angle * 3.14159 / 180;
        int x = xc + r*cos(rad);
        int y = yc + r*sin(rad);

        if(x>=0 && x<ROWS && y>=0 && y<COLS)
            canvas[x][y] = '*';
    }
}

void deleteArea(int x,int y,int w,int h) {
    for(int i=x;i<x+h;i++)
        for(int j=y;j<y+w;j++)
            if(i<ROWS && j<COLS)
                canvas[i][j] = '_';
}

int main() {
    int choice;

    clearCanvas();

    while(1) {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Canvas\n");
        printf("7. Clear Canvas\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==0)
            break;

        int x,y,x2,y2,w,h,r,size;

        switch(choice) {

        case 1:
            printf("x1 y1 x2 y2: ");
            scanf("%d%d%d%d",&x,&y,&x2,&y2);
            drawLine(x,y,x2,y2);
            break;

        case 2:
            printf("x y width height: ");
            scanf("%d%d%d%d",&x,&y,&w,&h);
            drawRectangle(x,y,w,h);
            break;

        case 3:
            printf("x y size: ");
            scanf("%d%d%d",&x,&y,&size);
            drawTriangle(x,y,size);
            break;

        case 4:
            printf("centerX centerY radius: ");
            scanf("%d%d%d",&x,&y,&r);
            drawCircle(x,y,r);
            break;

        case 5:
            printf("x y width height: ");
            scanf("%d%d%d%d",&x,&y,&w,&h);
            deleteArea(x,y,w,h);
            break;

        case 6:
            displayCanvas();
            break;

        case 7:
            clearCanvas();
            break;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}