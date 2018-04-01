// L2-1 分而治之
// Language: C++

#include <iostream>
#include <cstring>

using namespace std;

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
        bool city_attcked[city_count + 1];
        memset(city_attcked, 0, sizeof(city_attcked));

        for(int i = 0;i < attack_count;i++){
            int attack_city_id;
            cin >> attack_city_id;
            city_attcked[attack_city_id] = true;
        }

        bool result = true;
        for(int i = 0;i < road_count;i++){
            int road_src = start[i], road_dest = end[i];
            if(city_attcked[road_src] || city_attcked[road_dest]){
                continue;
            }
            result = false;
            break;
        }

        if(!result){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }

    return 0;
}
