impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        let mut cont = 0;
        let mut acum_R = 0; // Acumulados de R
        let mut ant = b'I'; // Infinito à esquerda
        for c in directions.bytes () {
            cont += match c {
                b'R' => { acum_R += 1; ant = b'R'; 0 },
                b'S' => {
                    let tmp = acum_R;
                    acum_R = 0;
                    ant = b'S';
                    tmp
                },
                b'L' => {
                    let mut tmp = 0;
                    if ant == b'S' {
                        tmp = 1;
                        // ant permanece
                    } else if ant == b'R' {
                        tmp += 2;
                        tmp += acum_R - 1;
                        ant = b'S';
                        acum_R = 0;
                    } else { // Ou é I ou outro L
                        ant = b'L';
                    }
                    tmp
                },
                _ => 0 // Só para ter um valor geral
            }
        }
        cont
    }
}
