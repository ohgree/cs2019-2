print("***** 문제 1 *****")
n1=input("소중한 것?")
n2=input("소중한 것?")
n3=input("소중한 것?")
n4=input("소중한 것?")
n5=input("소중한 것?")
n6=input("소중한 것?")
n7=input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(n1,n2,n3,n4,n5,n6,n7)
print()
print("**** 문제 2 *****")
m=input("내게 소중한 것?")
m1,m2,m3,m4,m5,m6,m7=m.split()
print("="*12)
print("소중한 것 7가지")
print("="*12)
print(m1)
print(m2)
print(m3)
print(m4)
print(m5)
print(m6)
print(m7)
print()
print(m1,m2,m3,m4,m5,m6,m7)
print()
print("***** 문제3 *****")
msg="""오래참고 온유하며 자랑하지아니하며 교만하지아니하며
  무례히행하지아니하며 자기의유익을구하지아니하며"""
msg1,msg2,msg3,msg4,msg5,msg6=msg.split()
print("사랑은 %s"%msg1)
print("사랑은 %s"%msg2)
print("사랑은 %s"%msg3)
print("사랑은 %s"%msg4)
print("사랑은 %s"%msg5)
print("사랑은 %s"%msg6)
print()
print("***** 문제4 *****")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))
print()
print("***** 문제5 *****")
dateToday=input("Today Date??")
year,month,day=dateToday.split('/')
print("{}".format(year)+"년","{}".format(month)+"월","{}".format(day)+"일")
