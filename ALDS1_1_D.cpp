#include <cstdio>

int main(int argc, char const *argv[]) {

    bool decrease_flag = true;
    int n;
    int current, previous;
    int min, max = 0;
    const int DIFF_INIT = 1;
    int diff = DIFF_INIT;

    scanf("%d", &n);
    scanf("%d", &current);
    min = current;
    for(int i=1 ; i<n; i++){
        previous = current;
        scanf("%d", &current);

        // 最大値最小値更新
        if(current < min){
            min = current;
            if(max > 0) max = 0;
        }
        else if(current > max) max = current;

        // 利益更新
        // 傾きが正のとき
        if(current > previous){
            decrease_flag = false;
            if((max-min) > diff) diff = max - min;
        }
        // 傾きが"ずっと"負のとき
        else if(decrease_flag){
            if((diff == DIFF_INIT) || (current-previous) > diff) diff = current - previous;
        }
    }

    printf("%d\n", diff);
    return 0;
}
