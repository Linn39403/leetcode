/******************************************************************************


In this kata you have to write a simple Morse code decoder. While the Morse code is now mostly superseded by voice and digital data communication channels, it still has its use in some applications around the world.
The Morse code encodes every character as a sequence of "dots" and "dashes". For example, the letter A is coded as ·−, letter Q is coded as −−·−, and digit 1 is coded as ·−−−−. The Morse code is case-insensitive, traditionally capital letters are used. When the message is written in Morse code, a single space is used to separate the character codes and 3 spaces are used to separate words. For example, the message HEY JUDE in Morse code is ···· · −·−−   ·−−− ··− −·· ·.

NOTE: Extra spaces before or after the code have no meaning and should be ignored.

In addition to letters, digits and some punctuation, there are some special service codes, the most notorious of those is the international distress signal SOS (that was first issued by Titanic), that is coded as ···−−−···. These special codes are treated as single special characters, and usually are transmitted as separate words.

Your task is to implement a function that would take the morse code as input and return a decoded human-readable string.

*******************************************************************************/
#include <iostream>
#include <string>
const int ArrLength = 55;
const std::string morse[ArrLength] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  
const std::string ascii[ArrLength] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};

std::string decodeMorse(const std::string& morseCode);
void testAnswer(const std::string& morse, const std::string& expected);
int main()
{
    testAnswer(decodeMorse(".... . -.--   .--- ..- -.. ."),"HEY JUDE");
    testAnswer(decodeMorse(".-"), "A");
    testAnswer(decodeMorse("."), "E");
    testAnswer(decodeMorse(".."), "I");
    testAnswer(decodeMorse(". ."), "EE");
    testAnswer(decodeMorse(".   ."), "E E");
    testAnswer(decodeMorse("   .   . "), "E E");
    testAnswer(decodeMorse("      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-     "), 
    "SOS! THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.");
    return 0;
}

std::string convertMorseToASCII(const std::string& morseCode)
{
    int index = -1;
    for(int i = 0; i < ArrLength; i ++){
        if(morseCode == morse[i]){
            index = i;
        }
    }
    if(index == -1) std::cout << "SOMETHING WRONG " << std::endl;
    return ascii[index];
}

std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" ");
    if (first == std::string::npos) return ""; // All spaces
    size_t last = str.find_last_not_of(" ");
    return str.substr(first, (last - first + 1));
}

std::string decodeMorse(const std::string& morseCode) {
    std::string submorseCode = "";
    std::string ansString = "";
    std::string morseCodeTrim = trim(morseCode);
    int morseCodeLength = morseCodeTrim.length();
    for(int i = 0; i < morseCodeLength; i++){
        if(morseCodeTrim[i] != ' '){
            submorseCode += morseCodeTrim[i];
            continue; // no need to do the following if statment 
        }
        
        //for space and END OF THE CODE
        if(morseCodeTrim[i] == ' ' || (i ==morseCodeLength-1)){
            ansString += convertMorseToASCII(submorseCode);

            //check is it triple space?
            if((i+2 <= morseCodeLength ) && morseCodeTrim[i+1] == ' ' && morseCodeTrim[i+2] == ' '){
                i+=2;
                ansString += " ";
            }
            submorseCode = "";
        }
    }
    return ansString;
}

void testAnswer(const std::string& morse, const std::string& expected)
{
    if(morse != expected){
        std::cout << "WRONG: Expected = " "\"" << expected << "\"" " ,Result = " "\"" << morse << "\"";
    }else{
        std::cout << "OK: " << morse;
    }
    std::cout << "\n";
}