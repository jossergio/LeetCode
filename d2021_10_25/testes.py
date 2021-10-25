import modelo

obj = modelo.MinStack ()

def incluir (valor):
    print ("Incluindo: ", valor)
    obj.push (valor)

incluir (-1)
incluir (-2)
incluir (3)
incluir (0)

print ("Menor: ", obj.getMin ())
print ("Topo: ", obj.top ())

print ("Tirando topo.")
obj.pop ()
print ("Menor: ", obj.getMin ())
print ("Topo: ", obj.top ())

print ("Tirando topo.")
obj.pop ()
print ("Menor: ", obj.getMin ())
print ("Topo: ", obj.top ())

incluir (10)
incluir (-10)

print ("Menor: ", obj.getMin ())
print ("Topo: ", obj.top ())

