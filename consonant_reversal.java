import java.io.*;
import java.util.*;

public class Solution {
    private static boolean isVower(char c){
        if ( c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        else
            return false;
    }
    private static void reverseString(String str){
        int len = str.length();
        char cur[] = str.toCharArray();
        int left = 0;
        int right = len-1;
        while(left<right){
            if ( isVower(cur[left]))
                left++;
            else if (isVower(cur[right]))
                right--;
            else
            {
                char c = cur[left];
                cur[left] = cur[right];
                cur[right] = c;
                left++;
                right--;
            }
        }
        System.out.println(new String(cur));
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        try {
           BufferedReader in = new BufferedReader( new InputStreamReader(System.in));
           int n = Integer.parseInt( in.readLine().trim());
        
           for(int i=0; i<n; ++i)
           {
               String str = in.readLine().trim();
               reverseString(str);
           }
        
           in.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
