impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        operations.iter ().fold (
            0, | acum, atual |
            if atual.as_bytes ()[1] == b'+' { acum + 1 } else { acum - 1 }
        )
    }
}
