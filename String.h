#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
enum AlignType{
    left,
    right,
    justif
};
class String
{
    public:
        char* arr;
        int size ;
        //bool smaller(char* word1,char* word2);

    public:
        String();
        String(const String& other);
        String(const char* entery);
        ~String();
        int length();
        String substring(int st, int num);
        String append(String& objStr);
        int find(String &objStr);
        String replace(String&, String&);
        void align(AlignType AT);
        static void sort(String arr[],int sz);
        void reverse();
        void toUpper();
        void toLower();
        char get_at(int ind);
        bool isEmpty();
        int compare(String& second);

        friend istream& operator>>(istream &in,String& obj);
        friend istream& getline(istream &in,String& obj);
        friend ostream& operator<<(ostream &out,String& obj);
        String& operator=(const char* entery);
};

#endif // STRING_H
