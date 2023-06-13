class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> resposta;
        int i = 0;
        int t = nums.size ();
        while (i < t) {
            string tmp = to_string (nums [i]);
            int marcador = i;
            while (i < t - 1 && nums [i  + 1] == nums [i] + 1)
                i += 1;
            if (i != marcador)
                tmp += "->" + to_string (nums [i]);
            resposta.push_back (tmp);
            i += 1;
        }
        return resposta;
    }
};

