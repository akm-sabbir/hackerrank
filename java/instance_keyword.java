
 Practice
 Compete
 Jobs
 Rank
 Leaderboard
  sabbirsourov 
 
Dashboard  Java  Object Oriented Programming  Java Instanceof keyword Points: 240.00 Rank: 15976
Java Instanceof keyword 
by Shafaet
Problem
Submissions
Leaderboard
Discussions
Editorial
Submitted 10 days ago • Score: 10.00 Status: Accepted
 Test Case #0
 Test Case #1
 Test Case #2

Submitted Code
Language: Java 7

 Open in editor

1
import java.util.*;
2
​
3
​
4
class Student{}
5
class Rockstar{   }
6
class Hacker{}
7
​
8
​
9
public class InstanceOFTutorial{
10
   
11
   static String count(ArrayList mylist){
12
      int a = 0,b = 0,c = 0;
13
      for(int i = 0; i < mylist.size(); i++){
14
         Object element=mylist.get(i);
15
         if(element instanceof Student)
16
            a++;
17
         if(element instanceof Rockstar)
18
            b++;
19
         if(element instanceof Hacker)
20
            c++;
21
      }
22
      String ret = Integer.toString(a)+" "+ Integer.toString(b)+" "+ Integer.toString(c);
23
      return ret;
24
   }
25
​
26
   public static void main(String []args){
27
      ArrayList mylist = new ArrayList();
28
      Scanner sc = new Scanner(System.in);
29
      int t = sc.nextInt();
30
      for(int i=0; i<t; i++){
31
         String s=sc.next();
32
         if(s.equals("Student"))mylist.add(new Student());
33
         if(s.equals("Rockstar"))mylist.add(new Rockstar());
34
         if(s.equals("Hacker"))mylist.add(new Hacker());
35
      }
36
      System.out.println(count(mylist));
37
   }
38
}
39
​
Join us on IRC at #hackerrank on freenode for hugs or bugs. 
Contest Calendar | Interview Prep | Blog | Scoring | Environment | FAQ | About Us | Support | Careers | Terms Of Service | Privacy Policy | Request a Feature
