//Numerical integration for a given set of data using composite Simpson's 1/3

#include <iostream>

using namespace std;

int main()
{
    int n=15;
    double x0,xf,h,y[n];

    x0=0; xf=84;
    y[0]=124;
    y[1]=134;
    y[2]=148;
    y[3]=156;
    y[4]=147;
    y[5]=133;
    y[6]=121;
    y[7]=109;
    y[8]=99;
    y[9]=85;
    y[10]=78;
    y[11]=89;
    y[12]=104;
    y[13]=116;
    y[14]=123;

    h=(xf-x0)/(n-1);

    //composite Simpson's 1/3
    double sumE=0,sumO=0,s_answer;
    for(int i=1; i<n-1; i++)
    {
        if(i%2==0){sumE+=y[i];}
        else {sumO+=y[i];}

    }
    s_answer=h*(y[0]+4*sumO+2*sumE+y[n-1])/3;
    cout<<"\n******************************************\n";
    cout<<"composite Simpson's 1/3 approximation = "<<s_answer;
    cout<<"\n******************************************\n";




    return 0;
}
