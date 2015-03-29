change_state(s, Loup, Chevre, Chou, n, Loup, Chevre, Chou).
change_state(n, Loup, Chevre, Chou, s, Loup, Chevre, Chou).
change_state(s, s, Chevre, Chou, n, n, Chevre, Chou).
change_state(n, n, Chevre, Chou, s, s, Chevre, Chou).
change_state(s, Loup, s, Chou, n, Loup, n, Chou).
change_state(n, Loup, n, Chou, s, Loup, s, Chou).
change_state(s, Loup, Chevre, s, n, Loup, Chevre, n).
change_state(n, Loup, Chevre, n, s, Loup, Chevre, s).

legal(P,_,C,_) :- P = C, !.
legal(P,L,_,C) :- P = L, P= C, !.

go :- pretFeuGo([(n,n,n,n)],L), out(L), !.

pretFeuGo([(s,s,s,s)|L],Path) :- reverse([(s,s,s,s)|L],Path).

pretFeuGo([(Pecor, Loup, Chevre, Chou)|L],Path) :-

    change_state(Pecor, Loup, Chevre, Chou, Pecor1, Loup1, Chevre1, Chou1),

    \+ not(legal(Pecor1, Loup1, Chevre1, Chou1)),
    
    \+ member((Pecor1, Loup1, Chevre1, Chou1),L),
    
    pretFeuGo([(Pecor1, Loup1, Chevre1, Chou1),(Pecor, Loup, Chevre, Chou)|L],Path).

%/* Sortie des differents mouvements
out([X,Y]) :-
	write(X),
	write(" => "),
	write(Y), !.
out([X,Y|Z]) :- 
    write(""),
	write(X),
    write(" => "),
    write(Y),
	writeln(""),
    append([Y],Z, L),
    out(L).
%*/

%/* Sortie graphique