print("*20190083 이영선 실습5*")
print()
print("*****문제 1*****")
wic1=input("소중한 것?")
wic2=input("소중한 것?")
wic3=input("소중한 것?")
wic4=input("소중한 것?")
wic5=input("소중한 것?")
wic6=input("소중한 것?")
wic7=input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(wic1,wic2,wic3,wic4,wic5,wic6,wic7)
print()
print("*****문제 2*****")
wic=input("내게 소중한 것?")
wic1,wic2,wic3,wic4,wic5,wic6,wic7=wic.split()
print("="*12)
print("소중한 것 7가지")
print("="*12)
print(wic1)
print(wic2)
print(wic3)
print(wic4)
print(wic5)
print(wic6)
print(wic7)
print()
print(wic1,wic2,wic3,wic4,wic5,wic6,wic7)
print()
print("*****문제 3*****")
msg="오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며 자기의유익을구하지아니하며"
msg1,msg2,msg3,msg4,msg5,msg6=msg.split()
print("사랑은 %s" %msg1)
print("사랑은 %s" %msg2)
print("사랑은 %s" %msg3)
print("사랑은 %s" %msg4)
print("사랑은 %s" %msg5)
print("사랑은 %s" %msg6)
print()
print("*****문제 4*****")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))
print()
print("*****문제 5*****")
dateToday=input("Today Date??")
year,month,day=dateToday.split("/")
print("{}년 {}월 {}일".format(year,month,day))
