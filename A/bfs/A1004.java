import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));
        String str=reader.readLine();
        String[] s = str.split(" ");
        int n,m;
        n=Integer.parseInt(s[0]);
        m=Integer.parseInt(s[1]);

        if(m==0) {
            System.out.print(1);
            return;
        }
        else if(n==0){
            return;
        }
        //构造树
        int id,k;
        ArrayList<Integer>[] graph=new ArrayList[n+1];//下标从1开始
        for (int i = 1; i <=n; i++) {
            graph[i]=new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            str=reader.readLine();
            s = str.split(" ");
            id=Integer.parseInt(s[0]);
            k=Integer.parseInt(s[1]);
            for (int j = 0; j < k; j++) {
                graph[id].add(Integer.parseInt(s[j+2]));
            }
        }
        //bfs
        Queue<Integer> queue=new LinkedList<>();
        queue.offer(1);
        ArrayList<Integer> res=new ArrayList<>();
        int count=0;
        while (!queue.isEmpty()){
            count=0;//初始化
            int size= queue.size();
            for (int i = 0; i < size; i++) {
                //分层次
                int tmp=queue.poll();
                if(graph[tmp].isEmpty())count++;
                else{
                    for (Integer neig:graph[tmp])queue.offer(neig);
                }
            }
            res.add(count);
        }

        for (int i = 0; i < res.size(); i++) {
            if (i==0) System.out.print(res.get(i));
            else System.out.print(" "+res.get(i));
        }
    }
}
