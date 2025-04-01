impl Solution {
    pub fn title_to_number(column_title: String) -> i32 {
        column_title.bytes ().fold (0, | acum, a | acum * 26 + i32::from (a - b'A' + 1))
    }
}
