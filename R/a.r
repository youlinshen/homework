#student_main <- read.csv("HW2-Student-Main.csv")
student_main <- read.csv("https://github.com/youlinshen/programming-homework/raw/refs/heads/main/R/HW2-Student-Payment.csv")
fees <- read.csv("HW2-Fees.csv")
student_payment <- read.csv("HW2-Student-Payment.csv")

total_received <- sum(student_payment$Amount)
cat("Total amount received from students before due:", total_received, "\n")

merged_data <- merge(student_main, student_payment, by = "student_id", all.x = TRUE)
merged_data$Amount[is.na(merged_data$Amount)] <- 0
merged_data <- merge(merged_data, fees, by = "payment_type", all.x = TRUE)

merged_data$amount_short <- merged_data$fee_amount - merged_data$Amount

students_short <- merged_data[merged_data$amount_short > 0, ]

cat("Students who did not pay the required fees and the amount short:\n")
print(students_short[, c("name", "amount_short")])