#include <iostream>
using namespace std;
int fn(int n[])
{
    n[3]=n[3]+1;
    return 0;
}
int main()
{
    int num[5]={2,3,6,8,10};
    int i;
    fn(num);
    for(i=0;i<5;i++)
        cout<<num[i]<< ' '<<endl;
    return 0;
}
