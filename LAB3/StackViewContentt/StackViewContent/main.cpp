#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#endif
#include <unistd.h>     // for isatty()
#endif
#define SIZE 5
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

void gotoxy1(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), coord) ;
}

typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;

// set output color on the given stream:
void setTextColor(FILE *stream, TextColor color);

// PUSH NEW EMPLOYEE --> name, salary ONLY
// POP LAST EMPLOYEE
// DISPLAY ALL EMPLOYEES

typedef struct Employee{
    int id;
    char name[20];
    int salary;
}Employee;

Employee e1[SIZE];

class Stack{
    private:
    int top;
    int size;
    int counter; // number of employees
    //int * elements;
    Employee *e1;// we're sending a pointer NOT an array

    public:
    // COPY CONSTRUCTOR - haykhosh fi alatool mesh haykhosoh fel destructor
    /*Stack(const Stack &s2){
        top = s2.top;
        size = s2.size;
        e1=s2.e1;
        cout<<"Copy Constructor !!"<<endl;
    }*/
    Stack(int size){ // CONSTRUCTOR
        this->size=size;
        top=-1;
        e1 = new Employee[size]; // here it's an array
        cout<<"Constructor !!"<<endl;
    }
    ~Stack(){ // DESTRUCTOR
        cout<<"Destructor"<<endl;
        delete[] e1;
    }

    int push(){ // check if stack is FULL, then I CAN'T PUSH
        // cin id, cin name, cin salary, top++
        if(top == size-1){ // FULL STACK
            setTextColor(stdout, TC_RED);
            cout<<"STACK IS FULL!!!!!\n"<<endl;
            setTextColor(stdout, TC_WHITE);
            return 0;
        }
        // NOT FULL STACK
        top++; // increment top so I can add next input in the next index
        // PUSH EMPLOYEE DATA //
        gotoxy1(4,4);
        cout<<"Enter ID: "<<endl;
        gotoxy1(4,6);
        cin>>e1[top].id;
        gotoxy1(4,8);
        cout<<"Enter Name: "<<endl;
        gotoxy1(4,10);
        cin>>e1[top].name;
        gotoxy1(4,12);
        cout<<"Enter Salary: "<<endl;
        gotoxy1(4,14);
        cin>>e1[top].salary;
        gotoxy1(6,16);
        setTextColor(stdout, TC_YELLOW);
        cout<<"Employee added successfully !!! "<<endl;
        Sleep(3000);
        system("cls");
        setTextColor(stdout, TC_BLUE);
        gotoxy1(10,5);
        printf("New");
        setTextColor(stdout, TC_WHITE);
        gotoxy1(10,9);
        printf("Display");
        gotoxy1(10,13);
        printf("Pop");
        gotoxy1(10,17);
        printf("Exit");
        return 1;
    }
    int getTop(){
        return top;
    }
    int pop(){ // check if stack is EMPTY, then I CAN'T POP, if I want to store the data I popped I've to put data as reference
        if(top == -1){
            return 0;
        }
        e1[top].id=0;
        //e1[top].name='\0';
        e1[top].salary=0;
        top--;
        return 1;
    }

        void display(){ // display all stack elements
        // display number of employees using counter //
            if(top == -1){// CHECK IF STACK IS EMPTY, THEN PRINT "EMPTY STACK"
                setTextColor(stdout, TC_RED);
                cout<<"Empty Stack!!"<<endl;
                setTextColor(stdout, TC_WHITE);
            }
            else{ // STACK IS NOT EMPTY
                //gotoxy1(10,5);
                int space = 5;
                int counter=0;
                gotoxy1(10,space);
                for (int i = 0; i <= top; i++) {
                    gotoxy1(10, space++);
                    cout<<"ID: "<<e1[i].id;
                    gotoxy1(10, space++);
                    cout<<"Name: "<<e1[i].name;
                    gotoxy1(10, space++);
                    cout<<"Salary: "<<e1[i].salary<<endl;
                    space++;
                    counter++;
                    }
                    printf("\n\t\t\t\t\t\t");
                    setTextColor(stdout, TC_BLUE);
                    cout<<"Number of Employees: "<<counter<<endl;
                    setTextColor(stdout, TC_WHITE);
            }
    }
};

void viewContent(Stack &s){ // CALL BY VALUE , CALL BY REFERENCE &s
        if(s.getTop() == -1){// CHECK IF STACK IS EMPTY, THEN PRINT "EMPTY STACK"
                setTextColor(stdout, TC_RED);
                cout<<"Empty Stack!!"<<endl;
                setTextColor(stdout, TC_WHITE);
            }
            else{ // STACK IS NOT EMPTY
                //gotoxy1(10,5);
                int space = 5;
                int counter=0;
                gotoxy1(10,space);
                for (int i = 0; i <= s.getTop(); i++) {
                    gotoxy1(10, space++);
                    cout<<"ID: "<<e1[i].id;
                    gotoxy1(10, space++);
                    cout<<"Name: "<<e1[i].name;
                    gotoxy1(10, space++);
                    cout<<"Salary: "<<e1[i].salary<<endl;
                    space++;
                    counter++;
                    }
                    printf("\n\t\t\t\t\t\t");
                    //gotoxy(row,10);
                    setTextColor(stdout, TC_BLUE);
                    cout<<"Number of Employees: "<<counter<<endl;
                    setTextColor(stdout, TC_WHITE);
            }
    }

