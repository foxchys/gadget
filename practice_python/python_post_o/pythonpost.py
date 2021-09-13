import requests
import time
import numpy as np
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36'}
proxies = {
  "http": "",
}
url = 'http://'
payload = {'opid[]': '', 'activeid': '', 'code': ''}
for i in range(1,200):
    num=np.random.rand(1)
    r = requests.post(url, data = payload,proxies=proxies,headers=headers)
    print r.text
    print i
    time.sleep(3+num[0]*10)
