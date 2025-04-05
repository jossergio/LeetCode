impl Solution {
    fn buscar (nums: &Vec<i32>, nivel: usize, mut tmp: Vec<i32>, total: &mut i32) {
        if nivel == nums.len () {
            *total += tmp.iter ().fold (0, | acum, v | acum ^ v);
        } else {
            Self::buscar (nums, nivel + 1, tmp.clone (), total);
            tmp.push (nums [nivel]);
            Self::buscar (nums, nivel + 1, tmp.clone (), total);
        }
    }
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let mut resposta: i32 = 0;
        let mut tmp: Vec<i32> = Vec::new ();
        Self::buscar (&nums, 0, tmp, &mut resposta);
        resposta
    }
}
