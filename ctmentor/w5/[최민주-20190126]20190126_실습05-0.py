#문제 1
print("***** 문제 1 *****")
m1=input("소중한 것?")
m2=input("소중한 것?")
m3=input("소중한 것?")
m4=input("소중한 것?")
m5=input("소중한 것?")
m6=input("소중한 것?")
m7=input("소중한 것?")
print("@@@ 내게 소중한 것 7가지")
print(m1, m2, m3, m4, m5, m6, m7)
print()

#문제 2
print("***** 문제 2 *****")
msg=input("내게 소중한 것?")
msg1, msg2, msg3, msg4, msg5, msg6, msg7=msg.split()
print("="*12); print("소중한 것 7가지"); print("="*12)
print(msg1);print(msg2);print(msg3);print(msg4);print(msg5);print(msg6);
print(msg7)
print()
print(msg1, msg2, msg3, msg4, msg5, msg6, msg7)
print()

#문제 3
print("***** 문제 3 *****")
msg="오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며\
 자기의유익을구하지아니하며"
msg1, msg2, msg3, msg4, msg5, msg6=msg.split()
print("사랑은 %s" % msg1)
print("사랑은 %s" % msg2)
print("사랑은 %s" % msg3)
print("사랑은 %s" % msg4)
print("사랑은 %s" % msg5)
print("사랑은 %s" % msg6)
print()

#문제 4
print("***** 문제 4 *****")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))
print()

#문제 5
print("***** 문제 5 *****")
year, month, day = input("Today Date??").split('/')
print("{}년 {}월 {}일".format(year, month, day))
print()
