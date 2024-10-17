#include <iostream>
using namespace std;




void InOutFirstFun(int *x){
    cout << "(((2^(2/3)+27*y^(3/5))/(2^(1/2)+3*y^(1/10)) + 3*(32*y^2 - 2)^(1/10)) * 3^-2)^5" << endl;
    cout << "Введите аргумент:";
    cin >> *x;
}

void FirstFun(int* result){
    int y;
    InOutFirstFun(&y);
    cout << endl << y << endl;
    if(y < 0 and typeid(y).name() == typeid(int).name())
        *result = 0;
    else{
        *result = (((2^(2/3)+27*y^(3/5))/(2^(1/2)+3*y^(1/10)) + 3*(32*y^2 - 2)^(1/10)) * 3^-2)^5;
    }
}

void InOutSecondFun(float *x, int *y){
    cout << "(((x^2-y^2)*(x^(1/3)+y^(1/3))/(x^(5/3)+(x^2*y^3)^(1/3)-(x^3*y^2)^(1/3)-y^(5/3)))-((x*y)^(1/3)+y^2/3))" << endl;
    cout << "Введите аргумент x:";
    cin >> *x;
    cout << "Введите аргумент y:";
    cin >> *y;
}

void SecondFun(void* result){
    float x;
    int y;
    InOutSecondFun(&x, &y);
    float* result_ = static_cast<float*>(result);
    // float* xptr = static_cast<float*>(&x);
    // int* yptr = static_cast<int*>(&y);
    cout << endl << x << endl << y << endl;
    if(y <= 0 and x <= 0){
        *result_ = 0;
        result = result_;
    }
    else{

        *result_ = x * y;
        result = result_;
    }
}



int main(){
    void* result;
    cout << result << endl;
    SecondFun(&result);
    cout << (float*)result << endl;
    system("pause");
}