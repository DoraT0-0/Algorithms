#include <iostream>
#include <cmath>
using namespace std;




void InOutFirstFun(double *a){
    cout << "(1/(a^1/2 + (a+1)^1/2) + 1/(a^1/2 - (a-1)^1/2))/(1+((a+1)/(a-1))^1/2)" << endl;
    cout << "Input a (double):";
    cin >> *a;
}

void FirstFun(void* result){
    double a;
    InOutFirstFun(&a);
    if(a <= 1){
        *static_cast<double*>(result) = 0;
    }
    else{
        *static_cast<double*>(result) = 
        ((1/(pow(a, 0.5) + pow(a+1, 0.5)))+(1/(pow(a, 0.5) - pow(a-1, 0.5))))
        / 
        (1+pow(a+1 / a-1, 0.5));
    }
}

void InOutSecondFun(float *x, float *a){
    cout << "((x * (x^2-a^2)^-1/2 + 1)/(a* (x-a)^-1/2 + (x-a)^-1/2))/(((a^2 * (x+a)^1/2)/(x-(x^2-a^2)^1/2))+(1/(x^2-a*x)))" << endl;
    cout << "Input x (float):";
    cin >> *x;
    cout << "Input a (float):";
    cin >> *a;
}

void SecondFun(void* result){
    float x;
    float a;
    InOutSecondFun(&x, &a);
    if(x+a <= 0 || (a == 0 && x == 0)){
        *static_cast<double*>(result) = 0;
    }
    else{
        *static_cast<double*>(result) = 
            (
                (x*pow((pow(x, 2) - pow(a, 2)), -0.5) + 1)
                /
                (a*pow(x-a,-0.5)+pow(x-a, 0.5))
            )
            /
            (
                (
                    (pow(a, 2)*pow(x+a,0.5))
                    /
                    (x-pow(pow(x, 2)-pow(a, 2), 0.5))
                )
                +
                (
                    1
                    /
                    (pow(x, 2) - a*x)
                )
            );
    }
}

void InOutThreeFun(int *m, int *n, double *a){
    cout << "((a^1/m - a^1/n)^2 * 4*a^(m+n/m*n))/( (a^2/m - a^2/n)*((a^m+1 + (a^n+1)^1/n)^1/m))" << endl;
    cout << "Input m (int):";
    cin >> *m;
    cout << "Input n (int):";
    cin >> *n;
    cout << "Input a (double):";
    cin >> *a;
}

void ThreeFun(void* result){
    double a;
    int m,n;
    InOutThreeFun(&m, &n, &a);
    if((m == n) || (m == 0 && n == 0) || a <= 1){
        *static_cast<double*>(result) = 0;
    }
    else{
        *static_cast<double*>(result) = 
        (
            pow(pow(a, (double)1 / (double)m) - pow(a, (double)1 / (double)n), 2) * 4 * pow(a, (double)m+n / (double)m*n)
        )
        /
        (
            (
                pow(a, (double) 2 / (double) m) - pow(a, (double) 2 / (double) n)
            )
            *
            (
                pow(
                    pow(a, m+1)
                    +
                    pow(pow(a, n+1), (double) 1 / (double) n),
                    (double) 1 / (double) m
                )
            )
        );
    }
}

void print_result(void* ptr_result, void (*ptrFun[])(void*), int num){
    ptrFun[num](ptr_result);
    double* result_ = static_cast<double*>(ptr_result);
    cout << "Result: " << *result_ << endl;
}

int main(){
    double result;
    void* ptr_result = &result;
    void(*ptrFun[3])(void*) = {FirstFun, SecondFun, ThreeFun};

    int num;
    cout << "Select 0 or 1 or 2: ";
    cin >> num;
    switch (num)
    {
    case 0:
    {
        print_result(ptr_result, ptrFun, num);
        break;
    }
    case 1: {
        print_result(ptr_result, ptrFun, num);
        break;
    }
    case 2:{
        print_result(ptr_result, ptrFun, num);
        break;
    }
    default:
    {
        cout << "error";
        break;
    }
    }

    system("pause");
}