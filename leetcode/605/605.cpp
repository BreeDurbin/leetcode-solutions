class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int flowerCount = 0;

        if(flowerbed.size() == 1 && flowerbed[0] == 1) return 0 == n;
        if(flowerbed.size() == 1 && flowerbed[0] == 0) return 1 >= n;
        if(flowerbed.size() == 2 && flowerbed[0] == 0 && flowerbed[1] == 0){ 
            return 1 >= n;
        } else if(flowerbed.size() == 2) {
            return 0 == n;
        }


        if(flowerbed[0] == 0 && flowerbed[1] == 0) flowerCount++;
        std::cout << "first flower count: " << flowerCount << std::endl;
        if(flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0) flowerCount++;     
        std::cout << "second flower count: " << flowerCount << std::endl;

        if(flowerbed.size() > 4){
            for(int i = 2; i < flowerbed.size() - 2; i++){

                if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                    flowerCount++;
                    std::cout << "inner flower count: " << flowerCount << std::endl;
                    i++;
                }

            }
        }

        std::cout << "total flower count: " << flowerCount << std::endl;
        return flowerCount >= n;
        
    }
};