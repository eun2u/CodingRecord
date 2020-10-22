#include <string>
#include <vector>

using namespace std;
bool isCorrect(int y, int x, int brown, int yellow){
    int bVal=y*2 + (x-2)*2;
    if(bVal!=brown) return false;
    int yVal=(y-2)*(x-2);
    if(yVal!=yellow) return false;
    
    return true;   
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i=3;i<brown/2;i++){
        for(int j=3;j<brown/2;j++){
            if(isCorrect(i,j,brown, yellow)){
                answer.push_back(j);
                answer.push_back(i);
                return answer;
            }
        }
    }
}