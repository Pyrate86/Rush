%Creation des couples connus (male, femelle)
couple(marc,anne).
couple(luc,betty).
couple(jules,lisa).
couple(leon,sylvie).
couple(loic,eve).
couple(paul,julie).

%Creation des celibataires males
h(jean).
h(gerard).
h(jacques).
h(herve).

%Creation des celibataires femelles
f(valerie).

/*
Creation des peres des enfants (pere, enfant)
*/
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

/*
Recherche des hommes
cherche dans les males celib
sinon cherche dans les males de tous les couples
*/
homme(X) :- h(X).
homme(X) :- couple(X,_).

%idem que pour les hommes
femme(X) :- f(X).
femme(X) :- couple(_,X).

/*
recherche (mari, femme)
si le mari et la femme sont en couple alors on renvois l'homme
*/
mari_de(X,Y) :- couple(X,Y), homme(X).

%idem que pour les mari
femme_de(Y,X) :- couple(X,Y), femme(Y).

/*
recherche si X est le pere de Y
on recherche alors dans la liste des parents
sinon
recherche si X est la mere de Z
on cherche le mari Y de X dans les couples
puis on recherche dans la liste des parents avec le Y
*/
enfant_de(Y,X) :- parent(X,Y).
enfant_de(Z,X) :- parent(Y,Z), couple(Y,X).


/*
recherche si X est le beau pere de Z
on regarde si Z est en couple avec Y
on recherche alors le parent male de Y
*/
beaupere_de(X,Z) :- couple(Z,Y), parent(X,Y).
beaupere_de(X,Z) :- couple(Y,Z), parent(X,Y).


%On recherche la femme X du beau pere Y de Z
bellemere_de(X,Z) :- femme_de(X,Y), beaupere_de(Y,Z).

/*
si Y est l enfant de X alors X est l ancetre de Y
sinon
on cherche de qui (Y) est l enfant Z,
et on cherche si X est l ancetre de Y (reccursive)
*/
ancetre_de(X,Y) :- enfant_de(Y,X).
ancetre_de(X,Z) :- enfant_de(Z,Y), ancetre_de(X,Y).
