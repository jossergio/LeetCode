class Solution {
private:
    double pot (double x, long int n) {
        if (n == 0) // Também é saída da recursividade
            return 1;
        if (n < 0)
            return 1 / pot (x, -1 * n);
        if (n % 2 == 1) // Ímpar
            return x * pot (x * x, (n - 1) / 2); // Mesmo que n == 1; uma condição a menos
        // else
        return pot (x * x, n / 2);
    }
public:
    double myPow(double x, int n) {
        return pot (x, n);
    }
};

