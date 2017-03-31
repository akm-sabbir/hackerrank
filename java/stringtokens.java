import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        if (s.trim().length() == 0) {
            System.out.println(0);
        } else {
            StringTokenizer tokens = new StringTokenizer(s,"[ !,?._'@]+");
            int si = tokens.countTokens();
            System.out.println(si);
            while(tokens.hasMoreTokens()){
                System.out.println(tokens.nextToken());
            }
        }
        // Write your code here.
        scan.close();
    }
}
