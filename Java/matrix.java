//transpose of the matrix
import java.util.Scanner;//importing scanner class
public class matrix
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no. of rows");
        int rows=sc.nextInt();
        System.out.println("Enter the no. of columns");
        int columns=sc.nextInt();
        int A[][]=new int[rows][columns];
        System.out.println("Enter elements of matrix");
        for(int i=0;i<rows;i++)//to input the elements from the user
        {
            for(int j=0;j<columns;j++)
            {
                A[i][j]=sc.nextInt();
            }
        }
        System.out.println("ORIGINAL MATRIX");
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                System.out.print(A[i][j]+"    ");
            }
            System.out.println();
        }
        System.out.println("TRANSPOSE OF THE MATRIX");
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                System.out.print(A[j][i]+"    ");
            }
            System.out.println();
        }
    }
}
