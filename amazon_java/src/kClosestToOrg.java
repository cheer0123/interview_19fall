import java.util.Comparator;
import java.util.PriorityQueue;

public class kClosestToOrg {
    public static int[][] kClosest(int[][] points, int K) {

        PriorityQueue<int[]> heap = new PriorityQueue<int[]>(new Comparator<int[]>() {
            @Override
            public int compare(int[] A, int[] B) {
                return getDistance(B) - getDistance(A);
            }
        });

        for (int[] point: points) {
            heap.add(point);
            if (heap.size() > K)
                heap.poll();
        }

        int[][] result = new int[K][2];
        while (K > 0)
            result[--K] = heap.poll();

        return result;
    }

    private static int getDistance(int [] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
}
