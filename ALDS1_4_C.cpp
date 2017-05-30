#include <cstdio>
#include <list>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    list<string> strList;
    list<bool> result;
    string command;
    string inputStr;


    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> command >> inputStr;
        // insertコマンド
        if(command[0] == 'i'){
            strList.push_back(inputStr);
        }
        // findコマンド
        else if(command[0] == 'f'){
            list<string>::iterator itr = strList.begin();
            for( ; itr!=strList.end() ; itr++){
                if(*itr == inputStr){
                    result.push_back(true);
                    break;
                }
            }
            if(itr == strList.end()) result.push_back(false);
        }
    }

    list<bool>::iterator itr = result.begin();
    for( ; itr!=result.end() ; itr++){
        if(*itr) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
