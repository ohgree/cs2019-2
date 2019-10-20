print("*****문제1*****")

w1=input("소중한 것?")
w2=input("소중한 것?")
w3=input("소중한 것?")
w4=input("소중한 것?")
w5=input("소중한 것?")
w6=input("소중한 것?")
w7=input("소중한 것?")
print("@@@내게 소중한 것 7가지")
print(w1,w2,w3,w4,w5,w6,w7)

print("\n")

print("*****문제2*****")
w1,w2,w3,w4,w5,w6,w7=input("내게 소중한 것?").split()
print("="*12);print("소중한 것 7가지");print("="*12)

print(w1)
print(w2)
print(w3)
print(w4)
print(w5)
print(w6)
print(w7)

print(w1,w2,w3,w4,w5,w6,w7)

print("\n")

print("*****문제3*****")
msg="오래참고 온유하며 자랑하지아니하며 교만하지아니하며 \
무례히행하지아니하며 자기의유익을구하지아니하며"

msg1,msg2,msg3,msg4,msg5,msg6=msg.split()

print("사랑은 %s" %msg1)
print("사랑은 %s" %msg2)
print("사랑은 %s" %msg3)
print("사랑은 %s" %msg4)
print("사랑은 %s" %msg5)
print("사랑은 %s" %msg6)


print("\n")


print("*****문제4*****")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))

print("\n")

print("*****문제5*****")
year,month,day=input("Today Date??").split("/")
print("{}년 {}월 {}일".format(year,month,day))


