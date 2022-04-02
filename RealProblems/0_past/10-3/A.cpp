class Solution {
public:
    int minimumMoves(string s) {
        int thr = 0;
		int num = 0;
		int flag =false;
		for(int i = 0; i< s.size();)
		{
            if(s[i] == 'X'){
                num++;
                if(i + 3 < s.size()){
                    i=i+3;
                }
            }else{
                i++;
            }
		}
		return num;
    }
};