class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";

        cout << "chars size " << chars.size() << endl;

        int storage_ptr = 0;
        int group_start_ptr = 0;

        while(group_start_ptr < chars.size()){
            int group_size = 1;
            chars[storage_ptr++] = chars[group_start_ptr];
            while((group_start_ptr+group_size) < chars.size() && chars[group_start_ptr+group_size] == chars[group_start_ptr]){
                group_size++;
            }
            group_start_ptr += group_size;
            if(group_size > 1){
                recursive_count(chars, storage_ptr, group_size);
            }
        }

        return storage_ptr;
    }

    private:
    
    void recursive_count(vector<char>& chars, int& storage_ptr, int group_size){
        if(group_size == 0) return;
        recursive_count(chars,storage_ptr,group_size/10);
        chars[storage_ptr++] = '0'+group_size%10;
    }
};