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



class GameCards {
    let deck : RandomDeckOfCards
    private var top = 0
    init(){
        self.deck = RandomDeckOfCards()
    }
    func remainingNumOfCards() -> Int{
        return 52 - top
    }
    func getFiveCards() -> [Card] {
        let getNum = 5
        var fiveCards = [Card]()
        if self.remainingNumOfCards() >= getNum{
            for i in top...top+getNum-1{
                let card = deck.cards[i]
                fiveCards.append(card)
            }
            top += getNum
        }
        return fiveCards
    }
}



struct Hand {
    let fiveCards : [Card]
    init(from game: GameCards){
        self.fiveCards = game.getFiveCards()
    }
    func straightFlush()-> Bool {
        return self.straight() && self.flush()
    }
    func flush() -> Bool{
        var setSuit = Set<Suit>()
        for card in fiveCards {
            let suit = card.getSuit()
            setSuit.insert(suit)
        }
        return setSuit.count == 1
    }
    func straight() -> Bool{
        return false
    }
    
    func fourOfaKind() -> Bool{
        var setRank = Set<Rank>()
        var set2Rank = Set<Rank>()
        for card in fiveCards {
            let rank = card.getRank()
            if setRank.contains(rank){
                set2Rank.insert(rank)
            } else {
                setRank.insert(rank)
            }
        }
        if setRank.count == 2 && set2Rank.count == 1 {
            return true
        }
        return false
    }
    func threeOfaKind() -> Bool{
        return false
    }
    func onePair() -> Bool{
        return false
    }
    func separate() -> Bool{
        return false
    }

}



enum Category : Int {
 case straightFlush = 1, fourOfaKind, fullHouse, flush, straight, threeOfaKind,
twoPair, onePair, separate
}
