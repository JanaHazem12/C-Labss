// INCLUDE
#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

using namespace std;

class Shape{
    protected:
    int color;

    public:
    Shape(){
        color=RED;
        cout<<"Non-parametrized Parent Constructor\n";
    }
    Shape(int color){
        this->color=color;
        cout<<"Parametrized Parent Constructor\n";

    }
    ~Shape(){
        cout<<"PARENT DESTRUCTOR\n";
    }
};


class Point{
    private:
    int x;
    int y;
    //Point point1;
    //Point point2;

    public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }

    Point():x(0),y(0){

    }
    Point(int a, int b):x(a),y(b){ // co-ords x,y

    }
    /*void draw(){
        line(point1.getX(),point1.getY(),point2.getX(),point2.getY());
    }*/
};

class Line:public Shape{ // MUST have a point (Line & Point --> COMPOSITION) + (Line & Picture --> AGGREGATION)
    private:
    Point point1;
    Point point2;

    public:
    Line():point1(),point2(),Shape(){
        cout<<"non-param LINE constructor"<<endl;
    }
    Line(int x1, int y1,int x2, int y2, int color):point1(x1,y1), point2(x2,y2),Shape(color){
        cout<<"param. LINE constructor"<<endl;
    }
    ~Line(){
        cout<<"LINE DESRTRUCTOR"<<endl;
    }
    void draw(){
        line(point1.getX(),point1.getY(),point2.getX(),point2.getY());
    }
};

class Rectanglee:public Shape{ // MUST have a LINE - (Rectangle & Point --> COMPOSITION) + (Rectangle & Picture --> AGGREGATION)
    //Rectangle
    private:
    Point point1;
    Point point2;

    public:
    Rectanglee(): point1(), point2(),Shape(){
        cout<<"non-param. RECTANGLE constructor"<<endl;
    }
    Rectanglee(int x1, int y1, int x2, int y2, int color):point1(x1, y1),point2(x2, y2),Shape(color){
        cout<<"param. RECTANGLE constructor"<<endl;
    }
    // 4 points BAS code 2 pts only (top left + bottom right)
    ~Rectanglee(){
        cout<<"RECTANGLE DESRTRUCTOR"<<endl;
    }

    void draw(){
        rectangle(point1.getX(),point1.getY(),point2.getX(),point2.getY());
    }
};

class Circle:public Shape{ // (Circle & Point --> COMPOSITION) + (Circle & Picture --> AGGREGATION)
    private:
    Point point1;
    int radius;

    public:
    Circle():point1(),radius(0),Shape(){
        cout<<"non-param. CIRCLE constructor"<<endl;

    }
    Circle(int x, int y, int r, int color):point1(x,y),radius(r),Shape(color){
        cout<<"param. CIRCLE constructor"<<endl;

    }
    ~Circle(){
        cout<<"CIRCLE DESTRUCTOR"<<endl;
    }

    void draw(){
        circle(point1.getX(),point1.getY(),radius);
    }
};

class Picture{
    private:
    Line *L1;
    Rectanglee *R1;
    Circle *C1;

    int LineCount;
    int RectCount;
    int CircleCount;

    public:
    Picture(){
        L1=NULL;
        R1=NULL;
        C1=NULL;
        LineCount=0;
        RectCount=0;
        CircleCount=0;
    }
    /*Picture(Line *linee, Rectangle *rectt, Circle *circlee, int LineNum ,int RectNum, int CircleNum){
        L1=line;
        R1=rectt;
        Circle=circlee;
        LineCount=LineNum;
        RectCount=RectNum;
        CircleCount=CircleNum;
    }*/

    void setCircle(int CC, Circle* circlee) {
        CircleCount = CC;
        C1 = circlee;
    }

    void setRectangle(int RC, Rectanglee*rectt) {
        RectCount = RC;
        R1 = rectt;
    }

    void setLine(int LC, Line* linee) {
        LineCount = LC;
        L1 = linee;
    }

    void paint() {
        for(int i=0; i<LineCount; i++){
            L1[i].draw();
        }
        for(int i=0; i<RectCount; i++){
            R1[i].draw();
        }
        for(int i=0; i<CircleCount; i++){
            C1[i].draw();
        }
    }

    /*void setLine(int, Line *);
    void setRectangle(int Rectangle *);
    void setCircle(int, Circle *);
    void paint();*/
};


int main(){
    /*Line L; // comp
    Line line; // aggreg.
    Rectangle rect; // aggreg.
    Circle cir; // aggreg.
    Picture(&line);
    Picture(&rect);
    Picture(&cir);*/


    /*int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // Graphic Mode
    Picture myPic;

    //Line ArrL[2] = {Line(420,50,300,300),Line(45,500,500,400)};
    Rectanglee ArrR[4] = {Rectanglee(200,30,300,125,RED),Rectanglee(200,150,300,245,RED),Rectanglee(200,270,300,365,RED),Rectanglee(10,150,150,245,RED)}; // 600,100 - 270,50
    //Circle ArrC[3] = {Circle(50,50,50),Circle(200,100,100),Circle(420,50,30)};

    // x1,x2,y1,y2
    //myPic.setLine(2, ArrL);
    myPic.setRectangle(4, ArrR);
    //myPic.setCircle(3, ArrC);

    myPic.paint();*/

    //Shape s;
    /*Line L;
    Rectanglee R;
    Circle C;*/

    //getch();


    return 0;
}

