#include <iostream>
#define TERM '\0'

using namespace std;

class String{
    private:
    //char str1[size]; // arr of characters (strings)
    char *str1;
    int size;

    public:
    //int StrLength(String str);
    int StrLength(String str){
        //cout<<"ccccccc";
        int i=0;
        while(str.str1[i]!=TERM){
            i++;
        }
        return i;
    }
    int StrLengthCH(char str[]){
        int i=0;
        while(str[i]!=TERM){
            i++;
        }
        return i;
    }
    String(char *str){ // CONSTRUCTOR - create dynamic memory allocation
        int i = 0;
        size = StrLengthCH(str);
        str1=new char[size];// memory alloc - *str1 (the ptr I've) = new BLOCK in heap (new yb2a in heap alatool)
        for(i=0; i<size; i++){ // j a n a 0 1 2 3 4(TERM)
            str1[i]=str[i];
        }
        str1[size]=TERM;
    }

    ~String(){ // DESTRUCTOR
        delete[] str1;
    }

    // GETTERS AND SETTERS
    char * getString(){
        return str1;
    }
    void setString(char *strr){
        str1 = strr;
    }

    int getSize(){
        return size;
    }
    void setSize(int sizee){
        size=sizee;
    }
    // StrCopy
    void StrCopy(String &source){ // dest is this-> S1.StrCopy(S2);
        int i=0;
        //cout<<"String before copy: "<<this->str1<<endl;
        char * str2 = new char[source.size]; // DYNAMIC MEMORY
            while(source.str1[i]!=TERM){
                str2[i]=source.str1[i];
                i++;
            }
        str2[i]=TERM;
        //cout<<"String after copy: "<<this->str1<<endl;
        delete[] str1;
        this->str1=str2;
        this->size=source.size;
        return;
    }
    // StrCompare
    void StrCompare(String source){
        int i=0;
        if(source.size!=this->size){
            cout<<"NOT EQUAL";
            return;
        }
        else{
        while(source.str1[i]!=TERM){
            if(source.str1[i]!=this->str1[i]){
                cout<<"NOT EQUAL";
                return;
            }
            else{
                i++;
            }
        }
        cout<<"EQUAL";
        return;
    }
}
    // StrConcat
    void StrConcat(String &source){ // source is S2, dest is S1
        //cout<<"ana hena";
        int i=0;
        int j=0;
        int sizee=source.size+this->size+1;

        //  *str1 of S1 --> "mina", *str1 after new char points at "minajana", make it a null pointer then

        char *str2=new char[sizee]; // change str1 to str2 to avoid overwriting


            //cout<<source.str1<<endl;
            //cout<<source.size<<endl;
            //cout<<this->str1<<endl; // NOT READING STR1
            while(this->str1[i]!=TERM){ // jana
                //cout<<"ana hena"<<endl;
                str2[i]=str1[i]; // adding what's in str1 to the NEW ARRAY - IMPOOOO
                i++;
            }
            //cout<<i<<endl;
            while(source.str1[j]!=TERM){ // if S2 is != TERM
                str2[i]=source.str1[j]; // str2 --> minaX
                i++;
                j++;
            }
            str2[i]=TERM;
            delete [] str1; // deletes array that points at str1 BUT keeps the pointer
            this->str1 = str2; // str1 ptr points NOW at str2 (no need to delete[] str2 as now str1 points at it)
            this->size = sizee;
            //cout<<this->str1<<endl;
            //cout<<this->size;
    }
    //     STRING DISPLAY     //
    void display(){
        for(int i=0; i<size; i++){
            cout<<str1[i];
        }
    }

    // Operator Overloading
    // Operator> --> str1>str2 THEN true else false
    bool operator >(char *S2){
        cout<<"xxxxxxxxxxxxxxxxx"<<endl;
        if((this->size)>StrLength(S2)){
            return true;
        }
        else{
            return false;
        }
    }
    // Operator< --> str1<str2 THEN true else false
    bool operator<(char *S2){
        if(this->size<StrLength(S2)){
            return true;
        }
        else{
            return false;
        }
    }
    // Operator= --> S1=S2, copy str2 to str1
    void operator=(String &source){
        int i=0;
        //cout<<"String before copy: "<<this->str1<<endl;
        char * str2 = new char[source.size]; // DYNAMIC MEMORY
            while(source.str1[i]!=TERM){
                str2[i]=source.str1[i];
                i++;
            }
        str2[i]=TERM;
        //cout<<"String after copy: "<<this->str1<<endl;
        delete[] str1;
        this->str1=str2;
        this->size=source.size;
        return;
    } // MAKE OPERATOR > & <
    // Operator= --> S1=S2, copy str2 to str1
    /*String operator=(char *S2){
        StrCopy(this->str1, S2,StrLength(this->size+S2.size);
            return S2;
        }*/
};


int main()
{
    char *stringInp1="malak";
    //cout<<"Please Enter S1: "<<endl;
    //cin>>stringInp1;
    char *stringInp2="aminaa";
    //cout<<stringInp1;
    //cout<<stringInp2;
    //cout<<"Please Enter S2: "<<endl;
    //cin>>stringInp2;
    String S1(stringInp1);
    //S1.getString();
    String S2(stringInp2);
    //cout<<"Length: "<<S1.StrLength(S1)<<endl; - DONE
    //S1.StrCompare(S2); - DONE
    //S1.StrConcat(S2);
    //cout<<endl;
    //S1.display();
    //cout<<endl;
    //S2.display();
    cout<<"String after copy: "<<endl;
    S1.StrCopy(S2); // - DONE
    S1.display();
    cout<<endl;
    //S1.setString(stringInp1);
    //S2.setString(stringInp2);
    /*S1.setSize(size);
    S2.setSize(size);*/
    //S1>S2; // compare sizes
    /*cout<<"S1 > S2"<<endl;
    if(S1>S2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    //S1<S2; // compare sizes
    cout<<"S1 < S2"<<endl;
    if(S1<S2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }*/

    cout<<"operator ="<<endl; // - DONE
    S1=S2;
    S1.display();
    return 0;
}
