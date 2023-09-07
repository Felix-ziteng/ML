#!/bin/bash

# 运行脚本encript/script.sh
/encrypt/script.sh &
pid=$!
echo $pid

# 等待5h
sleep 5h

#杀死进程
kill $pid

# 运行脚本noencrypt/script.sh
/noencrypt/script.sh &
pid=$!
echo $pid

# 等待5h
sleep 5h

#杀死进程
kill $pid



