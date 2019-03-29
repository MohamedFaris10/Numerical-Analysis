#include <iostream>
#include<cmath>

using namespace std;

int main()
{
    ///using the composite trapezoidal rule:
    int n=2;
    double t_answer,h,t_int1,t_int2,t_int3,y[n+1],x,s_answer,s_int1,s_int2,s_int3;
            //t stands for trapezoid & s stands for Simpson
    //first part from 0 to 0.1
    h=(0.1-0)/n;
    for(int i=0; i<=n; i++)
    {
        y[i]=pow((i*h),3)+1;
    }

    t_int1=h*(y[0]+2*y[1]+y[2])/2;  //using composite trapezoidal
    s_int1=0.1*(y[0]+4*y[1]+y[2])/(3*n); //using composite Simpson's 1/3

    //second part from 0.1 to 0.2
    for(int i=0; i<=n; i++)
    {
        x=0.1+i*h;
        y[i]=1.001+0.03*(x-0.1)+0.3*pow(x-+0.1,2)+2*pow(x-0.1,3);
    }

    t_int2=h*(y[0]+2*y[1]+y[2])/2;  //using composite trapezoidal
    s_int2=0.1*(y[0]+4*y[1]+y[2])/(3*n);  //using composite Simpson's 1/3

    //third part from 0.2 to 0.3
    for(int i=0; i<=n; i++)
    {
        x=0.2+i*h;
        y[i]=1.009+0.15*(x-0.2)+0.9*pow(x-0.2,2)+2*pow(x-0.2,2);
    }

    t_int3=h*(y[0]+2*y[1]+y[2])/2;  //using composite trapezoidal
    s_int3=0.1*(y[0]+4*y[1]+y[2])/(3*n);  //using composite Simpson's 1/3
    //total
    t_answer=t_int1+t_int2+t_int3;
    //error
    double error1,error2,error3,errorT;
    error1=0.1*pow(h,2)*6*0.1/12; //upper bound is 0.1
    error2=0.1*pow(h,2)*(0.6+12*(0.2-0.1))/12;  //upper bound is 0.2
    error3=0.1*pow(h,2)*(1.8+12*(0.3-0.2))/12;  //upper bound is 0.3
    errorT=error1+error2+error3;

    cout<<"\n******************************************\n";
    cout<<"composite trapezoidal approximation = "<<t_answer<<endl;
    cout<<"The maximum estimated error = "<<errorT;
    cout<<"\n******************************************\n";

    /*---------------------------------------------------------------------------------------------*/

    ///using Simpson's composite 1/3 rule:

    s_answer=s_int1+s_int2+s_int3;
    cout<<"\n******************************************\n";
    cout<<"composite Simpson's 1/3 approximation = "<<s_answer<<endl;
    cout<<"The estimated error = zero because it is a third degree function";
    cout<<"\n******************************************\n";

    return 0;
}
