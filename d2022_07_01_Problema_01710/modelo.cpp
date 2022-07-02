bool ordem (vector<int> a, vector<int> b) {
    return a [1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort (boxTypes.begin (), boxTypes.end (), ordem);
        
        int resp = 0;
        
        for (auto b: boxTypes)
            if (b [0] <= truckSize) {
                resp += b [0] * b [1];
                truckSize -= b [0];
            } else {
                resp += truckSize * b [1];
                break; // Não cabem mais caixas
            }
        
        return resp;
    }
};

