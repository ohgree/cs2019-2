print("20190058 신현빈 제5회 과제")
print()
print("***** 문제 1 *****")
a=input("소중한 것? (1번에 한 단어만 입력하십시오.):");b=input("소중한 것?:");c=input("소중한 것?:");d=input("소중한 것?:");e=input("소중한 것?:");f=input("소중한 것?:");g=input("소중한 것?:")
print("@@@내게 소중한 것 7가지");print(a,b,c,d,e,f,g);print()
print("***** 문제 2 *****")
a=input("내게 소중한 것 (7가지를 모두 입력하시오. 띄어쓰기 필수.):");m1,m2,m3,m4,m5,m6,m7=a.split();print()
print("="*12);print("소중한 것 7가지");print("="*12);print()
print(m1);print(m2);print(m3);print(m4);print(m5);print(m6);print(m7);print();print(m1,m2,m3,m4,m5,m6,m7);print()
print("***** 문제 3 *****")
msg= "오래참고 온유하며 자랑하지아니하며 교만하지아니하며 무례히행하지아니하며 자기의유익을구하지아니하며"
msg1,msg2,msg3,msg4,msg5,msg6=msg.split()
print("사랑은 %s" %msg1);print("사랑은 %s" %msg2);print("사랑은 %s" %msg3);print("사랑은 %s" %msg4);print("사랑은 %s" %msg5);print("사랑은 %s" %msg6);print()
print("***** 문제 4 *****")
print("사랑은 {}".format(msg1));print("사랑은 {}".format(msg2));print("사랑은 {}".format(msg3));print("사랑은 {}".format(msg4));print("사랑은 {}".format(msg5));print("사랑은 {}".format(msg6));print()
print("***** 문제 5******")
dateToday=(input("What is Today Date?:"));year,month,day=dateToday.split('/')
print(year+"년",month+"월",day+"일")
