import java.io.*;
import java.util.*;

public class smritiString {
    
    public static String largestString(String str, int m){
        char[] strarray = str.toCharArray();
        int len = strarray.length;
        int count = 0;
        int j = 1;
        int[] pos = new int[len+1];
        pos[0] = -1;
        
        while(j<len){
            if ( pos[j]>=0 && strarray[pos[j]]<strarray[j]){
                count++;
                strarray[pos[j]] = '-';
                pos[j] = pos[pos[j]];
            }
            else{
                pos[j+1] = j;
                j++;
            }
            if (count==m)
                break;
        }
        
        j = len-1;
        while(count<m){
            if (strarray[j]!='-'){
                count++;
                strarray[j] = '-';
            }
            j--;
        }
        
        StringBuilder res = new StringBuilder();
        for(char c : strarray){
            if (c!='-')
                res.append(c);
        }
        
        return res.toString();
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        try
        {
            BufferedReader buf = new BufferedReader( new InputStreamReader(System.in));
            
            int T = Integer.parseInt(buf.readLine());
            while(T-->0){
                String strline = buf.readLine().trim();
                StringTokenizer st = new StringTokenizer (strline);
                String str = st.nextToken();
                int m = Integer.parseInt(st.nextToken());
                
                String res = largestString(str, m);
                System.out.println(res);
            }
            
        }
        catch (IOException e){
            e.printStackTrace();
        }
    }
}
