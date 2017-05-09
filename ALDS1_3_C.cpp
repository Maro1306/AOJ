#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

void deleteElement(list<int> &intList, int target){
    list<int>::iterator itr;
    for(itr=intList.begin() ; itr!=intList.end() ; itr++){
        if(*itr == target){
            intList.erase(itr);
            break;
        }
    }
    return;
}

int main(int argc, char const *argv[]) {
    int n, inputInt;
    char command[12];
    list<int> intList;

    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%s", command);
        // リストの先頭に挿入
        if(strncmp(command, "insert", 6) == 0){
            scanf("%d", &inputInt);
            intList.push_front(inputInt);
        }
        // 先頭を削除
        else if(strncmp(command, "deleteFirst", 11) == 0){
            intList.pop_front();
        }
        // 末尾を削除
        else if(strncmp(command, "deleteLast", 10) == 0){
            intList.pop_back();
        }
        // 特定の要素を削除
        else if(strncmp(command, "delete", 6) == 0){
            scanf("%d", &inputInt);
            deleteElement(intList, inputInt);
        }
        else printf("無効なコマンド\n");
    }

    list<int>::iterator itr = intList.begin();
    printf("%d", *itr++);
    for( ; itr!=intList.end() ; itr++){
        printf(" %d", *itr);
    }
    printf("\n");

    return 0;
}
