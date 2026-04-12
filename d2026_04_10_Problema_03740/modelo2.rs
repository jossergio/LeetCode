impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let mut resposta = -1;
        let t = nums.len ();
        for i in 0..t {
            let mut j = i + 1;
            while j < t && nums [j] != nums [i] {
                j += 1;
            }
            let mut k = j + 1;
            while k < t && nums [k] != nums [i] {
                k += 1;
            }
            if k < t {
                let tmp = ((j - i) + (k - j) + (k - i)) as i32; // Não precisa de abs
                resposta = if resposta == -1 { tmp } else { resposta.min (tmp) };
            }
        }
        resposta
    }
}
