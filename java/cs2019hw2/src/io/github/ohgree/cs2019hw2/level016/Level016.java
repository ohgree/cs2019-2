package io.github.ohgree.cs2019hw2.level016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Text {
    private String text = "";
    public void readTextFromFile(String fileDir){
        try(BufferedReader br = new BufferedReader(new FileReader(fileDir))) {
            String in;
            while ((in = br.readLine()) != null) {
                this.text = this.text.concat(in);
            }
        } catch (IOException e) {
            System.out.println("Error: file does not exist.");
        }
    }
    public int countChar(char k) {
        return this.text.length() - this.text.replaceAll(Character.toString(k), "").length();
    }
}

public class Level016 {
    public static void main(String args[]) {
        Text t = new Text();
        t.readTextFromFile("input.txt");
        System.out.println("a: " + t.countChar('a'));
        System.out.println("b: " + t.countChar('b'));
        System.out.println("c: " + t.countChar('c'));
    }
}