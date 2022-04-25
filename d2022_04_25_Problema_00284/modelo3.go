/*   Below is the interface for Iterator, which is already defined for you.
 *
 *   type Iterator struct {
 *       
 *   }
 *
 *   func (this *Iterator) hasNext() bool {
 *		// Returns true if the iteration has more elements.
 *   }
 *
 *   func (this *Iterator) next() int {
 *		// Returns the next element in the iteration.
 *   }
 */

type PeekingIterator struct {
    proximo int // = 0
    lido bool // = false
    i *Iterator
}

func Constructor(iter *Iterator) *PeekingIterator {
    tmp := &PeekingIterator {}
    tmp.i = iter
    return tmp
}

func (this *PeekingIterator) hasNext() bool {
    return this.lido || this.i.hasNext ()
}

func (this *PeekingIterator) next() int {
    if !this.lido {
        this.proximo = this.i.next ()
    }
    this.lido = false // Indiferente
    return this.proximo
}

func (this *PeekingIterator) peek() int {
    if !this.lido {
        this.proximo = this.next ()
    }
    this.lido = true
    return this.proximo
}

