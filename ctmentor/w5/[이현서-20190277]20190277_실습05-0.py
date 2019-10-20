print ("***** 문제 1 *****")

변수1 = input("소중한 것?")

변수2 = input("소중한 것?")

변수3 = input("소중한 것?")

변수4 = input("소중한 것?")

변수5 = input("소중한 것?")

변수6 = input("소중한 것?")

변수7 = input("소중한 것?")

print ( "@@@내게 소중한 것 7가지")
print (변수1, 변수2, 변수3, 변수4, 변수5, 변수6, 변수7)

print()
print ("***** 문제2 *****")
a = input ("내게 소중한 것?")
변수1, 변수2, 변수3, 변수4, 변수5, 변수6, 변수7 = a.split()
print ("="*12)
print ("소중한 것 7가지")
print ("="*12)
print (변수1)
print (변수2)
print (변수3)
print (변수4)
print (변수5)
print (변수6)
print (변수7)
print (변수1,변수2, 변수3, 변수4, 변수5, 변수6, 변수7)

print()
print ("***** 문제 3 *****")
msg = "오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며 자기의유익을구하지아니하며"
msg1,msg2,msg3,msg4,msg5,msg6 = msg.split()
print ("사랑은 %s" %msg1)
print ("사랑은 %s" %msg2)
print ("사랑은 %s" %msg3)
print ("사랑은 %s" %msg4)
print ("사랑은 %s" %msg5)
print ("사랑은 %s" %msg6)

print()
print ("***** 문제4 *****")
print ("사랑은 {}". format(msg1) )
print ("사랑은 {}". format(msg2) )
print ("사랑은 {}". format(msg3) )
print ("사랑은 {}". format(msg4) )
print ("사랑은 {}". format(msg5) )
print ("사랑은 {}". format(msg6) )

print()
print ("***** 문제5 *****")
dateToday = input("Today Date??")
year, month, day = dateToday.split('/')
print ("{}년 {}월 {}일". format(year, month, day) )
