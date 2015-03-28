%Liste des elements du probleme
poisson(Proprio) :- probleme(Pb), member(house(Proprio, _, poisson, _, _), Pb).

append_(A, B, Ls) :- append(_, [A,B|_], Ls) ; append(_, [B,A|_], Ls).
appendL_(A, B, Ls) :- append(_, [B,A|_], Ls).


%house (NMaison Nationnalite, Couleur, Animal, Consommation, Fume)
probleme(Pb) :- 
    length(Pb, 5),
  member(house( anglais, rouge, _, _, _), Pb),
    member(house( suedois, _, chiens, _, _), Pb),
  member(house( danois, _, _, the, _), Pb),
  appendL_(house(_, verte, _, _, _), house(_, blanche, _, _, _), Pb),
  member(house( _, verte, _, cafe, _), Pb),
  member(house( _, _, oiseaux, _, pallMall), Pb),
  member(house( _, jaune, _, _, dunHill), Pb),
  Pb = [ _, _,house(_, _, _, lait, _), _, _],
    Pb = [house(norvegien, _, _, _, _)| _],
  append_(house(_, _, _, _, blend), house(_, _, chat, _, _), Pb),
  append_(house(_, _, cheval, _, _), house(_, _, _, _, dunHill), Pb),
  member(house(_, _, _, biere, blueMaster), Pb),
  member(house(allemand, _, _, _, prince), Pb),
    append_(house(norvegien, _, _, _, _), house(_, bleu, _, _, _), Pb),
  append_(house(_, _, _, _, blend), house(_, _, _, eau, _), Pb),
    member(house(_, _, poisson, _, _), Pb), !.
