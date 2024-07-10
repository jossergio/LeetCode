impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut contador:i32 = 0;
        for s in logs {
            let b = s.as_bytes ();
            if b [0] == b'.' { // Sempre há algo aqui
                if b [1] == b'.' { // É isso ou '/'
                    contador = if contador == 0 { 0 } else { contador - 1};
                } // Senão, ou seja, é '/', peremanece onde está
            } else {
                contador += 1;
            }
        }
        return contador;
    }
}

