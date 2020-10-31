class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        // 第一个移 shifts[0]+shifts[1]+...+shifts[n-1]
        // 第二个移 shifts[1]+shifts[2]+...+shifts[n-1]
        // ...
        // 最后一个移 shifts[n-1]
        // 后面的不变
        
        if(S.empty() || shifts.empty())
            return S;
        
        // shifts可能高达10^9, 要 %26
        for(int i=shifts.size()-1; i>=0; i--){
            if(i == shifts.size()-1){
                // 第一个
                shifts[i] %= 26;
            }else{
                shifts[i] = (shifts[i]%26+shifts[i+1])%26;
            }
        }
        
        // shifts已更新
        string ans;
        int length = min(S.length(), shifts.size());
        int i = 0;
        for(i=0; i<length; i++){
            char cur_char = S.at(i);
            int asc_val = cur_char+shifts[i];
            char char_new = asc_val > 122 ? asc_val-26 : asc_val;
            ans.push_back(char_new);
        }
        if(i == S.length())
            return ans;
        string left = S.substr(i, S.length());
        return ans+left;
    }
};