//3121. 统计特殊字母的数量 II
class Solution {
public:
    int numberOfSpecialChars(string word) {
        //map:a映射/对应b
        //set:1元素去重 2排序 3判断元素是否出现过

        set<char> st;
        set<int> st2;
        vector<int> arr(26,0);
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a'&&word[i]<='z'){//小写
               st.insert(word[i]);

               if(arr[word[i]-'a']>0){
                cnt--;
                arr[word[i]-'a']--;
                }
            }else{ 
                if(st.find(word[i]+('a'-'A'))!=st.end()&&arr[word[i]-'A']==0&&st2.find(word[i]-'A')==st2.end()){
                cnt++;
                arr[word[i]-'A']++;
            }
               if(st2.find(word[i]-'A')==st2.end()){
                st2.insert(word[i]-'A');
               }
            }
        }
        return cnt;
    }
};
