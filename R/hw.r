# 读取 CSV 文件
student_main <- read.csv("HW2-Student-Main.csv", stringsAsFactors = FALSE)
fees <- read.csv("HW2-Fees.csv", stringsAsFactors = FALSE)
student_payment <- read.csv("HW2-Student-Payment.csv", stringsAsFactors = FALSE)

# 查看数据是否正确加载
head(student_main)
head(fees)
head(student_payment)

# 计算总支付金额
total_received <- sum(student_payment$Amount, na.rm = TRUE)
cat("Total amount received from students before due:", total_received, "\n")

# 合并数据：将学生信息与支付信息和费用信息合并
merged_data <- merge(student_main, student_payment, by = "student_id", all.x = TRUE)
merged_data <- merge(merged_data, fees, by = "payment_type", all.x = TRUE)

# 计算短缺金额
merged_data$amount_short <- merged_data$fee_amount - merged_data$Amount

# 找出未支付足够费用的学生
students_short <- merged_data[merged_data$amount_short > 0, ]

# 打印未支付足够费用的学生及短缺金额
cat("Students who did not pay the required fees and the amount short:\n")
print(students_short[, c("name", "amount_short")])
