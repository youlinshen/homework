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