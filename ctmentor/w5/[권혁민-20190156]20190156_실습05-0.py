print("***** 20190156 권혁민 실습 05 *****")
print()
print("*****문제 1*****")
msg1=input("소중한 것?")
msg2=input("소중한 것?")
msg3=input("소중한 것?")
msg4=input("소중한 것?")
msg5=input("소중한 것?")
msg6=input("소중한 것?")
msg7=input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(msg1,msg2,msg3,msg4,msg5,msg6,msg7)
print()
print("*****문제 2*****")
msg=input("내게 소중한 것?")
a,b,c,d,e,f,g=msg.split()
print("="*12)
print("소중한 것 7가지")
print("="*12)
print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print(g)
print()
print(a,b,c,d,e,f,g)
print()
print("*****문제 3*****")
msg="""오래참고 온유하며 자랑하지아니하며 교만하지아니하며
무례히행하지아니하며 자기의유익을구하지아니하며"""
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
dateToday=input("Today date??")
year,month,day=dateToday.split("/")
print("{}년 {}월 {}일".format(year,month,day))


