impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut x = 0; // i32
        for o in operations {
            let tmp = o.as_bytes (); // Será usado duas vezes
            if tmp [0] == b'+' || tmp [2] == b'+' {
                x += 1;
            } else {
                x -= 1;
            }
        }
        x
    }
}
