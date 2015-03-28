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
mari_de(Homme,Femme) :- couple(Homme,Femme), homme(Homme).

%idem que pour les mari
femme_de(Femme,Homme) :- couple(Homme,Femme), femme(Femme).

/*
recherche si X est le pere de Y
on recherche alors dans la liste des parents
sinon
recherche si X est la mere de Z
on cherche le mari Y de X dans les couples
puis on recherche dans la liste des parents avec le Y
*/
enfant_de(Enfant,Pere) :- parent(Pere,Enfant).
enfant_de(Enfant,Mere) :- parent(Pere,Enfant), couple(Pere,Mere).


/*
recherche si X est le beau pere de Z
on regarde si Z est en couple avec Y
on recherche alors le parent male de Y
*/
beaupere_de(Pere,Conjoint) :- couple(Conjoint,Enfant), parent(Pere,Enfant).
beaupere_de(Pere,Conjoint) :- couple(Enfant,Conjoint), parent(Pere,Enfant).


%On recherche la femme X du beau pere Y de Z
bellemere_de(Mere,Conjoint) :- femme_de(Mere,Enfant), beaupere_de(Enfant,Conjoint).

/*
si Y est l enfant de X alors X est l ancetre de Y
sinon
on cherche de qui (Y) est l enfant Z,
et on cherche si X est l ancetre de Y (reccursive)
*/
ancetre_de(Ancetre,Enfant) :- enfant_de(Enfant,Ancetre).
ancetre_de(Ancetre,Descendant) :- enfant_de(Descendant,Enfant), ancetre_de(Ancetre,Enfant).
