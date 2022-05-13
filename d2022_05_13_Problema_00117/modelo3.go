/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func buscar (atual *Node) *Node {
    for atual != nil {
        if atual.Left != nil {
            return atual.Left
        } else {
            if atual.Right != nil {
                return atual.Right
            }
        }
        atual = atual.Next
    }
    return nil // Se chegou ate aqui é porque não encontrou
}

func varrer (no *Node) {
    if no != nil {
        
        if no.Left != nil {

            if no.Right != nil {
                no.Left.Next = no.Right
            } else {
                no.Left.Next = buscar (no.Next)
            }
        }

        if no.Right != nil {
            no.Right.Next = buscar (no.Next)
        }
            
        varrer (no.Right)
        varrer (no.Left)
    }
}

func connect(root *Node) *Node {
    varrer (root)
    
    return root
}

