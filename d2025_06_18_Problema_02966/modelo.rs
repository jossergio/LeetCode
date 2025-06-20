impl Solution {
    pub fn divide_array(nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let mut resposta: Vec<Vec<i32>> = Vec::new ();
        let mut nums = nums.clone (); // Somreia e torna mutável
        nums.sort ();
        for i in (0..(nums.len () / 3)) {
            let (v1, v2, v3) = (nums [i * 3], nums [i * 3 + 1], nums [i * 3 + 2]);
            if v3 - v2 > k || v2 - v1 > k || v3 - v1 > k {
                return Vec::new (); // Não satisfaz a condição
            }
            // else
            resposta.push (vec![v1, v2, v3]);
        }
        resposta
    }
}
