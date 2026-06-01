class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>>adj = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }
        int[] indegree = new int[numCourses];
        for(int[] a: prerequisites){
            indegree[a[0]]++;
            adj.get(a[1]).add(a[0]);
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
             q.offer(i);
        }
        int completedCount=0;
        int[] result = new int[numCourses];
        List<Integer> ordering = new ArrayList<>();
        while(q.isEmpty()==false){
            int curr = q.poll();
            result[completedCount++]=curr;
            for(int a: adj.get(curr)){
                indegree[a]--;
                if(indegree[a]==0)
                  q.offer(a);
            }
        }
        if(completedCount!=numCourses)
         return new int[0];
        return result;
    }
}
