import java.util.*;

public class Solution {
    static int n;
    static boolean[] visited;
    static ArrayList<Integer>[] adj;
    
    public static void makeGraph(int[][] computers){
        adj=new ArrayList[n];
       
    	for(int i = 0; i < n; i++) 
			adj[i] = new ArrayList<>();
		
    	
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) {
        		if(computers[i][j]==1) {
        			adj[i].add(j);
        			adj[j].add(i);
        		}   			
        	}
        }
    }
    public static void dfs(int here) {
    	visited[here]=true;
    	
    	for(int i=0;i<adj[here].size();i++) {
    		int there=adj[here].get(i);
    		if(visited[there]==false) 
    			dfs(there);
    	}
    }
    public static int solution(int n, int[][] computers) {
        int answer = 0;
        n=computers.length;
        visited=new boolean[n]; //false로 채워지는
        
        makeGraph(computers);
        
        for(int i=0;i<n;i++)
        	if(visited[i]==false) {
        		dfs(i);
        		answer++;
        	}
        
        return answer;
    }
    
    public static void main(String[] args) {
    	int[][] computers= {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    	
    	solution(3,computers);
    	
    }
}