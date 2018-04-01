// L2-1 分而治之
// Language: C++

#include <iostream>

using namespace std;

bool dfs(int src,
        int start[], int end[], int road_count, 
        int attack_city[], int attack_count){
    for(int i = 0;i < attack_count;i++){
        if(attack_city[i] == src){
            return false;
        }
    }

    for(int i = 0;i < road_count;i++){
        int road_src = start[i], road_dest = end[i];
        if(road_src == src){
            bool found = false;
            for(int j = 0;j < attack_count;j++){
                if(attack_city[j] == road_dest){
                    found = true;
                    break;
                }
            }
            if(!found){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int city_count, road_count;
    cin >> city_count >> road_count;

    road_count *= 2;
    int start[road_count], end[road_count];

    for(int i = 0;i < road_count;i+=2){
        int src, dest;
        cin >> src >> dest;
        start[i] = src; end[i] = dest;
        start[i+1] = dest; end[i+1] = src;
    }

    int query_count;
    cin >> query_count;
    while(query_count--){
        int attack_count;
        cin >> attack_count;
        int attack_city[attack_count];

        for(int i = 0;i < attack_count;i++){
            cin >> attack_city[i];
        }

        bool result = false;
        for(int i = 0;i < city_count;i++){
            result = dfs(i+1, start, end, road_count,
                    attack_city, attack_count);
            if(result){
                break;
            }
        }
        if(result){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }

    return 0;
}