int Arrows(char key, int pos){
    if(key==72){ //arrow up
        if(pos == 1){
            pos = 4;
        }
        else{
            pos-=1;
        }
    }
    else if(key==80){ //arrow down
        if(pos == 4){
            pos=1;
        }
        else{
            pos+=1;
        }
    }
    return pos;
}



int main(void){

                int sizee;
                cout<<"Please Enter Stack Size: ";
                cin>>sizee;
                Stack s2(sizee);
                cout<<endl;
                viewContent(s2); // CALL BY VALUE (with & without COPY CONSTR.)
                //s2.viewContent(s2); // CALL BY REFERENCE
                int c=0;
                int pos=1;
                int row=10;
                int column=5;
                setTextColor(stdout, TC_BLUE);
                gotoxy1(row,column);
                printf("New");
                setTextColor(stdout, TC_WHITE);
                gotoxy1(row,column+4);
                printf("Display");
                gotoxy1(row, column+8);
                printf("Pop");
                gotoxy1(row,column+12);
                printf("Exit");
                int flag=1;
                while(flag==1){
                    char key=0;
                    key = getch();

                    if(key==-32){ // up, down, left, right
                        key = getch();
                        //printf("%d\n", key);
                        pos = Arrows(key,pos);
                        if(pos==1){
                            system("cls"); //sys OR system ??
                            setTextColor(stdout, TC_BLUE);
                            gotoxy1(row,column);
                            printf("New");
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column+4);
                            printf("Display");
                            gotoxy1(row, column+8);
                            printf("Pop");
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column+12);
                            printf("Exit");
                        }
                        if(pos==2){
                            system("cls"); //sys OR system ??
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column);
                            printf("New");
                            setTextColor(stdout, TC_BLUE);
                            gotoxy1(row,column+4);
                            printf("Display");
                            gotoxy1(row, column+8);
                            setTextColor(stdout, TC_WHITE);
                            printf("Pop");
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column+12);
                            printf("Exit");
                        }
                        if(pos==3){
                            system("cls"); //sys OR system ??
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column);
                            printf("New");
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column+4);
                            printf("Display");
                            gotoxy1(row, column+8);
                            setTextColor(stdout, TC_BLUE);
                            printf("Pop");
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column+12);
                            printf("Exit");
                        }
                        if(pos==4){
                            system("cls"); //sys OR system ??
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column);
                            printf("New");
                            setTextColor(stdout, TC_WHITE);
                            gotoxy1(row,column+4);
                            printf("Display");
                            gotoxy1(row, column+8);
                            setTextColor(stdout, TC_WHITE);
                            printf("Pop");
                            setTextColor(stdout, TC_BLUE);
                            gotoxy1(row,column+12);
                            printf("Exit");
                        }
                    }

                    else if(key==13){ // enter
                        switch(pos){
                            case 1:
                                {
                                system("cls");
                                setTextColor(stdout, TC_WHITE);
                                int f=1;
                                gotoxy1(row,column);
                                //c=enter_Employee(e1, c);
                                s2.push();
                                break;
                        }
                            case 2:
                                system("cls");
                                setTextColor(stdout, TC_WHITE);
                                gotoxy1(row,column);
                                //display_Employee(e1, c);
                                s2.display();
                                break;

                            case 3:
                                system("cls");
                                setTextColor(stdout, TC_WHITE);
                                gotoxy1(row, 3);
                                printf("EMPLOYEES BEFORE POP");
                                //printf("\n");
                                gotoxy1(row,column+4);
                                s2.display();
                                Sleep(5000);
                                system("cls");
                                s2.pop();
                                gotoxy1(row, 3);
                                printf("EMPLOYEES AFTER POP\n\n\t\t");
                                //gotoxy1(20,5);
                                s2.display();
                                break;

                            case 4:
                                system("cls");
                                setTextColor(stdout, TC_WHITE);
                                gotoxy1(row,column);
                                return 0; // QUITTING
                                printf("Exit");

                                //modify_Employee(e1,c);
                                break;

                                // display employees by their ID only DONEEE,
                                // choose employee id you want to modify DONEEE,
                                // asks you what do u want to modify ? for ex: name, salary, THEN modify it DPNEEE
                        }

                    }
                    else if(key==27){ // ESCAPE key
                        system("cls"); //sys OR system ??
                        setTextColor(stdout, TC_BLUE);
                        gotoxy1(row,column);
                        printf("New");
                        setTextColor(stdout, TC_WHITE);
                        gotoxy1(row,column+4);
                        printf("Display");
                        setTextColor(stdout, TC_WHITE);
                        gotoxy1(row, column+8);
                        printf("Pop");
                        setTextColor(stdout, TC_WHITE);
                        gotoxy1(row, column+12);
                        printf("Exit");
                    }
                }
                return 0; //
            }

int uniqueID(int userID){ // temp is IDs that are already saved, userID is the user input rn
                //int f=1;
                int i=0;
                for(i=0; i<SIZE; i++){
                    if(e1[i].id == userID){ // one of the IDs in the array = userinputID
                        //f=0;
                        return 0; // break the loop
                    }// ID IS NOT UNIQUE
                }
                return 1;
            }


#ifdef _WIN32

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}

#else

static const char *ansiColorSequences[] =
{
    "\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m"
};

static const char *ansiColorTerms[] =
{
    "xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0
    // there are probably missing a few others
};

// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{
    char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        fputs(ansiColorSequences[color], stream);
    }
}

#endif
