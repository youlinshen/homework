class Course {
    var id: Int
    var title: String
    
    init(id: Int, title: String) {
        self.id = id
        self.title = title
    }
}

var course = Course(id: 10, title: "ca")
print("course " + String(course.id) + " is " + course.title)


class Mobile {
    var make: String
    var model: String
    
    init(make: String, model: String) {
        self.make = make
        self.model = model
    }
}

let myMobile = Mobile(make: "Taiwan", model: "5s")
print(myMobile.make)

var mobile = myMobile
print(mobile.model)
myMobile.model = "8s"
print(mobile.model)

struct Mobile1 {
    var make: String
    var model: String

    init(make: String, model: String) {
        self.make = make
        self.model = model
    }
}

var myMobile1 = Mobile1(make: "Taiwan", model: "5s") 
var mobile1 = myMobile1
print(mobile1.model)
myMobile1.model = "8s"                           
print(myMobile1.model) 
print(mobile1.model)

class Straight {
    var three: Int
    
    init(three: Int) {
        self.three = three
    }
}

class Fullhouse: Straight { 
    var pair: Int
    
    init(pair: Int, three: Int) {
        self.pair = pair
        super.init(three: three)
    }
}

let fullhouse = Fullhouse(pair: 2, three: 9)
print(fullhouse.three)

class Robot {
    var withArm = true
    var withLeg: Bool
    
    init(withLeg: Bool) {
        self.withLeg = withLeg
    }
}

let robot = Robot(withLeg: true)
print(robot.withArm, robot.withLeg) 
