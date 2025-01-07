male(andy).
male(bob).
male(cecil).
male(dennis).
male(edward).
male(felix).
male(martin).
male(oscar).
male(quinn).

female(gigi).
female(helen).
female(iris).
female(jane).
female(kate).
female(liz).
female(nancy).
female(pattie).
female(rebecca).

married(bob, helen).
married(dennis, pattie).
married(gigi, martin).

parent(andy, bob).
parent(bob, cecil).
parent(cecil, dennis).
parent(dennis, edward).
parent(edward, felix).
parent(gigi, helen).
parent(helen, iris).
parent(iris, jane).
parent(jane, kate).
parent(kate, liz).
parent(martin, nancy).
parent(nancy, oscar).
parent(oscar, pattie).
parent(pattie, quinn).
parent(quinn, rebecca).

parent(X, Z) :- married(X, Y), parent(Y, Z).

siblings(Y, Z) :- parent(X, Y), parent(X, Z), Y \= Z.

brother(X, Y) :- siblings(X, Y), male(X), male(Y).

sister(X, Y) :- siblings(X, Y), female(X), female(Y).

cousin(Y, Z) :- siblings(W, X), parent(W, Y), parent(X, Z).
