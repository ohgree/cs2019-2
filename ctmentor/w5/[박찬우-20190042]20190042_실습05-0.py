print("***** 문제 1 *****")
favorite1 = input("소중한 것? ")
favorite2 = input("소중한 것? ")
favorite3 = input("소중한 것? ")
favorite4 = input("소중한 것? ")
favorite5 = input("소중한 것? ")
favorite6 = input("소중한 것? ")
favorite7 = input("소중한 것? ")
print("@@@내게 소중한 것 7가지")
print(favorite1, favorite2, favorite3, favorite4, favorite5, favorite6, favorite7)

print("")
print("**** 문제 2 ****")
favoritethings = input("내게 소중한 것? ")
f1, f2, f3, f4, f5, f6, f7 = favoritethings.split()
print("=" * 12)
print("소중한 것 7가지")
print("=" * 12)
print(f1)
print(f2)
print(f3)
print(f4)
print(f5)
print(f6)
print(f7)
print("")
print(f1, f2, f3, f4, f5, f6, f7)

print("")
print("**** 문제 3 ****")
msg = "오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며 자기의유익을구하지아니하며"
msg1, msg2, msg3, msg4, msg5, msg6 = msg.split()
print("사랑은 %s" %msg1)
print("사랑은 %s" %msg2)
print("사랑은 %s" %msg3)
print("사랑은 %s" %msg4)
print("사랑은 %s" %msg5)
print("사랑은 %s" %msg6)

print("")
print("**** 문제 4 ****")
print("사랑은 {}".format(msg1))
print("사랑은 {}".format(msg2))
print("사랑은 {}".format(msg3))
print("사랑은 {}".format(msg4))
print("사랑은 {}".format(msg5))
print("사랑은 {}".format(msg6))

print("")
print("**** 문제 5 ****")
dateToday = input("Today Date?? ")
year, month, day = dateToday.split('/')
print("{}년 {}월 {}일".format(year, month, day))
