impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        nums
            .iter ()
            .map (| v | {
                let mut n = -1; // Padrão
                let mut d = 1; // Diferença
                while v & d != 0 {
                    n = v - d;
                    d <<= 1;
                }
                n
            }).collect::<Vec<_>> ()
    }
}
