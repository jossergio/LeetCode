impl Solution {
    fn pode (tmp: &Vec<i32>, dif: i32, i: usize, acum: i32) -> bool {
        if i < tmp.len () {
            let mut i = i;
            while i < tmp.len () {
                if dif == acum + tmp [i] || Self::pode (tmp, dif, i + 1, acum + tmp [i]) {
                    return true;
                }
                i += 1;
            }
        }
        // else
        false // Padrão
    }
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        let mut nums = nums; // Torna mutável
        nums.sort ();
        let soma: i32 = nums.iter ().sum ();
        if soma % 3 == 0 {
            return soma; // Já é a resposta
        }
        // else
        let mut max_3 = (soma / 3) * 3; // Maior possível
        let t = nums.len ();
        while max_3 > 0 {
            let mut i = 0usize;
            let dif = soma - max_3;
            let mut tmp: Vec<i32> = Vec::new ();
            while i < t && nums [i] <= dif {
                tmp.push (nums [i]);
                i += 1;
            }
            if Self::pode (&tmp, dif, 0, 0) {
                break;
            }
            // else
            max_3 -= 3;
        }
        max_3
    }
}
