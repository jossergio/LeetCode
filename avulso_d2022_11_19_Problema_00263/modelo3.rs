impl Solution {
    pub fn is_ugly(n: i32) -> bool {
        if n <= 0 { return false; } // Não será
        if n == 1 { return true; } // Padrão
        (n % 2 == 0 && Self::is_ugly (n / 2))
            || (n % 3 == 0 && Self::is_ugly (n / 3))
            || (n % 5 == 0 && Self::is_ugly (n / 5))
    }
}
