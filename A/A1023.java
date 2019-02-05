import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner sc=new Scanner(new BufferedInputStream(System.in));
        BigInteger bigInteger = sc.nextBigInteger();
        String str=bigInteger.toString();
        //str数组
        int []map=new int[11];
        for (int i=0;i<map.length;i++){
            map[i]=0;
        }
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            map[c-'0']++;
        }
        BigInteger dou=bigInteger.multiply(new BigInteger("2"));
        String ans=dou.toString();
        for (int i = 0; i < ans.length(); i++) {
            char c = ans.charAt(i);
            map[c-'0']--;
        }
        boolean flag=true;
        for (int i = 0; i < map.length; i++) {
            if (map[i]!=0){
                flag=false;
                break;
            }
        }
        if (flag){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
        System.out.println(dou);
    }


}

