impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let mut ultimo: i32 = 0; // Por padrão
        let mut resposta: Vec<i32> = Vec::new ();
        let t = nums.len () as i32 - 1;
        for (i, n) in nums.into_iter ().enumerate () {
            if n == key {
                for j in ((i as i32 - k).max (ultimo)..=(i as i32 + k).min (t)) {
                    resposta.push (j);
                }
                ultimo = i32::min (i as i32 + k, t) + 1; // Salta mais um, pois já foi incluído
            }
        }
        resposta
    }
}
