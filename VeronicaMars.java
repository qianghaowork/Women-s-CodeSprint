mport java.io.*;
import java.util.*;

class Range {
        private Integer left;
        private Integer right;
        public Range(int l, int r){
           left = l;
           right = r;
        }
        public Integer getLeft() {return left; }
        public Integer getRight() { return right; }
        public String toString() {
        	return "Left:" + getLeft() + ",Right:" + getRight();
        }
        
        @Override
        public boolean equals(Object o){
        	if (o==null)
        		return false;
        	if (this.getClass()!=o.getClass())
        		return false;
        	
        	Range e = (Range)o;
        	return e.left.equals(this.left) && e.right.equals(this.right);
        }
        
        @Override
        public int hashCode() {
        	return left.hashCode() + right.hashCode();
        }
    }

public class VeronicaMars {
 
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan = new Scanner ( System.in );
        int num = scan.nextInt();
        
        Range start = new Range(Integer.MIN_VALUE, Integer.MAX_VALUE);
        TreeSet<Integer> nums = new TreeSet<Integer> ();
        HashMap<Range, Integer> indextree = new HashMap<Range, Integer> ();
        indextree.put( start, 1);
        int modn = (int)Math.pow(10,9) + 7;
        
        for(int i=0; i<num; ++i){
            int value = scan.nextInt();
            nums.add(value);
            
            int l = 0;
            int r = 0;
            int prev = Integer.MIN_VALUE;
            Iterator<Integer> index = nums.iterator();
            
            boolean sign = false;
            while(index.hasNext() && !sign){
                int temp = 0;
                if ( (temp=index.next())==value ){
                    l = temp == nums.first() ? Integer.MIN_VALUE : prev;
                    r = temp == nums.last() ? Integer.MAX_VALUE : index.next();
                    sign = true;
                }                
                prev = temp;
            }
            
            Range or = new Range(l,r);
            Range lr = new Range(l, value);
            Range rr = new Range(value, r);
            Integer result = indextree.get(or);
            if (i==num-1)
                System.out.println(result);
            else
                System.out.print( result + " ");
            
            indextree.put(lr, (result*2)%modn);
            indextree.put(rr, (result*2+1)%modn);
            indextree.remove(or);
        }
    }
}
