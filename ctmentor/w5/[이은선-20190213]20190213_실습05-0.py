print("*20190213 이은선 실습#5")
print('')
print("*****문제1*****")
a = input("소중한 것?")
b = input("소중한 것?")
c = input("소중한 것?")
d = input("소중한 것?")
e = input("소중한 것?")
f = input("소중한 것?")
g = input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(a,b,c,d,e,f,g)
print('')
print("*****문제2*****")
p = input("내게 소중한 것?")
p1, p2, p3, p4, p5, p6, p7 = p.split()
print("="*12)
print("소중한 것 7가지")
print("="*12)
print(p1)
print(p2)
print(p3)
print(p4)
print(p5)
print(p6)
print(p7)
print("")
print(p1, p2, p3, p4, p5, p6, p7)
print('')
print("*****문제3*****")
msg = "오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며 자기의유익을구하지아니하며"
msg1, msg2, msg3, msg4, msg5 ,msg6 = msg.split()
print("사랑은 %s" %msg1)
print("사랑은 %s" %msg2)
print("사랑은 %s" %msg3)
print("사랑은 %s" %msg4)
print("사랑은 %s" %msg5)
print("사랑은 %s" %msg6)
print('')
print("*****문제4*****")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))
print('')
print("*****문제5*****")
datetoday = input("Today Date??")
year, month, day = datetoday.split("/")
print("{}년 {}월 {}일".format(year, month, day))
