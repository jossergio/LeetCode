impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut ante: i32 = 0;
        let mut prox: i32 = 1;
        let mut n:i32 = n; // Sombrear, para tornar mutável
        while (n > 0) {
            n -= 1;
            let tmp: i32 = prox;
            prox = ante + prox;
            ante = tmp;
        }
        return prox
    }
}

