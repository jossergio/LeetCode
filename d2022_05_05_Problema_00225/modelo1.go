type TLista struct {
    valor int
    proximo *TLista
}

type MyStack struct {
    lista *TLista
}


func Constructor() MyStack {
    return MyStack {lista: nil}
}


func (this *MyStack) Push(x int)  {
    adicionar := &TLista {valor: x, proximo: this.lista}
    this.lista = adicionar
}


func (this *MyStack) Pop() int {
    x := this.lista.valor
    this.lista = this.lista.proximo
    return x
}


func (this *MyStack) Top() int {
    return this.lista.valor
}


func (this *MyStack) Empty() bool {
    return this.lista == nil
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */

