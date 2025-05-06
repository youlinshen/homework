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
    func flush() -> Bool{
        var setSuit = Set<Suit>()
        for card in fiveCards {
            let suit = card.getSuit()
            setSuit.insert(suit)
        }
        return setSuit.count == 1
    }
    func straight() -> Bool{
        var fiveRank = [Int]()
        for card in fiveCards {
            let r = card.getRank().rawValue
            fiveRank.append(r)
        }
        fiveRank.sort()
        if fiveRank[0] == 1 && fiveRank[1] == 10 &&
            fiveRank[2] == 11 && fiveRank[3] == 12 && fiveRank[4] == 13 {
            return true
        }
        for i in 0...fiveRank.count-2{
            let d = fiveRank[i+1] - fiveRank[i]
            if d != 1{
                return false
            }
        }
        return true
    }
    func straightFlush()-> Bool {
        return self.straight() && self.flush()
    }
    func onePair() -> Bool {
        var setRank = Set<Rank>()
        for card in fiveCards {
            let rank = card.getRank()
            setRank.insert(rank)
        }
        return setRank.count == 4
    }
    func separate() -> Bool {
        var setRank = Set<Rank>()
        for card in fiveCards {
            setRank.insert(card.getRank())
        }
        return setRank.count == 5
    }
    func threeOfaKind() -> Bool {
        var setRank = Set<Rank>()  
        var set2Rank = Set<Rank>()
        for card in fiveCards {
        let rank = card.getRank()
            if setRank.contains(rank) {
                set2Rank.insert(rank) 
            } else {
                setRank.insert(rank)   
        }
        }
        if setRank.count == 4 && set2Rank.count == 1 {
            return true
        }
        return false
    }
}



enum Category : Int {
    case straightFlush = 1, fourOfaKind, fullHouse, flush, straight, threeOfaKind,
         twoPair, onePair, separate
}



func cat2string(cat: Category) -> String{
    switch cat.rawValue {
    case 1:
        return "straightFlush"
    case 2:
        return "fourOfaKind"
    case 3:
        return "fullHouse"
    case 4:
        return "flush"
    case 5:
        return "straight"
    case 6:
        return "threeOfaKind"
    case 7:
        return "twoPair"
    case 8:
        return "onePair"
    default:
        return "separate"
    }
}







let  game = GameCards()
let play = Hand(from: game)
print(play.straight())
for card in play.fiveCards{
    print("\(card.getSuit().rawValue),\(card.getRank().rawValue)")
}

import SwiftUI

enum Suit : Character {
    case spades = "♠", hearts = "♡", dimonds = "♢", clubs = "♣"
}
enum Rank : Int {
    case ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen,
         king
}

enum Category : Int {
    case straightFlush = 1, fourOfaKind, fullHouse, flush, straight, threeOfaKind,
         twoPair, onePair, separate
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

func cat2string(cat: Category) -> String{
    switch cat.rawValue {
    case 1:
        return "straightFlush"
    case 2:
        return "fourOfaKind"
    case 3:
        return "fullHouse"
    case 4:
        return "flush"
    case 5:
        return "straight"
    case 6:
        return "threeOfaKind"
    case 7:
        return "twoPair"
    case 8:
        return "onePair"
    default:
        return "separate"
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
        var fiveRank = [Int]()
        for card in fiveCards {
            let r = card.getRank().rawValue
            fiveRank.append(r)
        }
        fiveRank.sort()
        if fiveRank[0] == 1 && fiveRank[1] == 10 &&
            fiveRank[2] == 11 && fiveRank[3] == 12 && fiveRank[4] == 13 {
            return true
        }
        for i in 0...fiveRank.count-2{
            let d = fiveRank[i+1] - fiveRank[i]
            if d != 1{
                return false
            }
        }
        return true
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
    func setCategory() -> Category {
     if self.straightFlush() {
     return Category.straightFlush
     }
     if self.fourOfaKind() {
     return Category.fourOfaKind
     }
     
     if self.flush() {
     return Category.flush
     }
     if self.threeOfaKind() {
     return Category.threeOfaKind
     }
     
     if self.onePair() {
     return Category.onePair
     }
     return Category.separate
     }
}


struct ContentView: View {
    @State private var catString = ""
    @State private var fivelCards = ""
    @State private var remainingNum : Int = 52
    var game = GameCards()
    var body: some View{
        Form {
            Text("\(remainingNum) cards")
    
            
            Button("Get Five Cards") {
                if game.remainingNumOfCards() > 10 {
                    let hand = Hand(from: game)
                    let category = hand.setCategory()
                    
                    remainingNum = game.remainingNumOfCards()
                    catString = cat2string(cat: category)
                    
                    fivelCards = hand.fiveCards.map { card in
                        let suit = String(card.getSuit().rawValue)
                        let rank = String(card.getRank().rawValue)
                        return suit + rank
                    }.joined(separator: " ")
                }
            }
        }
    }
}
struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
