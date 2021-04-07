import re
from time import strptime
'''
思路：
   1.先分析文档写出正则表达式（后续可能需要修改）
   2.分析时间格式
   3.编写逻辑
'''
PATTERN=re.compile('(.*?) - - \[(.*?) \+\d{4}\] \".*?\" \d{3} (\d{1,9}).*?')

BEGIN_TIME = strptime('01/Apr/2021:00:00:00', '%d/%b/%Y:%H:%M:%S')
END_TIME = strptime('01/May/2021:00:00:00', '%d/%b/%Y:%H:%M:%S')
dict={}
num_request=0
byteall=0
with open('access2.log', 'r', encoding='utf-8') as f:
    for index, line in enumerate(f):
        if(re.match(PATTERN,line)):
            ip, time, byte = PATTERN.findall(line)[0]
            byteall += int(byte)
            time = strptime(time, '%d/%b/%Y:%H:%M:%S')
            if (BEGIN_TIME <= time < END_TIME):
                num_request += 1
                if (ip not in dict):
                    dict[ip] = 1
                else:
                    dict[ip] += 1
print("请求数量为:",num_request)
print("ip数量为:",len(dict))
print("发送总字节数为:",byteall)
f.close()





