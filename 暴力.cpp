//枚举:
//44033. 门牌制作
#include <bits/stdc++.h>
using namespace std;
int ans=1;
int jisuan(int i){
    int res=0;
    while(i){
        if(i%10==2) res++;
        i/=10;
    }return res;
}
int main(){
    for(int i=12;i<=2020;i++){
        ans+=jisuan(i);
    }
    cout<<ans;
    return 0;
}
//44576. 卡片
#include <bits/stdc++.h>
using namespace std;
int arr[]={2021,2021,2021,2021,2021,2021,2021,2021,2021,2021};
void xiaochu(int x){
    if(x==0) arr[0]--;
    while(x){
        arr[x%10]--;
        x/=10;
    }return ;
}
int main(){
    for(int j=1;;j++){
        xiaochu(j);
        for(int i=0;i<=9;i++){
            if(arr[i]<0) {cout<<j-1;return 0;}
        }
    }
    return 0;
}

//模拟:
//43820. 回文日期
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s_y,s_m,s_d,e_y,e_m,e_d;
int ans=0;
int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool runnian(int y){
    if((y%4==0&&y%100!=0)||y%400==0) return 1;
    return 0;
}
bool huiwen(ll sum){
    ll a1=sum;
    ll a2=0;
    while(sum){
        a2=a2*10+sum%10;
        sum/=10;
    }
    if(a1==a2) return 1;
    return 0;
}
int main() {
    scanf("%4d%02d%02d",&s_y,&s_m,&s_d);
    scanf("%4d%02d%02d",&e_y,&e_m,&e_d);
    for(int i=s_y;i<=e_y;i++){
        for(int j=1;j<=12;j++){
            if(i==s_y&&j<s_m) continue;
            int mon_day=arr[j];
            if(j==2&&runnian(i)) mon_day++;
         for(int d=1;d<=mon_day;d++){
             if(i==s_y&&j==s_m&&d<s_d) continue;
             if(i==e_y&&j==e_m&&d==e_d){
                 if(huiwen(i*10000+j*100+d))
                 {
                     ans++;
                     cout<<ans;
                     return 0;
                 }
             }
                ll sum=i*10000+j*100+d;
                if(huiwen(sum)) ans++;
            }
        }
    }cout<<ans;
    return 0;
}
//递推:
//45668. Fibonacci数列
//法一:递推
#include <bits/stdc++.h>
using namespace std;
int n;
long long fibonacci(int n){
    if(n==1||n==2) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}
//法二:迭代
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    long long sum=0;
    long long a=1;
    long long b=1;
    if(n==1||n==2) sum=1;
    
    for(int i=3;i<=n;i++){
        sum=a+b;
        long long temp=sum;
        a=b;
        b=temp;
    }cout<<sum;
    return 0;
}
//44665. 糊涂人寄信
// //思路:
// 1：当第x封信装进了第y个信封时（y有n-1个选择），第y封信也恰好装进了第x个信封。此时还有n-2封信需要装错。（n-1）*x[n-2]

// 2：当第x封信装进了第y个信封时（y有n-1个选择），第y封信没有恰好装进了第x个信封。此时还有n-1封信需要装错。(n-1)*x[n-1]

// 总加起来就是 sum=（n-1）*x[n-2]+（n-1）*x[n-1]；

#include <bits/stdc++.h>
using namespace std;
int n;
long long fabonacci(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return (n-1)*fabonacci(n-1)+(n-1)*fabonacci(n-2);
}
int main(){
    while(cin>>n){
    cout<<fabonacci(n)<<endl;}
    return 0;
}

