impl Solution {
    pub fn total_waviness(num1: i32, num2: i32) -> i32 {
        (num1..=num2)
            .map (| mut a | {
                let mut prev = a % 10;
                a /= 10;
                let mut ant = a % 10;
                a /= 10;
                let mut r = 0;
                while a > 0 {
                    let atual = a % 10;
                    if (ant > prev && ant > atual) || (ant < prev && ant < atual) {
                        r += 1;
                    }
                    (prev, ant) = (ant, atual);
                    a /= 10;
                }
                r
            })
            .sum ()
    }
}
