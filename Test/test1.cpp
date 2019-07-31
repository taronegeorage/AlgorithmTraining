#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct JOB {
    int di;
    int pi;
} jobs[5];

bool cmp(JOB a,JOB b){
    if(a.di==b.di){
        return a.pi>b.pi;
    }
    return a.di < b.di;
}

struct STUDENT {
    int ai;
    int id;
} stu[5];

bool cmp2(STUDENT a,STUDENT b){
    return a.ai<b.ai;
}

int main() {
    for(int i = 0; i < 5; i++) {
        scanf("%d", &stu[i].ai);
        stu[i].id = i;
    }
    sort(stu, stu+5, cmp2);
    for(int i = 0; i < 5; i++) 
	cout << stu[i].ai << " " << stu[i].id << endl;
    return 0;
}
