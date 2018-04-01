// L2-3 名人堂与代金券
// Language: C++

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string email;
    int mark;
};

bool comp(Student a, Student b){
    if(a.mark == b.mark){
        return a.email < b.email;
    }
    return a.mark > b.mark;
}

int main(){
    int student_count, division, min_rank;
    cin >> student_count >> division >> min_rank;

    vector<Student> students;
    int total_sent = 0;
    for(int i = 0;i < student_count;i++){
        Student s;
        cin >> s.email >> s.mark;
        students.push_back(s);

        if(s.mark >= 60 && s.mark < division){
            total_sent += 20;
        }else if(s.mark >= division && s.mark <= 100){
            total_sent += 50;
        }
    }

    cout << total_sent << endl;

    sort(students.begin(), students.end(), comp);

    int current_rank = 1, current_rank_count = 0;
    int current_mark = -1;
    for(Student s : students){
        if(s.mark != current_mark){
            current_mark = s.mark;
            current_rank += current_rank_count;
            current_rank_count = 0;
            if(current_rank > min_rank){
                break;
            }
        }
        cout << current_rank << " " << s.email << " " << s.mark << endl;
        current_rank_count++;
    }

    return 0;
}
