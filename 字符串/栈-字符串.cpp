//682. 棒球比赛
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int len=operations.size();
        for(int i=0;i<len;i++){
            if(operations[i]=="C") stk.pop();
            else if(operations[i]=="D"){
                int q=stk.top();
                stk.push(q*2);
            }
            else if(operations[i]=="+"){
                int q1=stk.top();
                stk.pop();
                int q2=stk.top();
                stk.push(q1);
                stk.push(q1+q2);
            }else{
                int q=stoi(operations[i]);
                stk.push(q);
            }
        }
        int sum=0;
        while(!stk.empty()){
            sum+=stk.top();
            stk.pop();
        }
        return sum;
    }
};
