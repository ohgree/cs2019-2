print("*****문제1*****")
msg1=input("소중한 것?")
msg2=input("소중한 것?")
msg3=input("소중한 것?")
msg4=input("소중한 것?")
msg5=input("소중한 것?")
msg6=input("소중한 것?")
msg7=input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(msg1,msg2,msg3,msg4,msg5,msg6,msg7)
print("*****문제2*****")
kjh=input("내게 소중한 것?")
p1,p2,p3,p4,p5,p6,p7=kjh.split()
p1="가족";p2="연애";p3="친구";p4="희망";p5="여행";p6="자유";p7="꿈"
print("="*12);print("소중한 것 7가지");print("="*12)
print(p1);print(p2);print(p3);print(p4);print(p5);print(p6);print(p7)
print()
print(p1,p2,p3,p4,p5,p6,p7)
print("*****문제3*****")
msg="오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며\
 자기의유익을구하지아니하며"
msg1,msg2,msg3,msg4,msg5,msg6=msg.split()
msg1="오래참고";msg2="온유하며";msg3="자랑하지아니하며";msg4="교만하지아니하며"
msg5="무례히행하지아니하며";msg6="자기의유익을구하지아니하며"
print("사랑은 %s"%msg1)
print("사랑은 %s"%msg2)
print("사랑은 %s"%msg3)
print("사랑은 %s"%msg4)
print("사랑은 %s"%msg5)
print("사랑은 %s"%msg6)
print("*****문제4*****")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))
print("*****문제5*****")
dateToday=input("Today Date??")
year,month,day=dateToday.split("/")
print("{}년 {}월 {}일".format(year,month,day))


                                                                


