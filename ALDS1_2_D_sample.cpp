#include <cstdio>
#include <algorithm>
using namespace std;

#define D_ARRAY_SIZE 10 // 間隔の数

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
    for(int i=0 ; i<D_ARRAY_SIZE ; i++){
        if(n > distance[i]){
            count += insertionSort(x, n, distance[i]);
        }
    }
    return count;
}

// 間隔の値を格納する配列を生成
void generateDistance(int *distance){
    int h = 1;
    for(int i=D_ARRAY_SIZE-1 ; i>=0 ; i--){
        distance[i] = h;
        h = 3 * h + 1;
    }
}

int main(int argc, char const *argv[]) {
    int distance[D_ARRAY_SIZE];
    int x[1000000], n, count;

    // 要素数と数列の入力
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &x[i]);
    }

    // 間隔の値を生成
    generateDistance(distance);

    count = shellSort(x, distance, n);
    for(int i=0 ; i<D_ARRAY_SIZE ; i++){
        if(n > distance[i]){
            // 間隔の数を出力
            printf("%d\n", D_ARRAY_SIZE-i);
            // 間隔の値を出力
            for(int j=i ; j<D_ARRAY_SIZE ; j++){
                printf("%d", distance[j]);
                if(j != D_ARRAY_SIZE-1) printf(" ");
                else printf("\n");
            }
            break;
        }
        // 入力数列の要素が1つだけのとき...
        else if(i == D_ARRAY_SIZE-1) printf("1\n1\n");
    }
    // 交換回数を出力
    printf("%d\n", count);
    // ソート済みの数列を出力
    for(int i=0 ; i<n ; i++){
        printf("%d\n", x[i]);
    }

    return 0;
}
