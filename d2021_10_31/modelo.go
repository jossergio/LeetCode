/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

func pegarUltimo (filho *Node) *Node {
	no := filho
	for no.Next != nil { // filho nunca vem nil
		no = no.Next
	} // for no.Next != nil
	return no
}

func flatten(root *Node) *Node {
	no := root
	for no != nil {
		if no.Child != nil {
			filho := no.Child
			ultimo := pegarUltimo (filho)
			ultimo.Next = no.Next
			if no.Next != nil {
				proximo := no.Next
				proximo.Prev = ultimo
			} // if no.Next != nil
			no.Next = filho
			no.Child = nil
			filho.Prev = no
		} // if no.Child != nil
		no = no.Next
	} // for no != nil
	return root
}

