#include <cstdio>
#include <stack>
#include <list>
using namespace std;

// 水たまりの情報を格納する構造体
struct PUDDLE{
    int begin; // 開始位置
    int area; // 面積
};

int main(int argc, char const *argv[]) {
    int totalArea = 0; // 水たまりの総面積
    char crossSection[20001]; // 断面図
    stack<int> downhill; // 下りの開始位置
    list<PUDDLE> puddleList; // 水たまりの位置と面積

    scanf("%s", crossSection);
    for(int current=0 ; crossSection[current]!='\0' ; current++){
        switch (crossSection[current]) {
            case '\\':
                downhill.push(current);
                break;
            case '/' :
                if(downhill.empty()) break;
                // 現在の水たまりの面積を求める
                PUDDLE currentPuddle;
                currentPuddle.begin = downhill.top();
                downhill.pop();
                currentPuddle.area = current - currentPuddle.begin;
                totalArea += currentPuddle.area; // 総面積を更新
                // 間に水たまりがあれば結合する
                while(!puddleList.empty() && currentPuddle.begin<puddleList.back().begin){
                    currentPuddle.area += puddleList.back().area;
                    puddleList.pop_back();
                }
                puddleList.push_back(currentPuddle);
                break;
            case '_' : break; // 何もしない
        }
    }

    printf("%d\n", totalArea);
    printf("%zu", puddleList.size());
    list<PUDDLE>::iterator itr = puddleList.begin();
    for( ; itr!=puddleList.end() ; itr++){
        printf(" %d", itr->area);
    }
    printf("\n");

    return 0;
}
