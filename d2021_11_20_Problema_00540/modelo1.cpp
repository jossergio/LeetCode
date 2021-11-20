class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int anterior = nums [0];
        int contador = 1;
        for (int i = 1; i < nums.size (); i++) {
            if (nums [i] != anterior) {
                if (contador == 1) {
                    return anterior;
                } else { // if contador == 1
                    contador = 1;
                    anterior = nums [i];
                } // else if contador == 1
            } else // if nums i != anterior
                contador++;
        } // for i
        return nums [nums.size () - 1]; // Se chegou até aqui...
    }
};

