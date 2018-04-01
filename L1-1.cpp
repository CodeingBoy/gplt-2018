// L1-1 天梯赛座位分配
// Language: C++

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int school_count;
    cin >> school_count;

    int member_count[school_count];
    for(int i = 0;i < school_count;i++){
        cin >> member_count[i];
        member_count[i] *= 10;
    }

    bool complete[school_count];
    memset(complete, 0, sizeof(complete));

    vector<int> ids[school_count];
    int next_pos = 1;
    int complete_stat = 0;
    int last_school = -1;
    while(true){
        for(int i = 0;i < school_count;i++){
            if(ids[i].size() >= member_count[i]){
                if(!complete[i]){
                    complete[i] = true;
                    complete_stat++;
                }
                continue;
            }
            if(last_school == i){
                next_pos++;
            }
            ids[i].push_back(next_pos);
            next_pos++;
            last_school = i;
        }
        if(complete_stat == school_count){
            break;
        }
    }

    for(int i = 0;i < school_count;i++){
        vector<int> &id_list = ids[i];
        cout << "#" << (i + 1) << endl;
        bool first = true;
        for(int j = 0;j < id_list.size();j++){
            if(!first){
                cout << " ";
            }
            cout << id_list[j];
            first = false;
            if((j + 1) % 10 == 0){
                cout << endl;
                first = true;
            }
        }
        if(!first){
            cout << endl;
        }
    }

    return 0;
}
