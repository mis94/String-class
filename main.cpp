#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    int ch=1;
    String test1 = "data structure course";
    cout<<test1.length()<<endl;
    String test2 = test1.substring(5,6);
    cout<<test2<<endl;

    String caller = "ali-ahmed",passed = "-Mohamed";
    String tmp2 = caller.append(passed);
    cout<<tmp2<<endl;

    String se = "can you open this can for me?",se2 = "can";
    cout<<se.find(se2)<<endl;

    String orig = "ahmed ali ahmed mostafa";
    String old="ahmed",New="Hassan";
    String edit = orig.replace(old,New);
    cout<<edit<<endl;
    String paragraph = "Make the following assumptions: the English phrase consists of words separated by blanks, there are no punctuation marks and all words have two or more letters.  Create a program that inputs a string from the user and translates it into pig Latin.";
    paragraph.align(::left);
    cout<<endl;
    paragraph.align(::right);
    cout<<endl;
    paragraph.align(::justif);
    cout<<endl;

    String arr[4];
    arr[0] = "Ali";
    arr[1] = "Sameh";
    arr[2] = "Ahmed";
    arr[3] = "Mohamed";
    String::sort(arr,4);
    for(int i=0;i<4;i++)
        cout<<arr[i]<<endl;
    cout<<endl;

    String rev = "To be reversed";
    rev.reverse();
    cout<<rev<<endl;

    String to = "Ahmed Hosam";
    to.toUpper();
    cout<<to<<endl;
    to.toLower();
    cout<<to<<endl;

//    cout<<to.get_at(0);

    String empt;
    cout<<empt.isEmpty()<<" "<<to.isEmpty()<<endl;

    String c1 = "Ahmed" , c2="Ali" ,c3="Ali";
    cout<<c1.compare(c2)<<" ";
    cout<<c2.compare(c3)<<" ";
    cout<<c2.compare(c1)<<endl;

    return 0;
}
