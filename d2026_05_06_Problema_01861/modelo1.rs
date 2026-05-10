impl Solution {
    pub fn rotate_the_box(box_grid: Vec<Vec<char>>) -> Vec<Vec<char>> {
        let (m, n) = (box_grid.len (), box_grid [0].len ());
        let mut resposta = vec![vec!['.'; m]; n];
        let mut box_grid = box_grid.clone ();
        for i in 0..m {
            let mut j = n as i32 - 1; // Usarei -1 para final reverso
            while j >= 0 {
                let mut vazio = j;
                while vazio >= 0 && box_grid [i][vazio as usize] != '.' {
                    // Observar que a varredura é rotacionada
                    resposta [vazio as usize][m - i - 1] = box_grid [i][vazio as usize];
                    vazio -= 1;
                }
                let mut pedra = vazio - 1;
                while pedra >= 0 && box_grid [i][pedra as usize] == '.' {
                    pedra -= 1;
                    // Não precisa atualizar resposta, pois já é preenchida com vazios
                }
                if pedra >= 0 {
                    if box_grid [i][pedra as usize] == '*' { // Obstáculo
                        resposta [pedra as usize][m - i - 1] = '*';
                        j = pedra - 1;
                    } else { // É uma pedra
                        resposta [vazio as usize][m - i - 1] = '#';
                        box_grid [i][pedra as usize] = '.'; // Retira a pedra daqui
                        j = vazio - 1;
                    }
                } else {
                    j = -1;
                }
            }
        }
        resposta
    }
}
