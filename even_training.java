import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        String str = in.nextLine().replaceAll("[0\\s]", "");
        in.close();
        
        int count = str.length();
        System.out.println( ( (count&1)==1 ? "No " : "Yes ")+count );
       
    }
}

