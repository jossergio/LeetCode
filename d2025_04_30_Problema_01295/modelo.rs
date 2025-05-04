impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let digitos_par = |mut i: i32| -> bool {
            let mut d = 0;
            while i > 0 {
                d += 1;
                i /= 10;
            }
            d % 2 == 0
        };
        let mut resposta = 0;
        for n in nums {
            if digitos_par (n) { resposta += 1; }
        }
        resposta
    }
}
