const modulo int = 1000000007

func pegaValor (i int, m map [int] int) int {
    if _, existe := m [i]; !existe {
        if i == 1 {
            m [i] = 1
        } else {
            m [i] = i + pegaValor (i - 1, m) // Bela fórmula, não?
        }
    }
    return m [i]
}

func countHomogenous(s string) int {
    memo := make (map [int] int)
    var i  int // = 0
    var t int = len (s)
    var resposta int // = 0
    for i < t {
        c := s [i]
        var tmp int // = 0
        for i < t && c == s [i] {
            tmp += 1
            i += 1
        }
        resposta = (resposta + pegaValor (tmp, memo)) % modulo
    }
    return resposta
}

