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

ancetre_de(Parent, Enfant) :- enfant_de(Parent, Enfant), !.
ancetre_de(Parent, Enfant) :- enfant_de(Enfant, N_Parent), ancetre_de(Parent, N_Parent), !.