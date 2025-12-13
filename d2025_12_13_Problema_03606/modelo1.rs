impl Solution {
    fn valido (s: &str) -> bool {
        if s.len () == 0 {
            return false; // Sumariamente
        }
        // else
        for c in s.chars () {
            if !(
                (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                c == '_'
            ) {
                return false;
            }
        }
        true
    }
    pub fn validate_coupons(code: Vec<String>, business_line: Vec<String>, is_active: Vec<bool>) -> Vec<String> {
        let n = code.len (); // Todos são do mesmo tamanho
        let linha = std::collections::HashSet::<&str>::from (["electronics", "grocery", "pharmacy", "restaurant"]);
        let mut tmp = (0..n)
            .filter (| &i | is_active [i])
            .filter (| &i | Self::valido (&code [i]))
            .filter (| &i | linha.contains (business_line [i].as_str ()))
            .map (| i | (business_line [i].clone (), code [i].clone ()))
            .collect::<Vec<_>> ();
        tmp.sort_by (| a, b | a.0.cmp (&b.0).then_with (|| a.1.cmp (&b.1)));
        tmp.into_iter ().map (| e | e.1).collect ()
    }
}
