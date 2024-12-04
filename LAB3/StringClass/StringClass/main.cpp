#include <iostream>
#define TERM '\0'
using namespace std;


class String{
    private:
    //char str1[size]; // arr of characters (strings)
    char *str1;
    int size;

    public:
    String(char *str, int size){ // CONSTRUCTOR
        int i=0;
        size = StrLength(str);
        for(i=0; i<size; i++){ // READ ONLY
            str1[i]=str[i];
        }
    }
    String(char *str){ // CONSTRUCTOR
        int i=0;
        int size = StrLength(str);
        for(i=0; i<size; i++){ // READ ONLY
            str1[i]=str[i];
        }
    }

    ~String(){ // DESTRUCTOR
        // delete STRING
    }

    // GETTERS AND SETTERS
    char * getString(){
        return str1;
    }
    void setString(char *strr){ // I guess it's INCORRECT
        str1 = strr;
    }

    int getSize(){
        return size;
    }
    void setSize(int sizee){
        size=sizee;
    }
    // StrLength
    int StrLength(char *str){
        int i=0;
        while(str[i]!=TERM){
            i++;
        }
        return i;
    }
    // StrCopy
    void StrCopy(char source[],char dest[],int size){
        int i=0;
        if(StrLength(source)<size-1){
            while(source[i]!=TERM){
                dest[i]=source[i];
                i++;
            }
            dest[i]=TERM;
        }
        else{
            cout<<"Source > Destination"<<endl;
        }
        return;
    }
    // StrCompare
    int StrCompare(char source[], char dest[]){ // mina , jana
        int f=1;
        int i=0;
        int j=0;
        /*printf("Please enter string1: ");
        cin>>dest;
        printf("Please enter string2: ");
        cin>>source;*/
        while(f){
                if(dest[i] == TERM && source[j] == TERM){
                    f = 0;
                    return 0;
                }
                else if(dest[i] != TERM && source[j] == TERM){
                    i++;
                    f=0;
                }
                else if(dest[i] == TERM && source[j] != TERM){
                    j++;
                    f=0;
                }
                else if(dest[i] != TERM && source[j] != TERM){
                    i++;
                    j++;
                }
                else if(dest[i]<source[j]){
                    return -1;
                }
                else if(dest[i]>source[j]){
                    return 1;
                }
        }
        if(i==j){
            return 0;
        }
        else if(i<j){
            return -1;
        }
        else if(i>j){
            return 1;
        }
    }
    // StrConcat
    void StrConcat(char dest[], char source[], int size){
        int i=0;
        int j=0;
        if(StrLength(dest)>=StrLength(dest+size)){ // if destination size > size of destination + size of source
            while(dest[i]!=TERM){
                i++;
            }
            while(source[j]!=TERM){
                dest[i]=source[j];
                i++;
                j++;
            }
            dest[i]=TERM;
        }
        else{
            cout<<"Destination < Source + Destination"<<endl;
        }
    }
    // Operator Overloading
    // Operator> --> str1>str2 THEN true else false
    bool operator>(char *S2){
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
    // Operator== --> str1==str2 THEN true else false
    bool operator==(char *S2){
        if(StrCompare(this->str1,S2) == 0){ // NOT S1
            return true;
        }
        else{
            return false;
        }
    }
    // Operator= --> str1=str2, copy str2 to str1
    /*String operator=(char *S2){
        StrCopy(this->str1, S2,StrLength(this->size+S2.size);
            return S2;
        }*/
};


int main()
{
    char *stringInp1;
    cout<<"Please Enter S1: "<<endl;
    cin>>stringInp1;
    char *stringInp2;
    cout<<"Please Enter S2: "<<endl;
    cin>>stringInp2;
    String S1(stringInp1), S2(stringInp2);
    S1.setString(stringInp1);
    S2.setString(stringInp2);
    /*S1.setSize(size);
    S2.setSize(size);*/
    //S1>S2;
    cout<<"S1 > S2"<<endl;
    if(S1>S2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    //S1<S2;
    cout<<"S1 < S2"<<endl;
    if(S1<S2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    //S1==S2;
    cout<<"S1 == S2"<<endl;
    if(S1==S2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
