impl Solution {
    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
        let mut contar = vec! [0; 7]; // Conta cada número; a posição zero é desprezada; evitar cálculos de posição por 1-begin
        let mut embaixos = vec! [0; 7]; // Similar
        let mut em_cimas = vec! [0; 7];
        for i in 0..tops.len () { // Taanto faz tops ou bottos; são do mesmo tamanho
            contar [tops [i] as usize] += 1;
            if tops [i] != bottoms [i] {
                contar [bottoms [i] as usize] += 1;
                embaixos [bottoms [i] as usize] += 1;
                em_cimas [tops [i] as usize] += 1;
            }
        }
        let (mut numero, mut maximo) = (0 as usize, 0);
        for i in 1..contar.len () {
            if contar [i] > maximo {
                maximo = contar [i];
                numero = i;
            }
        }
        if maximo != tops.len () || numero == 0 { // tops ou bottoms, tanto faz
            return -1;
        }
        if embaixos [numero] < em_cimas [numero] { embaixos [numero] } else { em_cimas [numero] }
    }
}
