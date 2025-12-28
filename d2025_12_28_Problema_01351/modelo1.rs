impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let b = grid [0].len () - 1; // Base
        let mut limite: Option<usize> = Some (b); // Base inicial
        let mut contagem = 0;
        for v in grid {
            loop {
                if let Some (i) = limite {
                    if v [i] < 0 {
                        if i == 0 {
                            limite = None;
                        } else {
                            limite = Some (i - 1);
                        }
                    } else {
                        break;
                    }
                } else  {
                    break;
                }
            } // loop
            contagem += (if let Some (i) = limite { b - i } else { b  + 1 }) as i32;
        }
        contagem
    }
}
