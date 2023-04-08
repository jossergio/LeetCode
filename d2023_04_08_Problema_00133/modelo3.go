/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
    if node == nil { // Por falta disso, produziu um erro
        return nil
    }

    mapa := make (map [*Node] *Node)
    var montar func (no *Node) *Node // Como irá fazer recursão, tem que declarar antes do corpo
    montar = func (no *Node) *Node {
        if _, existe := mapa [no]; !existe {
            tmp := &Node {no.Val, make ([] *Node, len (no.Neighbors))}
            mapa [no] = tmp
            for i, item := range no.Neighbors {
                tmp.Neighbors [i] = montar (item)
            }
        }
        return mapa [no]
    }
    
    return montar (node)
}

