type CombinationIterator struct {
	Combinacoes [] string
}

func montarCombinacoes (combs *[] string, comb string, caracteres string, inicio int, nivel int) {
	if nivel == 0 {
		*combs = append (*combs, comb)
	} else { // if nivel == 0
		for i := inicio; i < len (caracteres); i++ {
			montarCombinacoes (combs, comb + string (caracteres [i]), caracteres, i + 1, nivel - 1)
		} // for i
	} // else if nivel == 0
} // montarCombinacoes

func Constructor(characters string, combinationLength int) CombinationIterator {
	var combs [] string
	montarCombinacoes (&combs, "", characters, 0, combinationLength)
	return CombinationIterator {combs}
}


func (this *CombinationIterator) Next() string {
	var retorno string
	if this.HasNext () {
		retorno = this.Combinacoes [0]
		this.Combinacoes = this.Combinacoes [1:]
	}
	return retorno
}


func (this *CombinationIterator) HasNext() bool {
	return (len (this.Combinacoes) > 0)
}


/**
 * Your CombinationIterator object will be instantiated and called as such:
 * obj := Constructor(characters, combinationLength);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */

