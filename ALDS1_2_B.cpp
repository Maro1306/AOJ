#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int x[100], n, min;
    int count = 0;

    // 要素数と数列の入力
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &x[i]);
    }

    // 選択ソート
    for(int i=0 ; i<n-1 ; i++){
        min = i;
        for(int j=i+1 ; j<n ; j++){
            if(x[j] < x[min]) min = j;
        }
        // 初期位置が最小値であれば何もしない
        if(min != i){
            swap(x[i], x[min]);
            count++;
        }
    }

    for(int i=0 ; i<n-1 ; i++){
        printf("%d ", x[i]);
    }
    printf("%d\n", x[n-1]);
    printf("%d\n", count);

    return 0;
}
