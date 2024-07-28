class Solution {

    Set<Integer>  digits = Stream.of(0,1,2,3,4,5,6,7,8,9).collect(Collectors.toCollection(HashSet::new));


    public int myAtoi(String s) {
        int n=s.length();
        if(n==0) return 0;
        int i = 0;
        long ans = 0;
        while(i < n && s.charAt(i) == ' ') ++i;

        boolean isPositive = true;
        if(i < n && s.charAt(i) == '-'){ 
            isPositive = false; 
            ++i; 
        } else if(i < n && s.charAt(i) == '+'){
            ++i;
        }

        while(i < n && Character.isDigit(s.charAt(i))){
            ans *= 10;
            ans += (int)(s.charAt(i) - '0');
            if(!isPositive && -ans < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            if(isPositive && ans > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            ++i;
        }
        return isPositive ? (int)ans : (int)-ans;
    }
}
