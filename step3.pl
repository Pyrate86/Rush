change_state(s, Loup, Chevre, Chou, n, Loup, Chevre, Chou).
change_state(n, Loup, Chevre, Chou, s, Loup, Chevre, Chou).
change_state(s, s, Chevre, Chou, n, n, Chevre, Chou).
change_state(n, n, Chevre, Chou, s, s, Chevre, Chou).
change_state(s, Loup, s, Chou, n, Loup, n, Chou).
change_state(n, Loup, n, Chou, s, Loup, s, Chou).
change_state(s, Loup, Chevre, s, n, Loup, Chevre, n).
change_state(n, Loup, Chevre, n, s, Loup, Chevre, s).

illegal(s,n,n,_).
illegal(n,s,s,_).
illegal(s,_,n,n).
illegal(n,_,s,s).

go :- pretFeuGo([(n,n,n,n)],L), writeln(L), !.

pretFeuGo([(s,s,s,s)|L],Path) :- reverse([(s,s,s,s)|L],Path).

pretFeuGo([(Pecor, Loup, Chevre, Chou)|L],Path) :-

    change_state(Pecor, Loup, Chevre, Chou, Pecor1, Loup1, Chevre1, Chou1),

    \+ illegal(Pecor1, Loup1, Chevre1, Chou1),

    \+ member((Pecor1, Loup1, Chevre1, Chou1),L),

    pretFeuGo([(Pecor1, Loup1, Chevre1, Chou1),(Pecor, Loup, Chevre, Chou)|L],Path).
