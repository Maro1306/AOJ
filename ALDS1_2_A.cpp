#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int x[100], n;
    bool swap_flag = true;
    int count = 0;

    // 要素数と数列の入力
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &x[i]);
    }

    // バブルソート
    while(swap_flag){
        swap_flag = false;
        for(int i=n-1 ; i>0 ; i--){
            if(x[i-1] > x[i]){
                swap(x[i-1], x[i]);
                swap_flag = true;
                count++;
            }
        }
    }

    for(int i=0 ; i<n-1 ; i++){
        printf("%d ", x[i]);
    }
    printf("%d\n", x[n-1]);
    printf("%d\n", count);

    return 0;
}
