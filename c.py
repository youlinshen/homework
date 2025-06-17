import math

# 已知抽樣資料
n = 100
x = 52
p_hat = x / n

# Z值 for 95% 信賴區間
z = 1.96

# 信賴區間計算
se = math.sqrt(p_hat * (1 - p_hat) / n)
margin = z * se
ci_lower = p_hat - margin
ci_upper = p_hat + margin

# 輸出結果
print(f"樣本比例：{p_hat:.3f}")
print(f"95% 信賴區間：({ci_lower:.3f}, {ci_upper:.3f})")
