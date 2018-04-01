// L2-2 小字辈
// Language: C++

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int people_count;
    cin >> people_count;

    int parents[people_count + 1];
    int index = 0;
    for(int i = 1;i < people_count + 1;i++){
        cin >> parents[i];
        if(parents[i] == -1){
            index = i;
        }
    }

    queue<int> q;
    queue<int> level;
    queue<int> last_queue;

    q.push(index);
    level.push(1);

    int last_level = 0;
    while(!q.empty()){
        int current_index = q.front(), current_level = level.front();
        if(current_level != last_level){
            last_queue = q;
            last_level = current_level;
        }
        q.pop(); level.pop();

        for(int i = 1;i < people_count + 1;i++){
            if(parents[i] == current_index){
                q.push(i); level.push(current_level + 1);
            }
        }
    }

    vector<int> results;
    while(!last_queue.empty()){
        results.push_back(last_queue.front());
        last_queue.pop();
    }
    sort(results.begin(), results.end());
    cout << last_level << endl;

    bool first = true;
    for(int i : results){
        if(!first){
            cout << " ";
        }
        cout << i;
        first = false;
    }

    return 0;
}
