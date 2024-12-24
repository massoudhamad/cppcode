#include<iostream>
using namespace std;
double base = 5.0; 
int radius = 2; 
int main() { 
cout<<"The VALUE of base is: "<<base<<endl; 
cout<<"The ADDRESS of base is: "<<&base<<endl; 
cout<<"The SIZE of double base is: "<<sizeof(double)<< "bytes \n"; 
cout<<"The VALUE of radius is: "<<radius<<endl; 
cout<<"The ADDRESS of radius is: "<<&radius<<endl; 
cout<<"The SIZE of integer radius is: "<<sizeof(int)<<" bytes \n"; 
return 0;
}

/* int cube(int *);
int main()
{
int number=5;
cout<<"Original value of number is :"<<number<<endl;
number=cube(&number);
cout<<"New value of number is "<<number<<endl;
return 0;
}

int cube(int *n){
return *n * *n * *n;
} */
