class Solution {
private:
    int perimetroTriangulo (int a, int b, int c) { // Se for um triângulo, retorna seu perímetro
    // Em a, sempre vem o maior
    if (b + c > a)
        return a + b + c;
    // else
    return 0;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        sort (nums.begin (), nums.end ());
        for (int i = nums.size () - 3; i >= 0; i--) {
            int perimetro = perimetroTriangulo (nums [i + 2], nums [i + 1], nums [i]); // i + 2 tem, sempre, o maior dos três
            if (perimetro > 0) {
                return perimetro;
            }
        }
        return 0; // Por omissão; se chegou até aqui, não localizou
    }
};

