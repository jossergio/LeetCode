class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int resposta = 0;
        int i = 0;
        
        map<int, vector<int>> mapa;
        
        for (int a = 0; a < nums2.size (); a++) {
            mapa [nums2 [a]].push_back (a);
        }
        
        while (i < nums1.size ()) {
            
            if (mapa [nums1 [i]].size () > 0)
                for (int b: mapa [nums1 [i]]) {
                    
                    int iTmp = i;
                    int j = b; // De onde inicia j
                    
                    while (iTmp < nums1.size () && j < nums2.size () && nums1 [iTmp] == nums2 [j]) {
                        iTmp++;
                        j++;
                    }
                    
                    resposta = max (resposta, iTmp - i);
                    
                    if (resposta >= (nums1.size () - i)) // Não tem como ser maior que isso
                        return resposta;
                }
            
            i++;
        } // while i
        
        return resposta;
    }
};

