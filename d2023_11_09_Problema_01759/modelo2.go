const modulo int = 1000000007

var memo [] int

func pegaValor (i int) int {
    if i > len (memo) {
        if i == 1 {
            memo = append (memo, 1)
        } else {
            memo = append (memo, i + pegaValor (i - 1)) // Bela fórmula, não?
        }
    }
    return memo [i - 1] // 0-begin
}

func countHomogenous(s string) int {
    memo = [] int {}
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
        resposta = (resposta + pegaValor (tmp)) % modulo
    }
    return resposta
}

