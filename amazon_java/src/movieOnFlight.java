import java.lang.reflect.Array;
import java.util.*;
/*
Question:
You are on a flight and wanna watch two movies during this flight.
You are given List<Integer> movieDurations which includes all the movie durations.
You are also given the duration of the flight which is d in minutes.
Now, you need to pick two movies and the total duration of the two movies is less than or equal to (d - 30min).

Find the pair of movies with the longest total duration and return they indexes. If multiple found, return the pair with the longest movie.

Example 1:

Input: movieDurations = [90, 85, 75, 60, 120, 150, 125], d = 250
Output: [0, 6]
Explanation: movieDurations[0] + movieDurations[6] = 90 + 125 = 215 is the maximum number within 220 (250min - 30min)
*/

public class movieOnFlight {
    public static int[] moviesOnFlight1(List<Integer> movieDurations, int d) {
        if (movieDurations == null || movieDurations.size() <= 1) return new int[] {-1, -1};
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < movieDurations.size(); i++) {
            int len = movieDurations.get(i);
            if (!map.containsKey(len)) map.put(len, new ArrayList<>());
            map.get(len).add(i);
        }
        Collections.sort(movieDurations);
        int target = d - 30;
        int curMax = Integer.MIN_VALUE;
        int l = 0, r = movieDurations.size() - 1;
        int[] values = new int[] {-1, -1};
        while (l < r) {
            int left = movieDurations.get(l), right = movieDurations.get(r);
            int total = left + right;
            if(total == target) {
                values[0] = left;
                values[1] = right;
                break;
            }
            else if (total < target) {
                if (total > curMax) {
                    curMax = total;
                    values[0] = left;
                    values[1] = right;
                }
                l++;
            } else {
                r--;
            }
        }
        int[] res = new int[] {-1, -1};
        if (values[0] == -1) return res;
        if (values[0] == values[1]) {
            res[0] = map.get(values[0]).get(0);
            res[1] = map.get(values[1]).get(1);
        } else {
            res[0] = map.get(values[0]).get(0);
            res[1] = map.get(values[1]).get(0);
        }
        return res;
    }
    public static void main(String[] args) {
        List<Integer> movie_duration1 = new ArrayList<>(Arrays.asList(90, 85, 75, 60, 120, 150, 125));
        List<Integer> movie_duration2 = new ArrayList<>(Arrays.asList(90, 85, 75, 60, 120, 150, 125, 125, 125));
        List<Integer> movie_duration3 = new ArrayList<>(Arrays.asList(0, 0));
        List<Integer> movie_duration4 = new ArrayList<>(Arrays.asList(10, 50, 20, 40, 30, 30, 0, 60));
        int d1 = 250, d2 = 250, d3 = 30, d4 = 90;
        System.out.println(Arrays.toString(moviesOnFlight1(movie_duration1, d1)));
        System.out.println(Arrays.toString(moviesOnFlight1(movie_duration2, d2)));
        System.out.println(Arrays.toString(moviesOnFlight1(movie_duration3, d3)));
        System.out.println(Arrays.toString(moviesOnFlight1(movie_duration4, d4)));

    }
}

