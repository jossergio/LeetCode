impl Solution {
    fn total (mut n: i32) -> i32 {
        let mut r = 0;
        let mut prev = n % 10;
        n /= 10;
        let mut ant = n % 10;
        n /= 10;
        while n > 0 {
            let atual = n % 10;
            if (ant > prev && ant > atual) || (ant < prev && ant < atual) {
                r += 1;
            }
            (prev, ant) = (ant, atual);
            n /= 10;
        }
        r
    }
    pub fn total_waviness(num1: i32, num2: i32) -> i32 {
        let mut r = 0;
        for v in num1..=num2 {
            r += Self::total (v);
        }
        r
    }
}
