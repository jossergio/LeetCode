impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut y: i32 = 0;
        let mut x: i32 = 0; // Coordenada de início
        let limite_y = mat.len () as i32;
        let limite_x = mat [0].len () as i32;
        let mut py: i32 = -1;
        let mut px: i32 = 1; // Passo da coordenada
        let mut cont = (mat.len () * mat [0].len ()) as i32; // Para ter um teste de final
        let mut resposta: Vec<i32> = Vec::with_capacity (cont as usize); // Já reserva
        while cont > 0 {
            resposta.push (mat [y as usize][x as usize]);
            y += py;
            x += px;
            if y == -1 || y == limite_y || x == -1 || x == limite_x {
                if y == -1 || y == limite_y {
                    if y == -1 {
                        if x == limite_x {
                            y = 1;
                            x = limite_x - 1;
                        } else {
                            y = 0;
                        }
                    } else {
                        y = limite_y - 1;
                        if x == -1 {
                            x = 1;
                        } else {
                            x += 2;
                        }
                    }
                }
                if x == -1 || x == limite_x {
                    if x == -1 {
                        if y == limite_y {
                            x = 1;
                            y = limite_y - 1;
                        } else {
                            x = 0;
                        }
                    } else {
                        x = limite_x - 1;
                        if y == -1 {
                            y = 1;
                        } else {
                            y += 2;
                        }
                        x = limite_x - 1;
                    }
                }
                py = -py;
                px = -px;
            }
            cont -= 1;
        }
        resposta
    }
}
