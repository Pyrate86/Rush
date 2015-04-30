change_state(s, Loup, Chevre, Chou, n, Loup, Chevre, Chou).
change_state(n, Loup, Chevre, Chou, s, Loup, Chevre, Chou).
change_state(s, s, Chevre, Chou, n, n, Chevre, Chou).
change_state(n, n, Chevre, Chou, s, s, Chevre, Chou).
change_state(s, Loup, s, Chou, n, Loup, n, Chou).
change_state(n, Loup, n, Chou, s, Loup, s, Chou).
change_state(s, Loup, Chevre, s, n, Loup, Chevre, n).
change_state(n, Loup, Chevre, n, s, Loup, Chevre, s).

legal(P,_,G,_) :- P=G, !.
legal(P,W,_,C) :- P=W, P=C, !.

go :- pretFeuGo([(n,n,n,n)],L), out(L), !.

pretFeuGo([(s,s,s,s)|L],Path) :- reverse([(s,s,s,s)|L],Path).

pretFeuGo([(Pecor, Loup, Chevre, Chou)|L],Path) :-

    change_state(Pecor, Loup, Chevre, Chou, Pecor1, Loup1, Chevre1, Chou1),

    legal(Pecor1, Loup1, Chevre1, Chou1),
    
    \+ member((Pecor1, Loup1, Chevre1, Chou1),L),
    
    pretFeuGo([(Pecor1, Loup1, Chevre1, Chou1),(Pecor, Loup, Chevre, Chou)|L],Path).


out([X,Y]) :-
	visu([X],[Y]),
	nl,
	visu([Y],[Y]),
    !.
out([X, Y|Z]) :- 
    visu([X],[Y]),
    nl,
    append([Y], Z, L),
    out(L).

visu([(Peon,Loup,Chevre,Choux)], [(PeonNext, LoupNext, ChevreNext, ChouxNext)]) :-
    writenl('####~~~~####'),
    writenl('#   ~~~~   #'),
    side(Peon, PeonNext, 'P'),
    side(Loup, LoupNext, 'W'),
    side(Chevre, ChevreNext, 'G'),
    side(Choux, ChouxNext, 'C'),
    writenl('#   ~~~~   #'),
    writenl('####~~~~####').

side(X, Y, C) :-
    X == n, Y == n,
    write('# '), write(C), write(' ~~~~   #'), nl;
    X == n, Y == s,
    write('# '), write(C), write(' >>>>   #'), nl;
    X == s, Y == s,
    write('#   ~~~~ '), write(C), write(' #'), nl;
    write('#   <<<< '), write(C), write(' #'), nl.
