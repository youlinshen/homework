# 读取 CSV 文件，使用 na.strings 处理空值，并去除末尾的空行
student_main <- read.csv("HW2-Student-Main.csv", stringsAsFactors = FALSE, na.strings = c("", "NA"))
fees <- read.csv("HW2-Fees.csv", stringsAsFactors = FALSE, na.strings = c("", "NA"))
student_payment <- read.csv("HW2-Student-Payment.csv", stringsAsFactors = FALSE, na.strings = c("", "NA"))

# 去除数据框中的空行
#student_main <- na.omit(student_main)
#fees <- na.omit(fees)
#student_payment <- na.omit(student_payment)

# 查看数据是否正确加载
head(student_main)
head(fees)
head(student_payment)

# 清理金额列：去除逗号并转换为数值
student_payment$Amount <- as.numeric(student_payment$Amount)
fees$fee_amount <- as.numeric(fees$fee_amount)

# 计算总支付金额
total_received <- sum(student_payment$Amount, na.rm = TRUE)  # 确保忽略 NA 值
cat("Total amount received from students before due:", total_received, "\n")

# 合并数据：将学生信息与支付信息和费用信息合并
merged_data <- merge(student_main, student_payment, by = "student_id", all.x = TRUE)
merged_data <- merge(merged_data, fees, by = "payment_type", all.x = TRUE)

# 计算短缺金额
merged_data$amount_short <- merged_data$fee_amount - merged_data$Amount

# 去除金额短缺列中为 NA 的行
students_short <- merged_data[merged_data$amount_short > 0, ]

# 打印未支付足够费用的学生及短缺金额
cat("Students who did not pay the required fees and the amount short:\n")
print(students_short[, c("name", "amount_short")])
