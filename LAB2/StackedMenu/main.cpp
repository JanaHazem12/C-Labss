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
    Stack(int size){ // CONSTRUCTOR
        this->size=size;
        top=-1;
        e1 = new Employee[size]; // here it's an array
    }
    ~Stack(){ // DESTRUCTOR
        //cout<<"Destructor"<<endl;
        delete e1;
    }

    int push(){ // check if stack is FULL, then I CAN'T PUSH
        // cin id, cin name, cin salary, top++
        if(top == size-1){ // FULL STACK
            setTextColor(stdout, TC_RED);
            cout<<"STACK IS FULL!!!!!\n";
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
                cout<<"Empty Stack!!";
                setTextColor(stdout, TC_WHITE);
            }
            else{ // STACK IS NOT EMPTY
                //gotoxy1(10,5);
                int space = 5;
                int counter=0;
                gotoxy1(10,space);
                for (int i = 0; i <= top; i++) {
                    gotoxy1(10, space++);
                    cout<<"ID"<<i<<": "<<e1[i].id;
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
};

// use an enum for platform-independent interface:


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

//int enter_Employee(Employee e1[ ], int c); // PROTOTYPE
//void display_Employee(Employee e1[ ], int c); // PROTOTYPE
//void modify_Employee(Employee e1[ ], int c); // PROTOTYPE
//int uniqueID(int userID); // PROTOTYPE

// wana fel NEW, a-call s.push() w hayeb2a gowaha cin, cout


int main(void){

                int sizee;
                cout<<"Please Enter Stack Size: ";
                cin>>sizee;
                Stack s(sizee);
                cout<<endl;
                /*try{
                    s.pop(&)?cout<<"Popped Element: "<<storedData<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;
                    s.pop(&storedData)?cout<<"Popped Element: "<<storedData<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;
                    s.pop(&storedData)?cout<<"Popped Element: "<<storedData<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;

                    s.display();
                }
                catch(const exception& e){
                    cout<<"Exception Caught!!"<<endl;
                }*/

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
                                s.push();
                                break;
                        }
                            case 2:
                                system("cls");
                                setTextColor(stdout, TC_WHITE);
                                gotoxy1(row,column);
                                //display_Employee(e1, c);
                                s.display();
                                break;

                            case 3:
                                system("cls");
                                setTextColor(stdout, TC_WHITE);
                                gotoxy1(row, 3);
                                printf("EMPLOYEES BEFORE POP");
                                //printf("\n");
                                gotoxy1(row,column+4);
                                s.display();
                                Sleep(5000);
                                system("cls");
                                s.pop();
                                gotoxy1(row, 3);
                                printf("EMPLOYEES AFTER POP\n\n\t\t");
                                //gotoxy1(20,5);
                                s.display();
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


//int enter_Employee(){ // PUSH



    // CALL PUSH FUNCTION //
    //s.push();



                /*int userID;
                int flag=0;
                int flagg=0;
                int ff=0;
                char term;
                if(c<=SIZE){
                    int check_validation=1;
                    while(!flag){
                    //scanf("%d", &userID);
                    while(check_validation){ // check_validation = 1
                        //scanf("%d%c", &userID, &term);
                        //setTextColor(stdout, TC_RED);
                        if((scanf("%d%c", &userID, &term)==2 && userID >0 && term=='\n')){ // nothing except INT !!
                                //printf("WAITING");
                                check_validation=0;
                        }
                        else{
                            setTextColor(stdout, TC_RED);
                            printf(" \n\t ERROR: Invalid input! Please enter numbers only: ");
                            setTextColor(stdout, TC_WHITE);
                            fflush(stdin);
                        }
                    }
                    if(uniqueID(userID) == 0){ // unique = 1, not unique = 0
                        setTextColor(stdout, TC_RED);
                        printf(" \n\t ID ALREADY TAKEN!! ");
                        printf(" \n\t Please enter a valid id: ");
                        setTextColor(stdout, TC_WHITE);
                        //scanf("%d", &userID);
                        int check_validation=1;
                        //while(!flagg){}
                        while(check_validation){
                        //scanf("%d%c", &userID, &term);
                        if((scanf("%d%c", &userID, &term)==2 && userID > 0 && term=='\n')){ // nothing except INT !!
                                //printf("WAITING");
                                check_validation=0;
                                //printf(" \n\t ID added successfully ");
                                //v1++;
                                //printf(" \n\t Employee added successfully! Press enter to add another employee or escape to go back.");
                        }
                        else{
                            setTextColor(stdout, TC_RED);
                            printf(" \n\t ERROR: Invalid input! Please enter numbers only: ");
                            setTextColor(stdout, TC_WHITE);
                            fflush(stdin);
                            //v1++;
                        }
                    }
                        }
                    else{
                        flag=1;
                        }
                    }

                    e1[c].id=userID;

                    printf(" \n\t Enter Employee Name= ");
                    scanf("%s", &e1[c].name); // DO NOT USE & because NAME is a set of values NOT a single value

                    printf(" \n\t Enter Employee Salary= ");
                    int checkV=1;
                    while(checkV){
                        if((scanf("%d%c", &e1[c].salary, &term)==2 && e1[c].salary > 0 && term=='\n')){ // nothing except INT !!
                                checkV=0;
                        }
                        else{
                            setTextColor(stdout, TC_RED);
                            printf(" \n\t ERROR: Invalid input! Please enter numbers only: ");
                            setTextColor(stdout, TC_WHITE);
                            fflush(stdin);
                        }
                }
                setTextColor(stdout, TC_YELLOW);
                printf(" \n\t Employee added successfully! Press enter to add another employee or escape to go back.");
                setTextColor(stdout, TC_WHITE);
                c+=1;
    }*/
    //return c;
//}

//void display_Employee(Employee e1[ ], int c){ // DISPLAY

    // CALL DISPLAY FUNCTION //
    //s.display()



                /*if(c<=SIZE){
                int i=0;
                int r = 10;
                int col = 5;
                int sum = 0;
                for(i=0; i<c; i++){ // looping over C to display data of the specific number of employees added!!
                setTextColor(stdout, TC_LIGHTMAGENTA);
                printf(" \n\t Employee id: %d \n", e1[i].id);
                printf(" \n\t Employee Name: %s \n", e1[i].name);
                printf(" \n\t Employee Salary: %d \n", e1[i].salary);
                setTextColor(stdout, TC_WHITE);
                printf("\n");
                }
            }*/
//return 0;
//}

/*void modify_Employee(Employee e1[ ], int c){
                 int userID;
                 int i=0;
                 int r = 10;
                 int col = 5;
                 int sum = 0;
                 int num = 0;
                 int attr=0;
                 int mod = 0;
                 int size = 5;
                 int arr[5];

                 for(i=0; i<c; i++){ // looping over C to display data of the specific number of employees added!!
                    setTextColor(stdout, TC_GREEN);
                    printf(" \n\t Employee id: %d \n", e1[i].id);
                    setTextColor(stdout, TC_WHITE);
                 }
                 printf(" \n\t Which id do you want to modify? ");
                 int check_validation=1;
                                char term;
                                while(check_validation){
                                if((scanf("%d%c", &num, &term)==2 && num > 0 && term=='\n')){ // nothing except INT !!
                                        check_validation=0;
                                }
                                else{
                                    setTextColor(stdout, TC_RED);
                                    printf(" \n\t ERROR: Invalid input! Please enter numbers only: ");
                                    setTextColor(stdout, TC_WHITE);
                                    fflush(stdin);
                                }
                            }

                 int fg=1;
                 while(fg){
                     for(i=0; i<c; i++){
                        if(num==e1[i].id){ // IF I INSERTED A NEW ID, ERRORRR
                             printf(" \n\t Which attribute do you want to modify? \n\t Please enter 1 for ID, 2 for name, 3 for salary: ");
                                int check_validation=1;
                                char term;
                                while(check_validation){
                                if((scanf("%d%c", &attr, &term)==2 && attr > 0 && (attr == 1 || attr == 2 || attr == 3) && term=='\n')){ // nothing except INT !!
                                        check_validation=0;
                                        printf(" \n\t VALID INPUT!! \n ");
                                }
                                else{
                                    setTextColor(stdout, TC_RED);
                                    printf(" \n\t ERROR: Invalid input! Please enter 1 for ID, 2 for name, 3 for salary: ");
                                    setTextColor(stdout, TC_WHITE);
                                    fflush(stdin);
                                }
                            }
                             if(attr == 1){ // CHANGE ID - MOD is new value
                                printf(" \n\t modification: ");
                                scanf(" %d", &e1[i].id);
                                printf(" \n\t MODIFIED SUCCESSFULLY! Press escape to go back.");
                        }
                            else if(attr == 2){
                                printf(" \n\t modification: ");
                                scanf(" %s", e1[i].name);
                                printf(" \n\t MODIFIED SUCCESSFULLY! Press escape to go back.");
                            }
                            else if(attr == 3){
                               printf("modification: ");
                               scanf(" %d", &e1[i].salary);
                               printf(" \n\t MODIFIED SUCCESSFULLY! Press escape to go back.");
                            }
                             fg=0;
                            }
                        }

                     if(fg==0){ // attr --> 1 id, 2 name, 3 salary

                     }
                     else{
                     setTextColor(stdout, TC_RED);
                     printf(" \n\t UNAVAILABLE ID, please enter a valid ID: ");
                     setTextColor(stdout, TC_WHITE);
                     scanf(" %d", &num);
                     }
}

                 int flag=0;
        return 0;
}*/



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
