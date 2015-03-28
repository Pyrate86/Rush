couple(marc,anne).
couple(luc,betty).
couple(jules,lisa).
couple(leon,sylvie).
couple(loic,eve).
couple(paul,julie).

h(jean).
h(gerard).
h(jacques).
h(herve).

f(valerie).

parent(marc, jean).
parent(marc, jules).
parent(marc, leon).
parent(luc, lisa).
parent(luc, loic).
parent(luc, gerard).
parent(jules, jacques).
parent(leon, herve).
parent(leon, julie).
parent(loic, paul).
parent(loic, valerie).

homme(X) :- h(X).
homme(X) :- couple(X,_).

femme(X) :- f(X).
femme(X) :- couple(_,X).

mari_de(X,Y) :- couple(X,Y), homme(X).
femme_de(Y,X) :- couple(X,Y), femme(Y).

enfant_de(Y,X) :- parent(X,Y).
enfant_de(Z,X) :- parent(Y,Z), couple(Y,X).

beaupere_de(X,Z) :- couple(Z,Y), parent(X,Y).
beaupere_de(X,Z) :- couple(Y,Z), parent(X,Y).

bellemere_de(X,Z) :- femme_de(X, Y), beaupere_de(Y, Z).

ancetre_de(X,Y) :- enfant_de(Y,X).
ancetre_de(X,Z) :- enfant_de(Z,Y), ancetre_de(X,Y).
