impl Solution {
    fn pegar_ids (s: &str) -> Vec<i32> {
        let mut id = 0;
        let mut retorno: Vec<i32> = Vec::new ();
        for v in s.bytes () {
            if v == b'i' || v == b'd' {
                continue;
            }
            if v == b' ' {
                retorno.push (id);
                id = 0;
            } else {
                id *= 10;
                id += (v - b'0') as i32;
            }
        }
        retorno.push (id); // O que sobrou
        retorno
    }
    pub fn count_mentions(number_of_users: i32, events: Vec<Vec<String>>) -> Vec<i32> {
        let n = number_of_users as usize; // Converte e facilita
        let mut offline: Vec<i32> = vec![0; n];
        let mut resposta = vec![0; n];
        let mut events = events; // Torna mutável
        events.sort_by (| a, b | {
            let t_a = (
                *Self::pegar_ids (&a [1]).first ().unwrap (), // Reaproveitar código
                if a [0] == "MESSAGE" { 1 } else { 0 } // Prioriza OFFLINE
            );
            let t_b = (
                *Self::pegar_ids (&b [1]).first ().unwrap (), // Idem
                if b [0] == "MESSAGE" { 1 } else { 0 } // Idem
            );
            t_a.cmp (&t_b)
        }); // events.sort_by
        for e in events {
            if e [0] == "MESSAGE" {
                match e [2].as_str () {
                    "ALL" => (0..n).for_each (| i | resposta [i] += 1 ),
                    "HERE" => {
                        let tempo = *Self::pegar_ids (&e [1]).first ().unwrap (); // Ideia de reaproveitar código
                        (0..n).filter (| &i | offline [i] <= tempo).for_each (| i | resposta [i] += 1 )
                    }
                    _ => Self::pegar_ids (&e [2]).iter ().for_each (| &i | resposta [i as usize] += 1)
                }
            } else { // OFFLINE
                let id = *Self::pegar_ids (&e [2]).first ().unwrap (); // Olha as ideias de reaproveitar código
                let tempo = *Self::pegar_ids (&e [1]).first ().unwrap (); // Idem
                offline [id as usize] = tempo + 60;
            }
        }
        resposta
    }
}
