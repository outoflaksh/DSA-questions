// WAF to reverse the order of words in a sentence string in-place
// example: "hi there hello" becomes "hello there hi"

#include <iostream>
#include <string.h>

using namespace std;

// soln: instead of reversing individual words, first reverse the whole sentence
// "hi there" becomes "ereht ih" => this actually changes the order
// all that's left now is to re-reverse the individual words


void reverseChars(string& s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;
        right--;
    }
}


void reverseWords(string& message)
{
    reverseChars(message, 0, message.length()-1);
    
    int currStart = 0;
    int currEnd = 0;
    
    while (currEnd <= message.length()) {
        if (currEnd == message.length() || message[currEnd] == ' ' ) {
            reverseChars(message, currStart, currEnd-1);
            currStart = currEnd + 1;
        }
        
        currEnd++;
    }

}

int main() {
	string str = "hi there hello";
	reverseWords(str);
	string str2 = "avengers infinity war";
	reverseWords(str2);
	cout << str << endl; // hello there hi
	cout << str2 << endl; // war infinity avengers
}

// Time: O(N) & Space: O(1)