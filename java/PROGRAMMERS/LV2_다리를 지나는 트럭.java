import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int[] endTime = new int[truck_weights.length];
        Queue<Integer> onBridge = new LinkedList<Integer>();
        int time = 0, cur = 0;
        while(true) {
            if (!onBridge.isEmpty() && endTime[onBridge.peek()] == time) {
                weight += truck_weights[onBridge.poll()];
            }
            
            if (cur < truck_weights.length && truck_weights[cur] <= weight) {
                onBridge.add(cur);
                endTime[cur] = time + bridge_length;
                weight -= truck_weights[cur];
                cur++;
            }
            
            time++;
            if(onBridge.isEmpty())
                break;
        }
        return time;
    }
}