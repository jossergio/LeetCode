impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        bank.into_iter ().filter_map (
            | a | {
                let tmp = a.chars ().filter (| c | *c == '1').count ();
                if tmp > 0 {
                    ;return Some (tmp)
                }
                // else
                None
            })
            .fold ((0, 0), | (mut acum, mut anterior), atual | {
                acum += atual * anterior;
                anterior = atual;
                (acum, anterior)
            }
        ).0 as i32 // Por conta de count, Rust infere todo mundo como usize
    }
}
