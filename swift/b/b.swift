import UIKit

var index = 1...5
for num in index {
    print(num*num)
}
var sum = 0
for num in index {
    sum += num
}
print(sum)


let numend = 5
let numstart = 2
for num in numstart...numend {
    print(num)
}
for num in numstart..<numend {
    print(num)
}


var a = [1, 2, 4, 5]
var su = 0
for num in a {
    su += num
}
print(su)

var deep = ["input", "output", "hidden"]
for num in deep {
    print(num)
}

