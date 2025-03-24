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

var tenDou = Array(repeating: 0.0, count: 10)
var another = Array(repeating: 1.5, count: 10)
var sur = 0.0
for num in another {
    sur += num
}
print(sur)

var tenDou1 = Array(repeating: 2.0, count: 10)
var twentyVariables = [Double]()
twentyVariables.append(contentsOf: tenDou1)
twentyVariables.append(contentsOf: another)
var sur1 = 0.0
for num in twentyVariables {
    sur1 += num
}
print(sur1)

for (index, layer) in deep.enumerated() {
    print("layer " + String(index) + " is " + layer)
}

let max = 20
var loop = 0
while loop < max {
    loop += 1
}
print("  " + String(loop) + " loops completed")

let max1 = 20
let str = 2
let dis = 3
var nu = str
repeat{
    nu += dis
}while (nu < max1)
print("the last num " + String(nu) + " <= " + String(max1))

let max2 = 200
let sta = 2
let dis1 = 7
var nu1 = sta
let sizemax = 25
var size = 1
repeat{
    nu1 += dis1
    size += 1
}while (nu1 < max2) && (size < sizemax)
print("size " + String(size))
print(nu1)

