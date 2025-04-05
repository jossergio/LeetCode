impl Solution {
    fn buscar (nums: &Vec<i32>, nivel: usize, acumulado: i32) -> i32 {
        if nivel == nums.len () {
            return acumulado;
        }
        // else
        Self::buscar (nums, nivel + 1, acumulado) +
            Self::buscar (nums, nivel + 1, acumulado ^ nums [nivel])
    }
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        Self::buscar (&nums, 0, 0)
    }
}
