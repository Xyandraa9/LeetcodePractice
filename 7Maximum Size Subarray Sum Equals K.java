public class Solution {
    public int maxLenZeroSumSubarray(int[] arr) {
      int maxLen=0;
      int runningSum=0;

      HashMap<Integer, Integer> map = new HashMap<>();
      map.put(0,-1);  // put sum -1 in index 0 in case the first index is part of subarray itself
      
      for(int i =0; i<arr.length; i++){
        runningSum += arr[i];

        if(map.containsKey(runningSum)){
          maxLen = Math.max(maxLen, i - map.get(runningSum));
        }
        else{
          map.put(runningSum,i);
        }
      }
      return maxLen;
    }
}
