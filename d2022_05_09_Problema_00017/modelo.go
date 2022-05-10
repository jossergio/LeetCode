var estrutura map [byte] string

func iniciar () {
    estrutura = make (map [byte] string)
    estrutura ['2'] = "abc"
    estrutura ['3'] = "def"
    estrutura ['4'] = "ghi"
    estrutura ['5'] = "jkl"
    estrutura ['6'] = "mno"
    estrutura ['7'] = "pqrs"
    estrutura ['8'] = "tuv"
    estrutura ['9'] = "wxyz"
}

func estruturar (d string, p int,  t string, r *[] string) {
    if len (t) == len (d) {
        *r = append (*r, t)
    } else {
        for _, c := range estrutura [d [p]] {
            estruturar (d, p + 1, t + string (c), r)
        }
    }
}

func letterCombinations(digits string) []string {
    if len (estrutura) == 0 {
        iniciar ()
    }
    
    var retorno [] string
    
    if len (digits) == 0 { // Caso contrário, incluirá uma string vazia ("")
        return retorno
    }
    
    estruturar (digits, 0, "", &retorno)
    
    return retorno
}

