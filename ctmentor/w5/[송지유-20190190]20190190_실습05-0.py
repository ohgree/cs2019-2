print("*****문제 1*****")
v1=input("소중한 것?")
v2=input("소중한 것?")
v3=input("소중한 것?")
v4=input("소중한 것?")
v5=input("소중한 것?")
v6=input("소중한 것?")
v7=input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(v1,v2,v3,v4,v5,v6,v7)
print()
print("*****문제 2*****")
i=input("내게 소중한 것?")
i1,i2,i3,i4,i5,i6,i7=i.split()
print("="*15);print("소중한 것 7가지");print("="*15)
print(i1)
print(i2)
print(i3)
print(i4)
print(i5)
print(i6)
print(i7)
print()
print(i1,i2,i3,i4,i5,i6,i7)
print()
print("*****문제 3*****")
msg="오래참고 온유하며 자랑하지아니하며 교만하지아니하며 \
무례히행하지아니하며 자기의유익을구하지아니하며"
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
dateToday=input("Today Date?")
year,month,day=dateToday.split('/')
print("{}년 {}월 {}일".format(year,month,day))
