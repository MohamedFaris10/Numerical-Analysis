#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x);

double f(double x){ //the function to be solved
    double ff=pow(x,3)-4*x-9;
    return ff;
}

double df(double x){ // the derivative of the function
    return 3*pow(x,2)-4;
}

int Bisection(double a,double b){
    double c,e,fa,fb,fc;
    int i=0; //iterations counter
    e = pow(10,-6);//setting the value of the error required
    fc=100;
    cout<<"\n Bisection Method\n\n";

        while(fabs(fc)>=e){

            i+=1; //incrementing the iterations counter

            c=(a+b)/2;
            fa=f(a);
            fb=f(b);
            fc=f(c);
            cout<<"a= "<<a<<" b"<<b<<" c="<<c<< " f(c)= "<<fc<<"    The relative error = "<<(c-a)/c<<endl;
            if(fc==0){
                cout<<"\n**************************\nthe true root is "<<c<<endl;
                break;
            }
            if(fa*fc>0){
                a=c;
            }
            else if(fa*fc<0){
                b=c;
            }
        }
        cout<<"\n**************************\nthe root is "<<c<<endl;


    cout<<"Number of iterations = "<<i<<endl;
    cout<<"\n**************************\n";

    return i;
}

int Newton(double a){

    double c,e,fa,fb,fc;
    int i=0;
    fc=100;
    e =pow(10,-6);
    cout<<" \n Newton-Raphson Method\n\n";


        while(fabs(fc)>=e){
                if (df(a)==0){
                        cout<<"Sorry, the method has failed!!!\n";
                        goto lbl_end;
                }

            c=a-(f(a)/df(a));

            fa=f(a);
            fc=f(c);
            cout<<"a = "<<a<<" c ="<<c<< " f(c) = "<<fc<<"  The relative error = "<<(c-a)/c<<endl;
            a=c;
            i+=1;
            if(fc==0){
                cout<<"\n**************************\nthe true root is "<<c<<endl;
                cout<<"\n**************************\n";
                break;
            }

        }
        cout<<"\n**************************\nthe root is "<<c<<endl;
        lbl_end:
        cout<<"The number of iterations = "<<i<<endl;
        cout<<"\n**************************\n";

        return i;

}

int main()
{
    cout.precision(6);
    cout.setf(ios::fixed);

    double a,b;
    int B,N;

     //Taking the starting points from the user
    lbl:
    cout << "Enter the value of a\n";
    cin >> a;
    cout << "Enter the value of b\n";
    cin >> b;

    if( f(a)*f(b)>0) {

            cout <<"Enter true values of a and b.\n";
            goto lbl;
        }

    //calling the methods functions
    B = Bisection(a,b);
    N = Newton(a);

    //comparing the number of iteration for both methods
    if (B>N)
        {cout<<"\nThe faster method is Newton-Raphson\n**********************************************\n";}
    else if (B<N)
        {cout<<"\nThe faster method is Bisection\n**********************************************\n";}
    else
        {cout<<"\nThe two methods made the same number of iterations\n**********************************************\n";}
    /*
    int choice;
    lbl_choice:
    cout<<"Choose the method:\n 1)Bisection.\n 2)Newton-Raphson.\n";
    cin>> choice;

    switch (choice){
        case 1:
            Bisection();
            break;
        case 2:
            Newton();
            break;
        default:
            cout<<"Wrong choice! Please try again.\n";
            goto lbl_choice;
    }*/


    return 0;
}
