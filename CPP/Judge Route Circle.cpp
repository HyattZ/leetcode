class Solution {
public:
    bool judgeCircle(string moves) {
        int ud_count = 0;
        int lr_count = 0;
        
        for (int i = 0 ; i < moves.size(); i++){
            if ('U' == moves[i]){
                ud_count++;
            }else if ('D' == moves[i]){
                ud_count--;
            }else if ('L' == moves[i]){
                lr_count--;
            }else if ('R' == moves[i]){
                lr_count++;
            }
        }
        
        if (ud_count == 0 && lr_count == 0){
            return true;
        }else{
            return false;
        }
    }
};