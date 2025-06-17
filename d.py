import pandas as pd

# 讀取資料
df = pd.read_csv("total.csv")

# 去除學院名稱空白
df["原始學院"] = df["原始學院"].str.strip()
df["轉系後學院"] = df["轉系後學院"].str.strip()

# 替換異體字，標準化學院名稱
replace_dict = {
    "理工學院": "理工學院",
    "管理學院": "管理學院"
}

df["原始學院"] = df["原始學院"].replace(replace_dict)
df["轉系後學院"] = df["轉系後學院"].replace(replace_dict)


# 判斷是否為跨學院轉系
df["是否跨院"] = df["原始學院"] != df["轉系後學院"]

# 以原始學院分組，統計跨院人數與總數
summary = df.groupby("原始學院").agg(
    總轉系人數 = ("學號", "count"),
    跨院轉系人數 = ("是否跨院", "sum")
)

# 計算比例
summary["跨院比例"] = summary["跨院轉系人數"] / summary["總轉系人數"]

# 顯示結果
print(summary)
