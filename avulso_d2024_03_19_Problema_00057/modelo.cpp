class menor {
public:
    bool operator () (const vector<int>& a, const vector<int>& b) {
        return b [0] < a [0];
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        priority_queue<vector<int>, vector<vector<int>>, menor> fila;
        for (auto i: intervals)
            fila.push (i);
        fila.push (newInterval);
        vector<vector<int>> resposta;
        resposta.push_back (fila.top ());
        fila.pop (); // Há, pelo menos, um
        while (!fila.empty ()) {
            vector<int> topo = fila.top ();
            fila.pop ();
            vector<int> ultimo = resposta.back ();
            if (ultimo [1] < topo [0]) {
                resposta.push_back (topo);
            } else {
                ultimo [1] = max (ultimo [1], topo [1]);
                resposta.pop_back ();
                resposta.push_back (ultimo);
            }
        }
        return resposta;
    }
};

