class Solution {
public:
    string intToRoman(int num) {
        const string Arr[9]    = {"I","II","III","IV","V","VI","VII","VIII","IX"};
        const string tenArr[9] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        const string hunArr[9] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        int arr[4] = {0,0,0,0};
        string ans = "";
        const int tenPower[3] = {10,100,1000};
        /* convert int to arr */
        for(int i=2;i>-1;i--){
            while(num>=tenPower[i]){
               arr[i+1]++;
               num-=tenPower[i];
            }
        }
        arr[0] = num;

        //START WITH THOUSAND
        while(arr[3]>=1){
            arr[3]-=1;
            ans += "M";
        }
        //HUNDREDS
        if(arr[2] != 0)
        ans += hunArr[arr[2]-1];
        //TENS
        if(arr[1] != 0)
        ans += tenArr[arr[1]-1];
        //ONES
        if(arr[0] != 0)
        ans += Arr[arr[0]-1];
        return ans;
    }
};