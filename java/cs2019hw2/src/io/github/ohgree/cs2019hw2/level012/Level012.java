package io.github.ohgree.cs2019hw2.level012;

import java.util.Scanner;

interface IntSequence {
    boolean hasNext();
    int next();
}
class IntSequenceStr implements IntSequence {
    private String numStr;
    @Override
    public boolean hasNext() {
        return !this.numStr.isEmpty();
    }
    @Override
    public int next() {
        int digit = Character.getNumericValue(numStr.charAt(0));
        numStr = numStr.substring(1);
        return digit;
    }
    public IntSequenceStr(Integer num) {
        this.numStr = num.toString();
    }
}
class BinarySequenceStr extends IntSequenceStr {
    public BinarySequenceStr(Integer num) {
        super(Integer.valueOf(Integer.toBinaryString(num)));
    }
}
public class Level012 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        String str = in.nextLine();
        int num = Integer.parseInt(str);
        in.close();
        System.out.println("Integer: " + num);
        IntSequenceStr seq = new BinarySequenceStr(num);
        System.out.print("Binary number: ");
        while(seq.hasNext())
            System.out.print(seq.next());
        System.out.println("");
    }
}
