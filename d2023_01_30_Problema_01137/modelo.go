var tribs = [] int {0, 1, 1};

func tribonacci(n int) int {
    if len (tribs) <= n {
        tribs = append (tribs, tribonacci (n - 1) + tribonacci (n - 2) + tribonacci (n - 3))
    }
    return tribs [n]
}

