const modulo: i64 = 12345;
impl Solution {
    pub fn construct_product_matrix(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = grid [0].len (); // Só preciso das colunas
        let tmp: Vec<i64> = grid // Usarei várias vezes assim
            .into_iter ()
            .flatten ()
            .map (| n | n as i64)
            .collect ();
        let valores1: Vec<i64> = tmp
            .iter ()
            .scan (1, | acum, atual | {
                let tmp = *acum % modulo;
                *acum = (*acum * *atual) % modulo;
                Some (tmp)
            })
            .collect ();
        let mut valores2: Vec<i64> = tmp // Irei inverter a ordem
            .iter ()
            .rev ()
            .scan (1, | acum, atual | {
                let tmp = *acum % modulo;
                *acum = (*acum * *atual) % modulo;
                Some (tmp)
            })
            .collect ();
        valores2.reverse ();
        valores1
            .iter ()
            .zip (valores2.iter ())
            .map (| (v1, v2) | ((*v1 * *v2) % modulo) as i32)
            .collect::<Vec<i32>> ()
            .chunks (m)
            .map (| a | a.to_vec ())
            .collect::<Vec<Vec<i32>>> ()
    }
}
