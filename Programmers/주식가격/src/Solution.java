
public class Solution {
    public static int[] solution(int[] prices) {
        int[] answer = {};
        int n=prices.length;
        answer=new int[n];
        
        for(int cur=0;cur<n;cur++){
            int curprice=prices[cur];
            int decreases=0;            
            for(int idx=cur;idx<n;idx++){
                if(prices[idx] < prices[cur]){
                    answer[cur]=idx-cur;
                    decreases=1;
                    break;
                }
            }
            if(decreases==0)
                answer[cur]=n-cur-1;
        }
        return answer;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] prices= {1, 5, 2, 1, 1, 5, 3, 7, 9};
		int[] result;
		
		result=solution(prices);
		for(int ret: result)
			System.out.print(ret +" ");
		
	}

}