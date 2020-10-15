import time;
import os;


while True :
    str_hour = time.strftime('%H');
    str_week = time.strftime('%A');
    print str_hour;
    print str_week;
    if str_hour == "21" and (str_week == "Monday" or str_week == "Wednesday" or str_week == "Saturday"):
        print "hello python";
        os.system("./xget \"http://apis.juhe.cn/lottery/query?lottery_id=dlt&key=58594838423535333832fe4fb5d05073\" > ./cjw.log");
    time.sleep(3600);
        
      
