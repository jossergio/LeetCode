impl Solution {
    pub fn title_to_number(column_title: String) -> i32 {
        let mut base: i32 = 1; // Unidade, dezena, centena... (x26)
        let mut resposta: i32 = 0;
        for c in column_title.bytes ().rev () {
            resposta += i32::from (c - b'A' + 1) * base;
            base *= 26;
        }
        resposta
    }
}
