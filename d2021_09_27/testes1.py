# coding: utf-8

#import modelo1
import modelo2

#m = modelo1.Solution ()
m = modelo2.Solution ()

lista = ["eu.voce@ninguem.ele", "euvoce@ninguem.ele",
    "eu.vo.ce+qualquer@ninguem.ele", "euvoce@ninguem.ele"]

tratados = [m.tratarEmail (email) for email in lista]

print (tratados)

print ("Únicos: ", m.numUniqueEmails (lista))

