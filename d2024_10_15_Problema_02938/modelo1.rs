impl Solution {
    pub fn minimum_steps(s: String) -> i64 {
        let mut tmp = String::from (s); // Iremos modificar a área dessa string
        let mut d = unsafe { tmp.as_bytes_mut () };
        let mut contador: i64 = 0;
        let mut permuta = true;
        let mut zero: i32 = d.len () as i32 - 1; // Onde deve ficar o último algarismo 0 reversamente
        let mut um: i32 = zero; // Só para ter um valor talvez maior e dentro do limite de "zero"
        // Obs.: i32, pois -1 indica que terminou
        while permuta {
            while zero >= 0 && d [zero as usize] != b'0' {
                zero -= 1;
            }
            if um > zero {
                um = zero - 1;
            }
            while um >= 0 && d [um as usize] != b'1' {
                um -= 1;
            }
            if um >= 0 { // Basta checar esse, pois veio por derivação do outro
                d [zero as usize] = b'1';
                d [um as usize] = b'0';
                contador += (zero - um) as i64; // A quantidade de permutas para ajeitar esse par
                um -= 1; // Para fazer busca a partir daqui, na próxima iteração
            } else {
                permuta = false; // Não há mais necessidade de permutar nada
            }
        }
        contador
    }
}

