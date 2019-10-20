package io.github.ohgree.cs2019hw2.level011;

interface IntSequence {
    public abstract boolean hasNext();
    public abstract int next();
}
class FibonacciSequence implements IntSequence{
    private int now, next;
    public FibonacciSequence() {
        this.next = 1;
        this.now = 0;
    }
    @Override
    public boolean hasNext() { return true; }
    @Override
    public int next() {
        int ret;
        ret = this.now;
        this.now = this.next;
        this.next += ret;
        return ret;
    }
}
public class Level011 {
    public static void main(String[] args) {
    	// write your code here
        IntSequence seq = new FibonacciSequence();
        for(int i=0; i<20; i++) {
            if(seq.hasNext() == false)
                break;
            System.out.print(seq.next() + " ");
        }
        System.out.println(" ");
    }
}
