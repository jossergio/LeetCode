impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let esq: Vec<i32> = nums
            .iter ()
            .scan (0, | acum, atual | {
                let tmp = *acum;
                *acum += atual;
                Some (tmp)
            })
            .collect ();
        let mut dir: Vec<i32> = nums
            .iter ()
            .rev ()
            .scan (0, | acum, atual | {
                let tmp = *acum;
                *acum += atual;
                Some (tmp)
            })
            .collect ();
        dir.reverse (); // Retorna; não consegui fazer no iterador
        esq
            .into_iter ()
            .zip (dir.into_iter ())
            .map (| (a, b) | (a - b).abs ())
            .collect ()
    }
}
