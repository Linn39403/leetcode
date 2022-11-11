class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        const string Arr[9]    = {"I","II","III","IV","V","VI","VII","VIII","IX"};
        const string tenArr[9] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        const string hunArr[9] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        const int indexDigit[9]= {1,2,3,2,1,2,3,4,2}; //represents the digit number in each arr
        const string * strPtr = nullptr;
        int multiplier = 0;
        int i =0;
        while(i<s.length())
        {
            if(s[i]  == 'M'){
                ans += 1000;
                i++;
            }else {
                if(s[i] == 'C' || s[i] == 'D'){
                    strPtr = hunArr;
                    multiplier = 100;
                }else if(s[i] == 'X' || s[i] == 'L'){
                    strPtr = tenArr;
                    multiplier = 10;
                }else{
                    strPtr = Arr;
                    multiplier = 1;
                }
                //loop each arr
                for(int j=8;j>-1;j--)
                {
                    switch(indexDigit[j]){
                        case 1:
                            if(s[i] == strPtr[j][0]){
                                i++;
                                ans +=  (j+1) * multiplier;
                                j = -1; //break the loop;
                            }
                            break;
                        case 2:
                            if(s[i] == strPtr[j][0] && s[i+1] == strPtr[j][1]){
                                i+=2;
                                ans +=  (j+1) * multiplier;
                                j = -1; //break the loop;
                            }
                            break;
                        case 3:
                            if(s[i] == strPtr[j][0] && s[i+1] == strPtr[j][1] && s[i+2] == strPtr[j][2]){
                                i+=3;
                                ans +=  (j+1) * multiplier;
                                j = -1; //break the loop;
                            }
                            break;
                        case 4:
                            if(s[i]   == strPtr[j][0] && s[i+1] == strPtr[j][1] &&
                               s[i+2] == strPtr[j][2] && s[i+3] == strPtr[j][3]){
                                i+=4;
                                ans +=  (j+1) * multiplier;
                                j = -1; //break the loop;
                            }
                            break;
                    }
                }
            }
        }
        return ans;
    }
};