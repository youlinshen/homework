import UIKit

enum Suit : Character {
    case spades = "♠", hearts = "♡", dimonds = "♢", clubs = "♣"
}



enum Rank : Int {
    case ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen,
         king
}



class Card {
    private let rank: Rank
    private let suit: Suit
    init(_ rank: Rank, of suit: Suit){
        self.rank = rank
        self.suit = suit
    }
    func getRank() -> Rank {
        return rank
    }
    func getSuit() -> Suit{
        return suit
    }
    func compareSuit(with otherCard: Card) -> Bool{
        return self.suit == otherCard.suit
    }
    func compareRank(with otherCard: Card) -> Bool{
        return self.rank == otherCard.rank
    }
}



let a = Card(.ace, of: .spades)
let q = Card(.queen, of: .hearts)
print(a.getRank(), a.getSuit())
print(q.getRank(), q.getSuit())
print(q.getSuit().rawValue, q.getRank().rawValue)
print(a.compareRank(with: q))
print(a.compareSuit(with: q))

let suits = [Suit.spades, Suit.hearts, Suit.dimonds, Suit.clubs]
let ranks = [Rank.ace, Rank.two, Rank.three, Rank.four, Rank.five, Rank.six,
             Rank.seven, Rank.eight, Rank.nine, Rank.ten, Rank.jack, Rank.queen,
             Rank.king]



struct RandomDeckOfCards {
    let cards: [Card]
    init(){
        var allCards = [Card]()
        for suit in suits{
            for rank in ranks{
                let card = Card(rank, of: suit)
                allCards.append(card)
            }
        }
        self.cards = allCards.shuffled()
    }
}
