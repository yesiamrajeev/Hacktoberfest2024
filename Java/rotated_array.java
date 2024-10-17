// You are using Java
import java.util.*;
class sample
{
    public static void main(String[] args)
    {
        Scanner vis=new Scanner(System.in);
        int[] arr={1,2,3,4,5};
        int k=vis.nextInt();
        for(int i=0;i<k;i++)
        {
            int j=1;
            int z=arr[0];
            while(j<arr.length)
            {
                int v=arr[j];
                arr[j]=z;
                z=k;
            }
            arr[i]=z;
        }
        for(int v:arr)
        {
            System.out.println(v);
        }
    }
}
