class Solution {
private:
    static bool ordenar (pair<int, int> a, pair<int, int> b) {
        return (a.second < b.second);
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> temporario (nums.size ());
        
        for (int i = 0; i < nums.size (); i++)
            temporario [i] = {i, nums [i]};
        
        sort (temporario.begin (), temporario.end (), ordenar);
        
        int esquerda = 0, direita = nums.size () - 1;
        
        while (esquerda < direita) {
            
            int acumulado = temporario [esquerda].second + temporario [direita].second;
            
            if (acumulado == target)
                return vector<int> ({temporario [esquerda].first, temporario [direita].first});
            // else
            if (acumulado > target)
                direita--;
            else
                esquerda++;
        } // while
        
        return vector<int> (); // Vazio, se chegar aqui
    }
};

