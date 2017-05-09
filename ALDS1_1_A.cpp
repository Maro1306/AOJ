#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int x[100], n;

    // 要素数と数列の入力
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &x[i]);
    }
    for(int i=0 ; i<n-1 ; i++){
        printf("%d ", x[i]);
    }
    printf("%d\n", x[n-1]);

    // 挿入ソート
    for(int i=1 ; i<n ; i++){
        for(int j=i-1 ; j>=0 ; j--){
            if(x[j] > x[j+1]) swap(x[j], x[j+1]);
            else break;
        }
        for(int j=0 ; j<n-1 ; j++){
            printf("%d ", x[j]);
        }
        printf("%d\n", x[n-1]);
    }

    return 0;
}
