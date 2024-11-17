impl Solution {
    pub fn convert_to_title(column_number: i32) -> String {
        let mut column_number = column_number; // Sombreia e torna mutável
        let mut v = Vec::new (); // Formará a resposta
        let A = b'A'; // u8
        while column_number != 0 {
            column_number -= 1;
            v.push ((column_number % 26) as u8 + A);
            column_number /= 26;
        }
        v.reverse (); // O algoritmo monta de forma invertida
        String::from_utf8 (v).unwrap ()
    }
}

