impl Solution {
    pub fn is_ugly(n: i32) -> bool {
        if n <= 0 { return false; } // Não será
        let mut n = n; // Torna mutável
        for v in [2, 3, 5] {
            while n % v == 0 {
                n /= v;
            }
            if n == 1 { return true; } // Sai logo
        }
        false // Com certeza, n é maior que 1 e as divisões contém outros divisores
    }
}
