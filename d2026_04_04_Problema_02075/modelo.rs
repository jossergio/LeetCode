impl Solution {
    pub fn decode_ciphertext(encoded_text: String, rows: i32) -> String {
        let mut matriz: Vec<Vec<u8>> = Vec::new ();
        let encoded_text: Vec<u8> = encoded_text.as_bytes ().to_vec (); // Muda o tipo
        let t = encoded_text.len ();
        if t == 0 { // chunks entra em pânico; sumariamente
            return String::from ("" );
        }
        let rows = rows as usize; // Muda o tipo
        let cols = t / rows;
        for linha in encoded_text.chunks (cols) {
            matriz.push (linha.to_vec ());
        }
        let mut resposta: Vec<u8> = Vec::new ();
        for j in 0..cols {
            for i in 0..rows {
                if i + j < cols {
                    resposta.push (matriz [i][j + i]);
                } else {
                    break;
                }
            }
        }
        String::from_utf8 (resposta)
            .unwrap ()
            .trim_right ()
            .to_string ()
    }
}
