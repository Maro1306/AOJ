#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

bool isOperator(char c){
    if((c == '+') || (c == '-') || (c == '*')) return true;
    else return false;
}

int operation(char ope, int x, int y){
    switch (ope) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        // dafault???
    }
}

int main(int argc, char const *argv[]) {
    char str[8];
    stack<int> operand; // オペランドを格納するスタック

    while(scanf("%s", str) != EOF){
        // 演算子が来た場合
        if(isOperator(str[0])){
            int y = operand.top();
            operand.pop();
            int x = operand.top();
            operand.pop();
            operand.push(operation(str[0], x, y));
        }
        // 値が来た場合
        else{
            operand.push(atoi(str));
        }
    }
    printf("%d\n", operand.top());

    return 0;
}
