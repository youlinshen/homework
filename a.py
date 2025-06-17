import pandas as pd

# 讀取資料
data = pd.read_csv("total.csv")

# 計算跨學院與否
data["跨學院"] = data["原始學院"] != data["轉系後學院"]

# 統計結果
cross_count = data["跨學院"].sum()
total = len(data)
cross_ratio = cross_count / total

# 輸出結果
print(f"總樣本數：{total}")
print(f"跨學院轉系人數：{cross_count}")
print(f"跨學院轉系比例：{cross_ratio:.3f}")
