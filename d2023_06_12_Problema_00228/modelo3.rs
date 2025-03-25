impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut resposta: Vec<String> = Vec::new ();
        let mut i: usize = 0;
        let t = nums.len ();
        while i < t {
            let mut tmp = nums [i].to_string ();
            let mut marcador = i;
            while i < t - 1 && nums [i + 1] == nums [i] + 1 {
                i += 1;
            }
            if i != marcador {
                tmp += &(String::from ("->") + &nums [i].to_string ());
            }
            resposta.push (tmp);
            i += 1;
        }
        resposta
    }
}
