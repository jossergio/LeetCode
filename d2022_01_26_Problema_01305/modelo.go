/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func arvoreParaLista (arvore *TreeNode) (lista [] int) {
    
    if arvore != nil {
        lista = arvoreParaLista (arvore.Left)
        lista = append (lista, arvore.Val)
        tmp := arvoreParaLista (arvore.Right)
        lista = append (lista, tmp...)
    }
    
    return // [] int
}

func ordenado (l1 [] int, l2 [] int) (o [] int) {
    var i1 int // = 0
    var i2 int // = 0
    
    t1 := len (l1)
    t2 := len (l2)
    
    for i1 < t1 && i2 < t2 {
        
        if l1 [i1] < l2 [i2] {
            o = append (o, l1 [i1])
            i1++
        } else {
            o = append (o, l2 [i2])
            i2++
        }
        
    }
    if i1 < t1 {
        
        for i1 < t1 {
            o = append (o, l1 [i1])
            i1++
        }
        
    } else { // Com certeza foi i2
        
        for i2 < t2 {
            o = append (o, l2 [i2])
            i2++
        }
        
    }
    
    return // o
}

func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
    
    lista1 := arvoreParaLista (root1)
    lista2 := arvoreParaLista (root2)
    
    return ordenado (lista1, lista2)
}

