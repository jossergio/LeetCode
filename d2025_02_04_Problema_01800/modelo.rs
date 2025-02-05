impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let mut ant: i32 = nums [0];
        let mut acum: i32 = ant;
        let mut resposta: i32 = acum;
        for i in 1..nums.len () {
            if nums [i] > ant {
                acum += nums [i];
            } else {
                acum = nums [i];
            }
            if acum > resposta {
                resposta = acum;
            }
            ant = nums [i];
        }
        resposta
    }
}
