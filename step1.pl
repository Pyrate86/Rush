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



%Copyright (c) 2015 (Oui, du prolog, en 2015, je sais), mbarbari

%Creation des couples 
couple(marc,anne).
couple(luc,betty).
couple(jules,lisa).
couple(leon,sylvie).
couple(loic,eve).
couple(paul,julie).

%Creation des solos
couple(jean, null).
couple(gerard, null).
couple(jacques, null).
couple(herve, null).
couple(null, valerie).

%creation des enfants
enfant(marc, anne, [jean, jules, leon]).
enfant(luc, betty, [lisa, loic, gerard]).
enfant(jules, lisa, [jacques]).
enfant(leon, sylvie, [herve, julie]).
enfant(loic, eve, [paul, valerie]).

%Test si le personnage est une femme
femme(X) :- X \== null, couple(_, X).
homme(X) :- X \== null, couple(X, _).

couple_(Ind, Conjoint) :- couple(Ind, Conjoint) ; couple(Conjoint, Ind).

mari_de(Femme, Homme) :- couple(Homme, Femme), homme(Homme), femme(Femme).
femme_de(Homme, Femme) :- couple(Homme, Femme), femme(Femme), homme(Homme).

exists(X, [X | _]).
exists(X, [_|Tail]) :- exists(X, Tail).

beaupere_de(Enfant, Pere) :-
    couple_(Enfant,Conjoint),
    enfant(Pere, _, List),
    exists(Conjoint, List),!.

bellemere_de(Enfant, Mere) :-
    couple(Pere,Mere),beaupere_de(Enfant,Pere).

enfant_de(Pere, Enfant) :- enfant(Pere, _, List),exists(Enfant, List), !.
enfant_de(Mere, Enfant) :- enfant(_,Mere,List),exists(Enfant, List), !.


