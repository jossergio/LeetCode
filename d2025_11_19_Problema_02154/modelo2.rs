impl Solution {
    pub fn find_final_value(nums: Vec<i32>, original: i32) -> i32 {
        let tabela = std::collections::HashSet::<i32>::from_iter (nums.into_iter ());
        let mut resp = original;
        while tabela.contains (&resp) {
            resp <<= 1; // Dobra binária
        }
        resp
    }
}
