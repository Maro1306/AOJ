#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct{
    char symbol;
    int number;
} TRUMP;

void bubble_sort(TRUMP *x, int n){
    bool swap_flag = true;
    for(int j=0 ; swap_flag ; j++){
        swap_flag = false;
        for(int i=n-1 ; i>j ; i--){
            if(x[i-1].number > x[i].number){
                swap(x[i-1], x[i]);
                swap_flag = true;
            }
        }
    }
}

void selection_sort(TRUMP *x, int n){
    int min;
    for(int i=0 ; i<n-1 ; i++){
        min = i;
        for(int j=i+1 ; j<n ; j++){
            if(x[j].number < x[min].number) min = j;
        }
        // 初期位置が最小値であれば何もしない
        if(min != i) swap(x[i], x[min]);
    }
}

bool is_stable(TRUMP *x, TRUMP *y, int n){
    for(int i=0 ; i<n ; i++){
        if(x[i].symbol != y[i].symbol){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int n;
    char tmp[3]; // カードの値取得用
    bool stable_flag;
    TRUMP x_b[36], x_s[36];

    // 要素数と数列の入力
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%s", tmp);
        x_b[i].symbol = tmp[0];
        x_b[i].number = (int)(tmp[1] - '0');
    }
    memcpy(x_s, x_b, sizeof(x_b));

    // バブルソート
    bubble_sort(x_b, n);
    for(int i=0 ; i<n-1 ; i++){
        printf("%c%d ", x_b[i].symbol, x_b[i].number);
    }
    printf("%c%d\n", x_b[n-1].symbol, x_b[n-1].number);
    printf("Stable\n");

    // 選択ソート
    selection_sort(x_s, n);
    for(int i=0 ; i<n-1 ; i++){
        printf("%c%d ", x_s[i].symbol, x_s[i].number);
    }
    printf("%c%d\n", x_s[n-1].symbol, x_s[n-1].number);

    // 絶対安定のバブルソートの結果と比較
    bool stable_flag = is_stable(x_b, x_s, n);
    if(stable_flag) printf("Stable\n");
    else printf("Not stable\n");

    return 0;
}
