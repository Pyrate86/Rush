hanoi(N) :- move(N, 'gauche', 'droite', 'centre'), write('Tout est a droite'), nl, !.

move(1, X, Y, _) :-
    write('Deplacer le disque de '),
    write(X),
    Y \= 'centre',
    write(' a '),
    write(Y),
    nl;
    write(' au '),
    write(Y),
    nl.

move(N, X, Y, Z) :-
    M is N - 1,
    move(M, X, Z, Y),
    move(1, X, Y, _),
    move(M, Z, Y, X).
