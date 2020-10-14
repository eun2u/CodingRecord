import java.util.ArrayList;
	
public class Solution {

		public static void main(String[] args) {
			// TODO Auto-generated method stub
			int[][] board= {{0,0,1,0,0},{0,0,1,0,0},{0,2,1,0,0},{0,2,1,0,0},{0,2,1,0,0}};
			int[] moves= {1,2,3,3,2,3,1};
			
			int result= solution(board,moves);
			System.out.println(result);
		}
		
		public static int solution(int[][] board, int[] moves) {
	        int answer = 0;
	        int n=board.length;	        
	        int m=moves.length;
	        ArrayList<Integer> basket= new ArrayList<Integer>();
	        int idx=0;

	        while(idx<m){
	            int moveloc=moves[idx]-1;
	            
	            for(int i=0;i<n;i++){
	                if(board[i][moveloc]!=0){
	                	//basket이 비었
	                	if(basket.isEmpty()==true) {
	                		basket.add(board[i][moveloc]);
	                		board[i][moveloc]=0;
	                		break;
	                	}
	                	//basket top에 있는 인형과 넣을 인형이 같
	                    if(basket.get(basket.size()-1)==board[i][moveloc]){
	                        basket.remove(basket.size()-1);
	                        answer+=2;
	                		board[i][moveloc]=0;
	                        break;
	                    }
	                    else { 
	                        basket.add(board[i][moveloc]);
	                        board[i][moveloc]=0;
	                        break;
	                    }
	                }
	            }
	            
	            idx++;
	        }
	        
	        return answer;
	    }	
	}



