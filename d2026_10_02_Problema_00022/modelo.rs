use std::collections::HashSet;
impl Solution {
    fn preencher (a: &mut HashSet<Vec<char>>, tmp: Vec<char>, mut n: i32) {
        if n == 0 {
            a.insert (tmp);
        } else {
            for i in 0..tmp.len () {
                if tmp [i] == ')' {
                    let mut tmp2 = tmp.clone (); // Para facilitar descartar, depois
                    tmp2.insert (i, ')'); // Primeiro o fecha parêntesis
                    tmp2.insert (i, '('); // Em seguida o abre parêntesis
                    Self::preencher (a, tmp2, n - 1);
                }
            }
            let mut tmp2 = tmp.clone (); // Idem, para o final da cadeia
            tmp2.insert (tmp.len (), ')');
            tmp2.insert (tmp.len (), '(');
            Self::preencher (a, tmp2, n - 1);
        }
    }
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut pre_resposta: HashSet<Vec<char>> = HashSet::new ();
        let tmp: Vec<char> = Vec::new ();
        Self::preencher (&mut pre_resposta, tmp, n);
        pre_resposta
            .into_iter ()
            .map (| r | String::from_iter (r.into_iter ()))
            .collect::<Vec<String>> ()
    }
}
