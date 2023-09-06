/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        return binarySearch(1,n);
    }

    int binarySearch(int min, int max){
        //We guess halfway between min and max
        int mid = min + (max - min)/2;
        int response = guess(mid);

        //If mid(our guess) is the correct answer
        if(response == 0) return mid;
        //If our guess is low we guess with a new scope of mid + 1 to max
        else if(response > 0) return binarySearch(mid + 1, max);
        //If our guess is high we guess with a new scope of min and mid - 1
        else return binarySearch(min, mid - 1);
    }
};