class Solution {
private:
    void contar (vector<int>& nums, int k, int p, vector<int>& acum, int& resp) {
        if (p < nums.size ()) {
            for (int i = p; i < nums.size (); i += 1) {
                bool pode = true;
                for (int v: acum) {
                    if (abs (v - nums [i]) == k) {
                        pode = false;
                        break;
                    }
                }
                if (pode) {
                    resp += 1;
                    acum.push_back (nums [i]);
                    contar (nums, k, i + 1, acum, resp);
                    acum.pop_back ();
                }
            }
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int resposta = 0;
        vector<int> acumulado;
        contar (nums, k, 0, acumulado, resposta);
        return resposta;
    }
};

