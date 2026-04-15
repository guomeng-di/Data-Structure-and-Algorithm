//c++语法:
//1结构体
//2结构体的sort函数
//3scanf不能读string
#include <bits/stdc++.h>
using namespace std;
typedef struct{
    string date;
    string time;
    int timu;
    int score=-1;
}Stu;
int n,m;
bool cmp(const Stu& a,const Stu& b){
    return a.time<b.time;
}
int main(){
    cin>>n>>m;
    vector<Stu> stu(m);
    for(int i=0;i<n;i++){
        string s1,s2;
        int d1,d2;
        cin>>s1>>s2>>d1>>d2;
        if(stu[d1-1].score<d2){
            stu[d1-1].date=s1;
            stu[d1-1].time=s2;
            stu[d1-1].timu=d1;
            stu[d1-1].score=d2;
        }
    }
    sort(stu.begin(),stu.end(),cmp);
    for(int i=0;i<m;i++){
        if(stu[i].score!=-1){
            cout<<stu[i].date<<" "<<stu[i].time<<" "<<stu[i].timu<<" "<<stu[i].score<<endl;
        }
    }
    return 0;
}