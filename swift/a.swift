var h = -6
var rectifyOutput = (h > 0) ? h : 0
print(rectifyOutput)

var threshold = 5.0
let num1 = 1
let num2 = -1
var p = 1.5
var thresholdOutput = (threshold > p) ? num1 : num2
print(thresholdOutput)

var x = 7
var evenOdd = (x % 2 == 0) ? "even" : "odd"
print(String(x) + " is " + evenOdd)

var g = 10
var evenNumber = (g % 2 == 0) ? true : false
if evenNumber {
    print("It is an even number")
}

var d1 = 1.11 - 1.10 
var d2 = 2.11 - 2.10
if abs(d1 - d2) == 0 {
    print("same")
} else {
    print("different")
}

var t1 = 1.11 - 1.10 
var t2 = 2.11 - 2.10
let epsilon = 0.001
if abs(t1 - t2) <= epsilon {
    print("Same")
} else {
    print("Different")
}

var value = 9.5
if value < 0 {
    print("too small")
} else if value > 10 {
    print("too large")
} else {
    print("in range")
}
