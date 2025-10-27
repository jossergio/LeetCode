impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        bank.into_iter ().fold ((0, 0),
            | (mut anterior, mut acum), atual | {
                let cont = atual.chars ().filter (| c | *c == '1').count ();
                if cont != 0 {
                    acum += cont * anterior;
                    anterior = cont;
                }
                (anterior, acum)
            }
        ).1 as i32 // Por conta de count, Rust infere todo mundo como usize
    }
}
