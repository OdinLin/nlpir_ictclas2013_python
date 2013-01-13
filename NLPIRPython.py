#-*- coding:gb2312

import NLPIR

#print hello_ext.greet()

print NLPIR.nlpir_init("./")
'''
t_filename = "test/test2.txt"
tweet_file = open(t_filename, 'r')
for line in tweet_file.readlines():
    string2 = line.decode('utf-8').encode('gb2312', 'ignore')
    tokens = NLPIR_ext.process_str(string2, 0)
    print tokens.decode('gb2312').encode('utf-8')
print NLPIR_ext.ict_exit()
'''
print NLPIR.process_str('我是傻瓜啊', 1)
print NLPIR.nlpir_exit()
