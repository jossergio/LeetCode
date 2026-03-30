impl Solution {
    pub fn check_strings(s1: String, s2: String) -> bool {
        let mut s1_pares: Vec<char> = s1
            .chars ()
            .step_by (2)
            .collect ();
        s1_pares.sort ();
        let mut s2_pares: Vec<char> = s2
            .chars ()
            .step_by (2)
            .collect ();
        s2_pares.sort ();
        let mut s1_impares: Vec<char> = s1
            .chars ()
            .skip (1)
            .step_by (2)
            .collect ();
        s1_impares.sort ();
        let mut s2_impares: Vec<char> = s2
            .chars ()
            .skip (1)
            .step_by (2)
            .collect ();
        s2_impares.sort ();
        s1_pares == s2_pares && s1_impares == s2_impares
    }
}
