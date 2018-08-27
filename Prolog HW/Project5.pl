%Author: Kazon Wilson
%Project 5

%mymember

mymember(X,[X|End]).

mymember(X,[Y|Tail]):- mymember(X,Tail).


%myeven

myeven(X):- 0 =:= X mod 2.


%myevennumber

myevennumber(0,[]).

myevennumber(X, [Head|Tail]):- myeven(Head), myevennumber(Y,Tail), X is Y+1.

myevennumber(X, [Head|Tail]):- \+ myeven(Head),myevennumber(X,Tail).


%myminlist

myminlist([X],X).

myminlist([M| Tail], M) :- myminlist(Tail, Y), M < Y.

myminlist([Head|Tail], M) :- myminlist(Tail, M), M < Head.


%palindrome
%First, define a reverse function

rev([],[]).
rev([H|T],L):-
    rev(T,R),
    append(R,[H],L).

% Reverse the list, if the reverse list is equal to the original list,
% return true.
palindrome(X) :- rev(X,X).


%leafcount

leafcount(nil, 0).
leafcount(t(_,L,R), T) :- leafcount(L,Nl),leafcount(R,Nr),
    ( (L=nil,R\=nil ; L\=nil,R=nil) -> C = 1 ; C = 0 ),
    T is Nl + Nr + C.



