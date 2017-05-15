#include <cstdio>

int main(int argc, char const *argv[]) {
    int n, q, target;
    int findCount = 0; // 見つかった数の個数
    int inputSequence[100000];

    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%d", &inputSequence[i]);
    }

    scanf("%d", &q);
    for(int i=0 ; i<q ; i++){
        scanf("%d", &target);
        int begin = 0, end = n-1;
        do{
            int current = (begin+end)/2;
            if(inputSequence[current] == target){
                findCount++;
                break;
            }
            // 真ん中より大きい→右を調べる
            else if(inputSequence[current] < target){
                begin = current + 1;
            }
            // 真ん中より小さい→左を調べる
            else if(inputSequence[current] > target){
                end = current - 1;
            }
        } while(begin <= end); // 先頭と末尾が入れ替わったら終了
    }

    printf("%d\n", findCount);
    return 0;
}
