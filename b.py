import pandas as pd

# 讀取完整轉系資料
df = pd.read_csv("total.csv")

# 去除學院名稱空白，避免誤判
df["原始學院"] = df["原始學院"].str.strip()
df["轉系後學院"] = df["轉系後學院"].str.strip()

# 隨機抽樣 25 筆資料（固定隨機種子以利重現）
sample_df = df.sample(n=100)
#sample_df = df.sample(n=25, random_state=42)

# 加入是否跨學院欄位
sample_df["跨學院"] = sample_df["原始學院"] != sample_df["轉系後學院"]

# 統計結果
cross_count = sample_df["跨學院"].sum()
total = len(sample_df)
ratio = cross_count / total

# 輸出統計
print(f"抽樣總數：{total}")
print(f"跨學院轉系人數：{cross_count}")
print(f"跨學院轉系比例：{ratio:.3f}")
#print(sample_df[["學號", "原始學院", "轉系後學院", "跨學院"]])
