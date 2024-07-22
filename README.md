# War---cpp-Project
The 3rd class project in cpp course: A game of "War".

The game of "War" is a simple multiplayer card game based on luck.
The standart deck of cards is distributed equally between all players, each round every players reveals the top card from his hand and the player with the highest card wins the round and collect the cards shown. 
If there is a tie the players with the highest card are in a "Duel".
In Duel the players place three more cards and the last placed card is the dueling card where the highest one wins.
When a player finishes his deck of cards he picks up the cards that he won, shuffles them and they are now his new deck.

A player loses when he no longer has cardsb.

In this assignment we were given a partial realization of the game but all of the operators definitions and friend access were deleted.
We were supposed to understand alone what to complete and how to complete it.

The assignments are:
1. Search and complete "friend" classes that were erased.
2. Identify and complete the missing operators:

    a. operator #1 - adding a card to the hand of the player that runs the operator.
                    use example: *(players.players[playerIdx]) += (Cards[cardIdx++]);
   
    b. operator #2- removing n cards from the hand running the operator to his "trash" pile and returning the last card to his "trash" pile.
                    use example: if(!isFirst)
                                    tmp=(*(participant[no])) -3
                                 else
                                    tmp=(*(participant[no])) - 1;
                    
    c. operator #3 - check if the card running the operator is greater than the other card.
                    use example:  if(*tmp > *max)

    d. operator #4 - check if the card running the operator is equal to the other card.
                    use example:  if(*tmp == *max)

   e. operator #5 - add all the cards from the trash pile of a certain player to the hand of another player using operator #1. make sure it's a different player.
                    use example:  *winner + *(players.players[playerIdx]);
    
