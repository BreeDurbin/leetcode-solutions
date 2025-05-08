class Solution {
    public String mergeAlternately(String w1, String w2) {
        StringBuilder ans = new StringBuilder();
        int n = Math.max(w1.length(), w2.length());

        for(int i = 0; i<n; i++){
            if(i < w1.length()) ans.append(w1.charAt(i));
            if(i < w2.length()) ans.append(w2.charAt(i));
        }

        return ans.toString();
    }
}
