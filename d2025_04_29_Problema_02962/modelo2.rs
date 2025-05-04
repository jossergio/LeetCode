impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let t = nums.len ();
        let mut resposta = 0 as i64;
        let mut i = 0 as usize;
        let mut j = 0 as usize;
        let mut contagem = 0; // i32
        let maior = *nums.iter ().max ().unwrap (); // i32
        while j < t {
            while j < t && contagem < k {
                if nums [j] == maior { contagem += 1; }
                j += 1;
            }
            while (contagem >= k) {
                if nums [i] == maior { contagem -= 1; }
                resposta += t as i64 - j as i64 + 1; // Basicamente, de i até o final
                i += 1;
            }
        }
        resposta
    }
}
