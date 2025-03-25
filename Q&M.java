package daa_lab_set;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Prg_1 
{
    static final int MAX = 10005;
    static int[] a = new int[MAX];
    static int[] b = new int[MAX];

    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Max array size: ");
        int n = input.nextInt();

        Random random = new Random();
        System.out.println("Enter the choice:\n1. User input\n2. Random");
        int ch = input.nextInt();

        if (ch == 1) 
        {
            System.out.println("Enter the array elements: ");
            for (int i = 0; i < n; i++)
                a[i] = input.nextInt();
        } 
        else if (ch == 2) 
        {
            for (int i = 0; i < n; i++)
                a[i] = random.nextInt(1000);
        }

        b = Arrays.copyOf(a, n);

        long startTime = System.nanoTime();
        MergeSortAlgo(0, n - 1);
        long elapsedTime = System.nanoTime() - startTime;
        System.out.println("Time Complexity (ms) for n [Merge sort] = " + n + " is : " + (double) elapsedTime / 1000000);

        long startTime1 = System.nanoTime();
        QuickSortAlgorithm(0, n - 1);
        long elapsedTime1 = System.nanoTime() - startTime1;
        System.out.println("Time Complexity (ms) for n [Quick sort] = " + n + " is : " + (double) elapsedTime1 / 1000000);

        System.out.println("The difference in time: " + ((double) elapsedTime / 1000000 - (double) elapsedTime1 / 1000000));

        System.out.println("Sorted Array (Merge Sort):");
        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        
        System.out.println("\nSorted Array (Quick Sort):");
        for (int i = 0; i < n; i++)
            System.out.print(b[i] + " ");

        input.close();
    }

    public static void MergeSortAlgo(int low, int high) 
    {
        if (low < high) 
        {
            int mid = (low + high) / 2;
            MergeSortAlgo(low, mid);
            MergeSortAlgo(mid + 1, high);
            Merge(low, mid, high);
        }
    }

    public static void Merge(int low, int mid, int high) 
    {
        int[] temp = new int[MAX];
        int i = low, h = low, j = mid + 1, k;

        while (h <= mid && j <= high) 
        {
            temp[i++] = (a[h] < a[j]) ? a[h++] : a[j++];
        }

        while (h <= mid)
            temp[i++] = a[h++];
        while (j <= high)
            temp[i++] = a[j++];

        for (k = low; k <= high; k++)
            a[k] = temp[k];
    }

    public static void QuickSortAlgorithm(int p, int r) 
    {
        if (p < r) 
        {
            int pivot = b[p], i = p + 1, j = r, temp;
            while (true) 
            {
                while (i < r && b[i] < pivot) i++;
                while (b[j] > pivot) j--;
                if (i < j) 
                {
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                } 
                else 
                {
                    break;
                }
            }
            b[p] = b[j];
            b[j] = pivot;
            QuickSortAlgorithm(p, j - 1);
            QuickSortAlgorithm(j + 1, r);
        }
    }
}