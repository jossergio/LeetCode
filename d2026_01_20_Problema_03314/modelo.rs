impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        nums
            .iter ()
            .enumerate ()
            .map (| (i, &v) | {
                for k in 1..v { // Não chega em v
                    if (k | (k + 1)) == nums [i] {
                        return k
                    }
                }
                -1 // Caso chegue aqui
            }
            ).collect::<Vec<_>> ()
    }
}
