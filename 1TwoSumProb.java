//BruteForce

// class Solution {
//     public int[] twoSum(int[] nums, int target) {
//         for(int i =0; i<nums.length;i++){
//             int complement = target-nums[i];
//             for(int j = i+1; j<nums.length;j++){
//                 if(nums[j] == complement){
//                     return new int[]{i,j};
//                 }
                
//             }
//         }
//         return new int[]{-1,-1};
//     }
// }

// O(n) optimised using hashmaps

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i =0; i<nums.length;i++){
            int complement = target-nums[i];
            if(map.containsKey(complement)){
                return new int[]{map.get(complement),i};
            }
            map.put(nums[i],i);
        }
        return new int[]{-1,-1};
    }
}