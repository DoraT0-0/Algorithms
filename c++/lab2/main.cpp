#include <iostream>
#include <cmath>
using namespace std;




void InOutFirstFun(int *x){
    cout << "(((2^(2/3)+27*y^(3/5))/(2^(1/2)+3*y^(1/10)) + 3*(32*y^2 - 2)^(1/10)) * 3^-2)^5" << endl;
    cout << "Input y:";
    cin >> *x;
}

void FirstFun(void* result){
    int y;
    InOutFirstFun(&y);
    if(y < 0){
        *static_cast<double*>(result) = 0;
    }
    else{
        *static_cast<double*>(result) = pow(
        (
            (
                (
                    double(pow(2,(double)2/(double)3) + 27*pow(y,(double)3/(double)5))/double(sqrt(2)+3*pow(y, (double)1/(double)5))
                )
                +
                (
                    3*pow(32*pow(y,2)-2, double(1)/double(16))
                )
            )
            *pow(3,-2)
        ),5);
    }
}

void InOutSecondFun(float *x, int *y){
    cout << "(((x^2-y^2)*(x^(1/3)+y^(1/3))/(x^(5/3)+(x^2*y^3)^(1/3)-(x^3*y^2)^(1/3)-y^(5/3)))-((x*y)^(1/3)+y^2/3))" << endl;
    cout << "Input x:";
    cin >> *x;
    cout << "Input y:";
    cin >> *y;
}

void SecondFun(void* result){
    float x;
    int y;
    InOutSecondFun(&x, &y);
    if(y <= 0 and x <= 0){
        *static_cast<double*>(result) = 0;
    }
    else{
        *static_cast<double*>(result) = 
            (
                ((pow(x,2) - pow(y, 2)) * (pow(x, (double)1/(double)3) + pow(y, (double)1/(double)3))
                /
                (pow(x, (double)5/(double)3) + pow(pow(x,2)*pow(y,3), double(1)/(double)3) - pow(pow(x,3)*pow(y,2), double(1)/(double)3) - pow(y, (double)5/(double)3))
            )
            -
            (
                pow(x*y, double(1)/double(3)) + pow(y, (double)2/(double)3)
            )
            );
    }
}

void InOutThreeFun(double *a, double *b, double *c){
    cout << "(1/(b*(a*b*c+a+c) - 1/(a+(1/(b+1/c))) : 1/(a+(1/b)))" << endl;
    cout << "Input a:";
    cin >> *a;
    cout << "Input b:";
    cin >> *b;
    cout << "Input c:";
    cin >> *c;
}

void ThreeFun(void* result){
    double a,b,c;
    InOutThreeFun(&a, &b, &c);
    if(b == 0 and c == 0){
        *static_cast<double*>(result) = 0;
    }
    else{
        *static_cast<double*>(result) = (
            (
                (1/(b*(a*b*c)+a+c))
                -
                (1/(a+(1/(b+(1/c)))))
            )
            /
            (1/(a+(1/b)))
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