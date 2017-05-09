#include <cstdio>
#include <queue>
using namespace std;

struct PROCESS{
    char name[11];
    int time;
};

int main(int argc, char const *argv[]) {
    int n, q, total_time = 0;
    queue<PROCESS> process_queue;
    PROCESS process;

    scanf("%d %d", &n, &q);
    for(int i=0 ; i<n ; i++){
        scanf("%s %d", process.name, &process.time);
        process_queue.push(process);
    }

    // キューが空になったら終了
    while(!process_queue.empty()){
        process = process_queue.front();
        // 処理時間がクォンタム以下の場合
        if(process.time <= q){
            total_time += process.time;
            printf("%s %d\n", process.name, total_time);
        }
        // 処理時間がクォンタムより長い場合
        else{
            total_time += q;
            process.time -= q;
            process_queue.push(process);
        }
        process_queue.pop(); // 先頭要素を削除
    }

    return 0;
}
