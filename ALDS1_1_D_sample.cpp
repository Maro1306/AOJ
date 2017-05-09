#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, current;
    int maxv = -2000000000;
    int minv;

    scanf("%d", &n);

    scanf("%d", &current);
    minv = current;

    for(int i=1 ; i<n ; i++){
        scanf("%d", &current);
        // 現在値と最小値との差が大きければ利益更新
        maxv = max(maxv, current-minv);
        // 現在値が最小値より小さければ最小値更新
        minv = min(minv, current);
    }

    printf("%d\n", maxv);
    return 0;
}
