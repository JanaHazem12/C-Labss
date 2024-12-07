// INCLUDE


class Line(){ // MUST have a point (Line & Point --> COMPOSITION) + (Line & Picture --> AGGREGATION)
    private:
    Point point1;
    Point point2;

    public:
    Line():point1(),point2(){
        point1=nullptr;
        point2=nullptr;
    };
    Line(int x1, int y1,int x2, int y2), point1(x1,y1), point2(x2,y2){

    }
    void draw(){
        line(point1.getX(),point1.getY(),point2.getX(),point2.getY());
    }
    }
};


class Point(){
    private:
    int x;
    int y;
    Point point1;
    Point point2;

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setX(int xx){
        x=xx;
    }
    void setY(int yy){
        y=yy;
    }
    public:
    Point(){
    }
    Point(int x, int y){ // co-ords x,y

    }
    void draw(){
        line(point1.getX(),point1.getY(),point2.getX(),point2.getY());
    }
};

class Rectangle(){ // MUST have a LINE - (Rectangle & Point --> COMPOSITION) + (Rectangle & Picture --> AGGREGATION)
    private:
    Point point1;
    Point point2;

    public:
    Rectangle(), point1(), point2(){
    }
    Rectangle(int x1, int x2, int y1, int y2):point1(x1, y1),point2(x2, y2){
    } // 4 points BAS code 2 pts only (top left + bottom right)

    void draw(){
        rectangle(point1.getX(),point1.getX(),point2.getX(),point2.getY());
    }
    }
};

class Circle(){ // (Circle & Point --> COMPOSITION) + (Circle & Picture --> AGGREGATION)
    private:
    Point point1;
    int radius;

    public:
    Circle():point2(){
        point1=nullptr;
        radius=0;
    }
    Circle(int x, int y, int r):point1(x,y){
        radius = r;
    }

    void draw(){
        circle(point1.getX(),point1.getY(),radius);
    }
};

class Picture(){
    private:
    Line *L1;
    Rectangle * R1;
    Circle * C1;

    int LineCount;
    int RectCount;
    int CircleCount;

    public:
    Picture(){
        L1=nullptr;
        R1=nullptr;
        Circle=nullptr;
        LineCount=0;
        RectCount=0;
        CircleCount=0;
    }
    Picture(Line *linee, Rectangle *rectt, Circle *circlee, int LineNum ,int RectNum, int CircleNum){
        L1=line;
        R1=rectt;
        Circle=circlee;
        LineCount=LineNum;
        RectCount=RectNum;
        CircleCount=CircleNum;
    }
    void setLine(int, Line *);
    void setRectangle(int Rectangle *);
    void setCircle(int, Circle *);
    void paint();
};

    void Picture::setLine(int lc, Line *linee){
        LineCount=lc;
        L1=linee;
    }
    void Picture::paint()
    {
     for(int i=0; i<LineCount; i++){
        L1[i].draw();
    }

     for(int i=0; i<RectangleCount; i++){
        R1[i].draw();
    }
     for(int i=0; i<CircleCount; i++){
        c1[i].draw();
    }
    }



int main(){
    /*Line L; // comp
    Line line; // aggreg.
    Rectangle rect; // aggreg.
    Circle cir; // aggreg.
    Picture(&line);
    Picture(&rect);
    Picture(&cir);*/
    Picture pic;

    Line arrLine[2]={Line(420,50,300,300), Line(40,500,500,400)};
    Rectangle arrRect[]={Rectangle(30,40,170,100), Rectangle(40,500,500,400)};;
    Circle arrCircle[2]={Circle(50,50,50), Circle(20,100,100)};;

    Line L;
    Rectangle R;
    Circle C;

    pic.setLine(2,arrLine);
    pic.setRectangle(2,arrRect);
    pic.setCircle(2,arrCircle);

    pic.paint();

    return 0;
}

