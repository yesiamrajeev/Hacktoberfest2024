// Problem Statement: loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
//Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
//Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//Return the minimum integer k such that she can eat all the bananas within h hours.


import java.util.Scanner;

public class kokoEatingBanana {

    public static boolean isPossible(int[] v, int h, int x) {
        int rem = h;
        for (int i = 0; i < v.length; i++) {
            int req = v[i] / x;
            rem -= req;

            if (v[i] % x != 0) {
                rem--;
            }

            if (rem == 0 && v.length == 1) {
                return true;
            } else if (rem < 0 && v.length == 1) {
                return false;
            }

            if (rem == 0 && i == v.length - 1) {
                return true;
            } else if (rem <= 0) {
                return false;
            }
        }

        return true;
    }

    public static int minEatingSpeed(int[] v, int h) {
        int max = Integer.MIN_VALUE;
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < v.length; i++) {
            max = Math.max(max, v[i]);
        }

        int low = 1;
        int high = max;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (isPossible(v, h, mid) == true) {
                ans = Math.min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int h = sc.nextInt();

        int answer = minEatingSpeed(arr, h);
        
        System.out.println(answer);
    }

}
