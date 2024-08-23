import matplotlib.pyplot as plt
import pandas as pd

# 读取文件内容
with open('E:\\Project\\cpp\\ProgrammingPractice\\Homework\\03-program-optimization-homework\\doc\\time_record_100.txt', 'r') as file:
    data = file.read().splitlines()

# 初始化数据存储
results = {'N': [], 'i-j-k': [], 'i-k-j': [], 'j-i-k': [], 'j-k-i': [], 'k-i-j': [], 'k-j-i': []}

# 初始化临时存储当前N的结果
current_N = None
current_results = {}

# 解析文件内容
for line in data:
    if line.startswith('N='):
        # 如果当前N不为空且已经有记录了，保存当前记录
        if current_N is not None:
            for key in current_results:
                results[key].append(current_results.get(key, 0.0))
        current_N = int(line.split('=')[1])
        current_results = {'N': current_N}  # 初始化当前N的结果
    elif '=' in line and current_N is not None:
        key, value = line.split('=')
        if key in results:  # 检查 key 是否是我们关心的
            current_results[key] = float(value)

# 最后一组数据也需要保存
if current_N is not None:
    for key in current_results:
        results[key].append(current_results.get(key, 0.0))

# 将数据转换为DataFrame
df = pd.DataFrame(results)

# 绘制图像
plt.figure(figsize=(10, 6))

for key in ['i-j-k', 'i-k-j', 'j-i-k', 'j-k-i', 'k-i-j', 'k-j-i']:
    plt.plot(df['N'], df[key], marker='o', label=key)

plt.xlabel('N')
plt.ylabel('time(s)')
plt.title('Addition time of different loop order')
plt.xticks(df['N'])  # 设置横轴刻度只显示 N 的实际值
plt.legend()
plt.grid(True)
plt.show()
