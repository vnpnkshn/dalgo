#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

bool IsOperator(char ch){
    if(ch == '/' || ch == '*' || ch == '+' || ch == '-'){
        return true;
    }
    return false;
}

bool IsNumericDigit(char ch){
    if(ch >= '0' and ch <= '9') return true;
    return false;
}

int PerformCalc(char operate, int op1, int op2){
    switch(operate){
        case '/':
            return op1 / op2;
            break;

        case '*':
            return op1 * op2;
            break;

        case '+':
            return op1 + op2;
            break;

        case '-':
            return op1 - op2;
            break;

        default:
            return 0;
            break;
    }
}

void EvaluatePostfix(string expr){
    for(int i=0; i < expr.length(); i++){
        if(expr[i] == ' ' || expr[i] == ',') continue;

        if(IsOperator(expr[i])){
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            s.push(PerformCalc(expr[i], op1, op2));
        }
        else {
            int operand = 0;
            while(i < expr.length() && IsNumericDigit(expr[i])){
                operand = (operand * 10) + ( expr[i] - '0');
                i++;
            }
            s.push(operand);
            i--;
        }
    }
    cout << s.top() << endl;
}

void EvaluatePrefix(string expr){
}

int main(){
    string expr;
    cout << "Enter an expression to evaluate: \n" << "> ";
    getline(cin, expr);
    EvaluatePostfix(expr);
}