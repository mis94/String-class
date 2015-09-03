#include "String.h"

String::String(){
    size=0;
    arr = new char[1];
    arr[0] = '\0';
}
String::String(const String& other){

    delete[] arr;
    size = other.size;
    arr = new char[size+1];
    for(int i=0;i<size;i++)
        arr[i] = other.arr[i];
    arr[size]='\0';
}
String::String(const char* entery){
    int sz=0;
    while(entery[sz]!='\0')
        sz++;
    size = sz;
    arr = new char[size+1];
    for(int i=0;i<size;i++)
        arr[i] = entery[i];
    arr[size]='\0';
}
String::~String(){
    delete[] arr;
}
int String::length(){
    return size;
}

String String::substring(int st, int num){
    String temp ;
    if(st>=size||st<0)
        return temp ;

    temp.size = num;
    temp.arr = new char[min(size-st,num)+1];
    for(int i=st;i<st+num&&i<size;i++)
        temp.arr[i-st] = arr[i];
    temp.arr[min(size-st,num)]='\0';
    return temp ;
}
String String::append(String& objStr){
    char* arrTemp = new char[size+objStr.size] ;
    for(int i=0;i<size;i++)
        arrTemp[i] = arr[i] ;
    for(int i=size;i<size+objStr.size;i++)
        arrTemp[i] = objStr.arr[i-size] ;
    size += objStr.size;
    delete[] arr;
    arr = new char[size+1];
    for(int i=0;i<size;i++)
        arr[i]=arrTemp[i];
    arr[size] = '\0';
    delete[] arrTemp;

    return *this;
}
int String::find(String& objStr){
    for(int i=0;i<size;i++)
    {
        if(arr[i]==objStr.arr[0] && size-i>=objStr.size)
        {
            bool x = 1 ;
            for(int j=i;j<objStr.length()+i;j++)
            {
                if(arr[j]!=objStr.arr[j-i])
                {
                    x = 0 ;
                    break ;
                }
            }
            if(x)
                return i ;
        }
    }
    return -1 ;
}
String String::replace(String &old, String &New){
    while(find(old)!=-1){
        int st = find(old) , num = old.size;
        char* arrTemp = new char[size-num+New.size] ;
        for(int i=0;i<st;i++)
            arrTemp[i] = arr[i] ;
        for(int i=st;i<New.length()+st;i++)
            arrTemp[i] = New.arr[i-st] ;
        for(int i=st+num;i<size;i++)
            arrTemp[i-num+New.length()] = arr[i] ;
        size = size-num+New.length() ;
        delete[] arr;
        arr = new char[size+1];
        for(int i=0;i<size;i++){
            arr[i] = arrTemp[i];
        }
        arr[size]='\0';

        delete [] arrTemp ;
    }
    return *this;
}
void String::align(AlignType AT){
    if(AT == 0){
        int start=0,x=0;
        for(int i=0;i<size;i++){
            if(arr[i]==' ')
                x=i;
        if(i-start>=80){
            for(int j=start;j<x;j++)cout<<arr[j];
            if(x!=i)cout<<endl;
            start = x+1;
            }
        }
        for(int j=start;j<size;j++)
            cout<<arr[j];
        if(size-start<80)cout<<endl;
    }else if(AT == 1){
        int start = 0 ,x = 0;
        for(int i=0; i<size;i++){
            if(arr[i]==' ')
                x=i;
            if(i-start>=80){
                for(int j=0;j<80-x+start;j++)cout<<' ';
                for(int j=start;j<x;j++)cout<<arr[j];
                start = x+1;
            }
        }
        for(int j=0;j<80-(size-start);j++)
            cout<<' ';
        for(int j=start;j<size;j++)
            cout<<arr[j];
    }else{
        int start=0, x=0, words=0;
        for(int i=0;i<size;i++){
            if(arr[i]==' '){
                x=i;
                words++;
            }
            if(i-start>=80){
                int spaces = (80-(x-start))/(words-1);
                int remspaces = (80-(x-start))%(words-1);
                for(int j=start;j<x;j++){
                    if(arr[j] == ' ')
                        for(int i=0;i<spaces+1;i++)cout<<' ';
                    else cout<<arr[j];
                    if(arr[j] == ' ' && remspaces){
                        cout<<' ';
                        remspaces--;
                    }
                }
            start = x+1;
            words = 0;
        }
        }
        for(int j=start;j<size;j++)
            cout<<arr[j];

        if(size-start<80)
            cout<<endl;

    }
}

void String::sort(String arr[] ,int sz){
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            int comp=0;
            int length1 = arr[i].length(), length2 = arr[j].length();
            for(int m=0;m<min(length1,length1);m++){
                if(arr[i].arr[m]<arr[j].arr[m]){comp=-1;break;}
                else if(arr[i].arr[m]>arr[j].arr[m]){comp=1;break;}
            }
            if(!comp && length1<length2)comp -1;
            else if(!comp && length1<length2)comp= 1;

            if(comp == -1){
                char *tmp = arr[i].arr;
                arr[i].arr = arr[j].arr;
                arr[j].arr = tmp;
                arr[i].size = length2;
                arr[j].size = length1;
                tmp = NULL;
            }
        }
    }
}
void String::reverse(){
    char *arr2 = new char[size];
    for(int i=0;i<size;i++)
        arr2[i]=' ';

    char *arrTemp = new char[size];
    for(int i=0;i<size;i++){
        int wordsize=0;

        while(i<size&&arr[i]!=' ')
            arrTemp[wordsize++] = arr[i++];

        for(int j = size-i,x=0 ; x<wordsize ; j++,x++)
            arr2[j] = arrTemp[x];
    }

    for(int i=0;i<size;i++){
        arr[i] = arr2[i];
    }
    delete[] arrTemp;
    delete[] arr2;
}

void String::toLower(){
    for(int i=0;i<size;i++)
        if(arr[i]>='A'&&arr[i]<='Z')
            arr[i] = (char)(arr[i]-('A'-'a'));
}
void String::toUpper(){
    for(int i=0;i<size;i++)
        if(arr[i]>='a'&&arr[i]<='z')
            arr[i] = (char)(arr[i]+('A'-'a'));
}
bool String::isEmpty(){
    return !size;
}
int String::compare(String& second){
    for(int i=0;i<min(size,second.size);i++){
        if(arr[i]<second.arr[i])
            return -1;
        else if(arr[i]>second.arr[i])
            return 1;
    }
    if(size == second.size)return 0;
    else if(size<second.size)return -1;
    else return 1;
}
istream& operator>>(istream &in,String& obj){
    in>>obj.arr;
    int sz = 0;
    while(obj.arr[sz]!='\0')sz++;
    obj.size=sz;
    return in;
}
istream& getline(istream &in,String& obj){
    // in.getline(obj.arr,obj.MaxSize-1);
    return in;
}

ostream& operator<<(ostream &out,String& obj){
    out<<obj.arr;
    return out;
}

String& String::operator=(const char* entery){
    delete[] arr;
    int sz=0;
    while(entery[sz]!='\0')sz++;
    size = ++sz;
    arr = new char[size+1];
    for(int i=0;i<size;i++)
        arr[i] = entery[i];
    arr[size]='\0';
    return *this;
}

