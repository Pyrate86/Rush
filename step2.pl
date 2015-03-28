/*
Si X existe en dans la Tete
sinon
la Queue deviens nouvelle liste envoyee a exists
*/
exists(X,[X|_]).
exists(X,[_|Y]) :- exists(X,Y).


%G est il a gauche de D ... simple non ?
gauche_droite(G,D,[G,D,_,_,_]).
gauche_droite(G,D,[_,G,D,_,_]).
gauche_droite(G,D,[_,_,G,D,_]).
gauche_droite(G,D,[_,_,_,G,D]).

/*
X et Y sont ils voisins dans la liste L
X a Gauche de Y
sinon
Y a gauche de X
*/
voisin(X,Y,L) :- gauche_droite(X,Y,L).
voisin(X,Y,L) :- gauche_droite(Y,X,L).

/* 
 [Nationalite,Couleur,Animal,Boisson,Fumer]
 creation de la liste avec la premiere maison et celle du milieu
 pour on suit ce qui est dis dans le sujet
 et enfin on ajoute le poisson
*/

solution(S) :-
S = [[norvegien,_,_,_,_],_,[_,_,_,lait,_],_,_],
exists([anglais,rouge,_,_,_],S),
exists([suedois,_,chiens,_,_],S),
exists([danois,_,_,the,_],S),
gauche_droite([_,vert,_,_,_],[_,blanche,_,_,_],S),
exists([_,vert,_,cafe,_],S),
exists([_,_,oiseau,_,pall_mall],S),
exists([_,jaune,_,_,dunhill],S),
voisin([_,_,_,_,blend],[_,_,chats,_,_],S),
voisin([_,_,cheval,_,_],[_,_,_,_,dunhill],S),
exists([_,_,_,biere,blue_master],S),
exists([allemand,_,_,_,prince],S),
voisin([norvegien,_,_,_,_],[_,bleue,_,_,_],S),
voisin([_,_,_,_,blend],[_,_,_,eau,_],S),
exists([_,_,poisson,_,_],S).