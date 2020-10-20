
public class Solution {
	public static int[] solution(int[] progresses, int[] speeds) {
    int[] answer = {};
    int n=progresses.length;
    int[] days=new int[n];
    int[] functions=new int [n];
    
    //count days
    for(int i=0;i<n;i++ ){
        int day=0;
        if((100-progresses[i])%speeds[i] ==0)
            day=(100-progresses[i])/speeds[i];
        else day=(100-progresses[i])/speeds[i] + 1;
        
        days[i]=day;
    }

    int idx=0;
    int cur=0;
    while(true){
        int cnt=0;
        int i=1;            

        while(cur+i < n){
            if(days[cur]<days[cur+i])
                break;
            cnt++;
            i++;
        }            

        if(cur+i==n){
            System.out.println(cur+"and" +i);
            break;
        }
        
        
        functions[idx++]=cnt+1;
        cur+=cnt+1;
    }
    
    int size=0;
    for(int i=0;i<n;i++)
        if(functions[i]!=0)
            size++;

    answer = new int[size];
    for(int i=0;i<size;i++)
        answer[i]=functions[i];        
    
    return answer;
}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] progresses= {95, 90, 99, 99, 80, 99};
		int[] speeds= {1, 1, 1, 1, 1, 1};
		solution(progresses, speeds);
	}

}