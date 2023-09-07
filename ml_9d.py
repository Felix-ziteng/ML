from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
import numpy as np

# 加载数据
malware_data = np.loadtxt('encrypt/parameters_learn/samples.txt')
benign_data = np.loadtxt('noencrypt/parameters_learn/samples.txt')
test_data = np.loadtxt('encrypt/parameters/samples.txt')

# 创建目标变量
malware_target = np.ones(len(malware_data))
benign_target = np.zeros(len(benign_data))

# 将数据合并成单个数组，并将目标变量合并
X = np.concatenate((malware_data, benign_data))
y = np.concatenate((malware_target, benign_target))

# 将数据集分为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 定义逻辑回归模型
model = LogisticRegression()

# 使用训练集拟合模型
model.fit(X_train, y_train)

# 在测试集上评估模型性能
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print('模型准确率：', accuracy)

# 预测第三组数据的标签
test_labels = model.predict(test_data)

# 计算来自恶意程序的数据百分比
malware_percentage = np.mean(test_labels)
print('来自恶意程序的数据百分比：', malware_percentage)
