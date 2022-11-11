class Solution {
public:
    vector<string> letterCombinations(string digits) {
        char keyStrArr[10][4] = {{0,0,0,0},{0,0,0,0},{'a','b','c',0},
                                 {'d','e','f',0},{'g','h','i',0},{'j','k','l',0},
                                 {'m','n','o',0},{'p','q','r','s'},{'t','u','v',0},
                                 {'w','x','y','z'}};
        int numCharArr[10] = {-1,-1,3,3,3,3,3,4,3,4};
        vector<string> ans;
        int digitArr[4] = {0,0,0,0};
        int digitsSize = digits.size();
        if(digitsSize == 0){
            return ans;
        }
        for(int i=0;i<digitsSize;i++){
            digitArr[i] = digits[i] - '0'; //convert ascii to int
        }
            switch(digitsSize){
                case 1:
                    for(int i=0; i < numCharArr[digitArr[0]]; i ++){
                        std::string s(1, keyStrArr[digitArr[0]][i]);
                        ans.push_back(s);
                    }
                    break;
                case 2:
                    for(int i=0; i < numCharArr[digitArr[0]];i++){
                        for(int j=0; j < numCharArr[digitArr[1]];j++){
                            ans.push_back(std::string()+keyStrArr[digitArr[0]][i] + keyStrArr[digitArr[1]][j]);
                        }
                    }
                    break;
                case 3:
                    for(int i=0; i < numCharArr[digitArr[0]];i++){
                        for(int j=0; j < numCharArr[digitArr[1]];j++){
                            for(int k=0; k<numCharArr[digitArr[2]];k++){
                                ans.push_back(std::string()+
                                keyStrArr[digitArr[0]][i] +
                                keyStrArr[digitArr[1]][j] +
                                keyStrArr[digitArr[2]][k]);
                            }
                        }
                    }
                    break;

                case 4:
                    for(int i=0; i < numCharArr[digitArr[0]];i++){
                        for(int j=0; j < numCharArr[digitArr[1]];j++){
                            for(int k=0; k<numCharArr[digitArr[2]];k++){
                                for(int l=0; l<numCharArr[digitArr[3]];l++){
                                    ans.push_back(std::string()+
                                                  keyStrArr[digitArr[0]][i] +
                                                  keyStrArr[digitArr[1]][j] +
                                                  keyStrArr[digitArr[2]][k] +
                                                  keyStrArr[digitArr[3]][l]);
                                }
                            }
                        }
                    }
                    break;
            }
        return ans;
    }
};