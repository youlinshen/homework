#student_main <- read.csv("https://github.com/youlinshen/programming-homework/raw/refs/heads/main/R/HW2-Student-Main.csv")
#fees <- read.csv("https://github.com/youlinshen/programming-homework/raw/refs/heads/main/R/HW2-Fees.csv")
#student_payment <- read.csv("https://github.com/youlinshen/programming-homework/raw/refs/heads/main/R/HW2-Student-Payment.csv")

#student_main <- read.csv("HW2-Student-Main.csv")
#fees <- read.csv("HW2-Fees.csv")
#student_payment <- read.csv("HW2-Student-Payment.csv")

student_main <- data.frame(
  student_id = c(920121001, 920121002, 920121003, 920121004, 920121005,
                 920121006, 920121007, 920121008, 920121009, 920121010,
                 920121011, 920121012, 920121013, 920121014, 920121015,
                 920121016, 920121017, 920121018),
  name = c("Andy", "Bob", "Cecil", "Dennis", "Edward", "Felix", "Gigi",
           "Helen", "Iris", "Jane", "Kate", "Liz", "Martin", "Nancy",
           "Oscar", "Pattie", "Quinn", "Rebecca"),
  payment_type = c("A", "B", "C", "A", "B", "C", "B", "B", "B", "A", "B",
                   "C", "A", "B", "C", "B", "B", "B")
)


fees <- data.frame(
  payment_type = c("A", "B", "C"),
  fee_amount = c(0, 21345, 42690)
)


student_payment <- data.frame(
  student_id = c(920121005, 920121009, 920121003, 920121017, 920121012,
                 920121002, 920121014, 920121018, 920121011, 920121006,
                 920121015, 920121008),
  Amount = c(21345, 21345, 42690, 21345, 21345, 21345, 15000, 21345, 20000,
             42690, 21345, 10000)
)


total_received <- sum(student_payment$Amount)
cat("Total amount received from students before due:", total_received, "\n")

data <- merge(student_main, student_payment, by = "student_id", all.x = TRUE)
data$Amount[is.na(data$Amount)] <- 0
data <- merge(data, fees, by = "payment_type", all.x = TRUE)

data$amount_short <- data$fee_amount - data$Amount

students_short <- data[data$amount_short > 0, ]

cat("Students who did not pay the required fees and the amount short:\n")
print(students_short[, c("name", "amount_short")])