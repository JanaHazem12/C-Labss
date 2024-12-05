#include <iostream>
using namespace std;

// list of elements el size bta3ha changes every time I add an element
// PUSH example --> list size = 0 , PUSH , list size = 1 ANOTHER PUSH list size = 1 , PUSH , list size = 2
// POP example --> list size = 3 , POP , list size = 2 ANOTHER POP list size = 2 , POP , list size = 1


class List{
    private:
    int size;
    int *list1;

    public:
    //  GETTERS & SETTERS  //
    int getSize(){
        return size;
    }
    /*void setSize(int sizee){
        size=sizee;
    }*/
    int *getList(){
        return list1;
    }
    /*void setList(List listt){
        list1=listt;
    }*/

    //     CONSTRUCTOR   (initial values)  //
    List(){
        this->size=0;
        list1 = new int[size];
    }
    //    DESTRUCTOR    //
    ~List(){
        delete[] list1;
    }

    //     PUSH    // --> values are put, size is incremented by 1
    void push(int x){ // list1.push(list2,5);
        if(size==0){
            size++; // size = 1
            int i =0;
            int* list3=new int[size];
            list3[i]=x;
            delete[] list1;
            list1=list3;
        }
        else{
             int j=0;
             size++; // size = 2   // example: list1 has 1 20    20,30
             int* list2=new int[size];
             while(j<size-1){
                list2[j]=list1[j];
                //cout<<list1[j]<<endl;
                j++;
             }
             list2[size-1]=x;
             delete[] list1;
             list1=list2;
        }

        //this->size=size;
    }

    //     POP     // --> values are deleted, size is decremented by 1
    int pop(){
        int i=0;
        int storedData=list1[size-1];  // POPPED DATA
        size-=1;
        int *list2 = new int[size]; // jana 4 size-- array fady with size 3
        while(i<size){ // loop over new list
            list2[i]=list1[i];
            i++;
        }
        // j a n a 0 1 2 3 i=0 list2=jana
        delete[] list1;
        list1=list2;
        return storedData; // jan a=storedData
    }

    //    DISPLAY    //
    void display(){
        if(size == 0){
            cout<<"Empty List!!"<<endl;
        }
        else{
            //int i=0;
            for(int i=0; i<size; i++){
                cout<<list1[i]<<" ";
            }
            cout<<endl;
        }
    }

    //    operator=   //  --> list1 = list2 --> copy what's in L2 to L1 --------

    //    list1.operator=(list2) - destination = list1 , source = list2
    // TEST CASE:  NOT EQUAL/EQUAL --> MAKE A NEW ARRAY OF SIZE L2

    void operator=(List &list2){  // source=L2 , dest=list1
        int *list3 = new int[list2.size];
        int i=0;
        while(i<list2.size){
            //list2.display();
            //cout<<endl;
            list3[i]=list2.list1[i]; // list3 is int * , list2 is List
            //cout<<list3[i]<<" ";
            i++;
        }
        //list2.display();
        //cout<<endl;
        //cout<<list3[i]<<" ";
        delete[] list1;
        list1=list3;
        this->size=list2.size;
        /*for(int i=0; i<list2.size; i++){
            cout<<list1[i]<<" ";
        }*/
    }
};

int main()
{
    int num1=50;
    int num2=30;
    List list1;
    List list2;
    //List list2();

    list1.push(num1);
    list1.push(num2);
    cout<<"List: ";
    list1.display();

    list2.push(100);
    list2.push(200);
    list2.push(300);
    cout<<"List2: ";
    list2.display();

    cout<<"POPPED DATA: "<<list1.pop()<<endl;
    cout<<"List1 after pop: ";
    list1.display();

    cout<<"operator= ";
    list1=list2;
    list1.display();
    return 0;
}
