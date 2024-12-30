# 读取 CSV 文件
fees <- read.csv("HW2-Fees.csv", stringsAsFactors = FALSE)

# 查看数据结构，确保 Amount 列是数值型
head(fees)
str(fees)

# 确保 Amount 列是数值型，如果是字符型则转换为数值型
#fees$Amount <- as.numeric(fees$Amount)

# 查看处理后的数据
head(fees)

# 计算总金额
total_amount <- sum(fees$Amount, na.rm = TRUE)
cat("Total amount:", total_amount, "\n")
