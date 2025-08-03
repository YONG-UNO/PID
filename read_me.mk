1.git选择添加版本管理
2.管理远程:添加仓库地址
3.新建忽略文件:cmake-build-debug/.gitignore

.idea/         # 忽略CLion配置目录
*.exe          # 忽略所有exe文件
pid_data.csv   # 忽略特定CSV文件

4.取消追踪:
git rm -r --cached .idea/  # 移除目录跟踪
git rm --cached main.exe   # 移除文件跟踪