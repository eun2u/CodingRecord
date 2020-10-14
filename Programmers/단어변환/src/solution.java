import java.util.*;
class Solution {
     ArrayList<Integer>[] adj;
     int[] distances;
     Queue<Integer> q= new LinkedList<>();
    
    public boolean checkConvert(String a, String b){
        int n=a.length();
        int cnt=0;
        
        for(int i=0;i<n;i++)
            if(a.charAt(i) ==b.charAt(i))
                 cnt++;
            
        if(cnt==n-1) return true;
        else return false;
    }
    public int findTarget(String target, String[] nwords) {
    	for(int i=0;i<nwords.length;i++)
    		if(nwords[i].equals(target))
    			return i;
    	
    	return -1;
    }
    public void bfs(int start) {
    	
    	q.offer(start);
    	distances[start]=0;
    	while(!q.isEmpty()) {
    		int here=q.peek();
    		q.poll();
    		
    		for(int i=0;i<adj[here].size();i++) {
    			int there=adj[here].get(i);
    			
    			if(distances[there]==-1) {
    				q.offer(there);
    				distances[there]=distances[here]+1;				
    			}
    		}
    	}
    }
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        int n=words.length;
        
        String[] nwords=new String[n+1];
        nwords[0]=begin;
        for(int i=1;i<=n;i++) 
            nwords[i]=words[i-1];
        
        int targetIdx=findTarget(target, nwords);
        if(targetIdx==-1)  	return 0;
        
        adj=new ArrayList[n+1];
        for(int i=0;i<n+1;i++)
            adj[i]=new ArrayList<>();
        
        
        for(int i=0;i<n+1;i++)
            for(int j=0;j<n+1;j++)
                if(checkConvert(nwords[i], nwords[j])==true)
                    adj[i].add(j);

        
    	distances=new int[n+1];
    	for(int i=0; i<distances.length;i++)
    		distances[i]=-1;
    	
        bfs(0);
        answer=distances[targetIdx];   
        if(answer==-1) return 0;
        else  return answer;
    }
}