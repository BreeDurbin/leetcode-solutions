class Solution {
public:
    bool sumGame(string nums) {
        bool alice = true, bob = false;

        int question_marks = 0, left_question_marks = 0, right_question_marks = 0; 
        int left_sum = 0, right_sum = 0;
        int half_size = nums.size() / 2;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == '?'){
                question_marks++;
                if(i < half_size){
                    left_question_marks++;
                }
                else {
                    right_question_marks++;
                }
            }
            else{
                if(i < half_size){
                    left_sum += (nums[i] - '0');
                }
                else {
                    right_sum += (nums[i] - '0');
                }
            }
        }

        // alice gets final move and forces an inequality 
        if(question_marks  % 2 == 1) return alice;

        // even question marks so bob gets the last move
        int diff = right_question_marks - left_question_marks;
        if(left_sum - right_sum == diff / 2 * 9) return bob;

        return alice;
    }
};
