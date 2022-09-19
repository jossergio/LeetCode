func pegarConteudo (arq string) (string, string) {
    itens := strings.Split (arq, "(") // Só há um
    return itens [0], itens [1][:len (itens [1]) - 1] // Tira o ")", sempre no final
}
func findDuplicate(paths []string) [][]string {
    
    mapa := make (map [string] [] string)
    
    for _, a := range paths {
        
        tmp := strings.Split (a, " ") // O delimitador é um espaço
        caminho := tmp [0] // O primeiro item é o caminho (path)
        
        for i := 1; i < len (tmp); i++ { // A partir do segundo item, são nomes de arquivos
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
        
        resposta = append (resposta, item)
    }
    
    return resposta
}

