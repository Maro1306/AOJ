#include <cstdio>
#include <algorithm>
using namespace std;

// 一定間隔にある数字のみに対して挿入ソートを行う
int insertionSort(int *x, int n, int distance){
    // 要素数より間隔が広ければ何もしない
    if(n <= distance) return 0;

    int count = 0;
    for(int i=distance ; i<n ; i++){
        int j, target = x[i];
        for(j=i-distance ; j>=0 ; j-=distance){
            // 小さい方の値を右にずらしていく
            if(x[j] > target){
                x[j+distance] = x[j];
                count++;
            }
            else break;
        }
        x[j+distance] = target;
    }
    return count;
}

// シェルソート
int shellSort(int *x, int *distance, int n){
    int count = 0;
    for(int i=0 ; i<5 ; i++){
        count += insertionSort(x, n, distance[i]);
    }
    return count;
}

int main(int argc, char const *argv[]) {
//    int distance[5] = {121, 40, 13, 4, 1};
    int distance[5] = {100, 50, 10, 5, 1};
    int x[1000000], n, count;

    // 要素数と数列の入力
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &x[i]);
    }

    count = shellSort(x, distance, n);
    for(int i=0 ; i<5 ; i++){
        if(n > distance[i]){
            printf("%d\n", 5-i);
            for(int j=i ; j<5 ; j++){
                printf("%d", distance[j]);
                if(j != 4) printf(" ");
                else printf("\n");
            }
            break;
        }
        // 入力数列の要素が1つだけのとき...
        else if(i == 4) printf("1\n1\n");
    }

    printf("%d\n", count);
    for(int i=0 ; i<n ; i++){
        printf("%d\n", x[i]);
    }

    return 0;
}
