func pegarConteudo (arq string) (arquivo string, conteudo string) {
    itens := strings.Split (arq, "(") // Só há um
    arquivo = itens [0]
    conteudo = itens [1][:len (itens [1]) - 1] // Tira o ")", sempre no final
    return // arquivo, conteudo
}
func findDuplicate(paths []string) [][]string {
    
    mapa := make (map [string] [] string)
    
    for _, a := range paths {
        
        tmp := strings.Split (a, " ") // O delimitador é um espaço
        caminho := tmp [0] // O primeiro item é o caminho (path)
        
        for i := 1; i < len (tmp); i++ { // A partir do segundo item, são nomes de aruqivos
            a, c := pegarConteudo (tmp [i])
            if _, existe := mapa [c]; !existe { // Não existe
                mapa [c] = make ([] string, 0)
            }
            // else
            mapa [c] = append (mapa [c], caminho + "/" + a)
        }
    }
    
    var resposta [][] string
    
    for _, item := range mapa {
        
        if len (item) < 2 {
            continue // Arquivos únicos não devem fazer parte da lista
        }
        
        tmp := make ([] string, 0)
        
        for _, i := range item {
            tmp = append (tmp, i)
        }
        
        resposta = append (resposta, tmp)
    }
    
    return resposta
}

