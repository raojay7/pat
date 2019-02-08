
import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    //判断是否为回文串
    static boolean  isPalindromic(String s1){
        return new StringBuffer(s1).reverse().toString().equals(s1);
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(new BufferedInputStream(System.in));
        BigInteger n = sc.nextBigInteger();
        int k=sc.nextInt();
        int cnt=0;
        BigInteger ans=null;
        //先验证是否是回文串
        if (isPalindromic(n.toString())||k==0){
            System.out.println(n);
            System.out.println(0);
            return;
        }
        while (cnt < k) {
            BigInteger tmp1=n;
            BigInteger tmp2=new BigInteger(new StringBuffer(n.toString()).reverse().toString());
            ans=tmp1.add(tmp2);
            cnt++;
            if (isPalindromic(ans.toString())){
                break;
            }
            n=ans;
        }

        System.out.println(ans);
        System.out.println(cnt);
    }


}

