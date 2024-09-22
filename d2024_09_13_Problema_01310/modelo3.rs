impl Solution {
    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut arr = arr; // Tornar mutável
        for i in 1..arr.len () {
            arr [i] ^= arr [i - 1];
        }
        Vec::from_iter (queries.iter ().map (
            |q| if q [0] == 0 {arr [q [1] as usize]}
            else {arr [q [1] as usize] ^ arr [(q [0] as usize) - 1]}))
    }
}

