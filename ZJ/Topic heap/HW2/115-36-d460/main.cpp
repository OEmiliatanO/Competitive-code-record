#include <iostream>

using namespace std;

int main()
{
    int age;
    while(cin>>age)
    {
        if(age>=0&&age<=5)
            cout<<"0"<<endl;
        else if(age>=6&&age<=11)
            cout<<"590"<<endl;
        else if(age>=12&&age<=17)
            cout<<"790"<<endl;
        else if(age>=18&&age<=59)
            cout<<"890"<<endl;
        else if(age>=60)
            cout<<"399"<<endl;
    }
    return 0;
}
