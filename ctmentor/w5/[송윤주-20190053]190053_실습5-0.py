print("******문제1******")
p1=input("소중한 것?")
p2=input("소중한 것?")
p3=input("소중한 것?")
p4=input("소중한 것?")
p5=input("소중한 것?")
p6=input("소중한 것?")
p7=input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(p1,p2,p3,p4,p5,p6,p7)

print("")
print("******문제2******")
precious=input("내게 소중한 것?")
precious1,precious2,precious3,precious4,precious5,precious6,precious7=precious.split()
print("="*12);print("소중한 것 7가지");print("="*12)
print(precious1)
print(precious2)
print(precious3)
print(precious4)
print(precious5)
print(precious6)
print(precious7)
print("")
print(precious1,precious2,precious3,precious4,precious5,precious6,precious7)

print("")
print("******문제3******")
msg="오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며 자기의유익을구하지아니하며"
msg1,msg2,msg3,msg4,msg5,msg6=msg.split()
print("사랑은 %s"%msg1)
print("사랑은 %s"%msg2)
print("사랑은 %s"%msg3)
print("사랑은 %s"%msg4)
print("사랑은 %s"%msg5)
print("사랑은 %s"%msg6)

print("")
print("******문제4******")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))

print("")
print("******문제5******")
dateToday=input("Today Date??")
year,month,day=dateToday.split('/')
print("{}년 {}월 {}일".format(year,month,day))
