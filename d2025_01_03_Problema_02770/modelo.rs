impl Solution {
    pub fn ways_to_split_array(nums: Vec<i32>) -> i32 {
        let mut acum: i128 = 0;
        let mut v: Vec<i128> = vec![0; nums.len ()];
        for (i, a) in nums.iter ().enumerate () {
            acum += *a as i128;
            v [i] = acum;
        }
        let mut resposta: i32 = 0;
        for i in 0..(nums.len () - 1) { // Não pode dividir no último
            if v [i] >= acum - v [i] {
                resposta += 1;
            }
        }
        resposta
    }
}

