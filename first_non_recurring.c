/*
Note: Write a solution that only iterates over the string once and uses O(1) additional memory, since this is what you would be asked to do during a real interview.

Given a string s, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.

Example

For s = "abacabad", the output should be
firstNotRepeatingCharacter(s) = 'c'.

There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

For s = "abacabaabacaba", the output should be
firstNotRepeatingCharacter(s) = '_'.

There are no characters in this string that do not repeat.

Input/Output

[time limit] 500ms (c)

[input] string s

A string that contains only lowercase English letters.

Guaranteed constraints:
1 ≤ s.length ≤ 105.

[output] char

The first non-repeating character in s, or '_' if there are no characters that do not repeat.

[C] Syntax Tips

// Prints help message to the console
// Returns a string
char * helloWorld(char * name) {
    char * answer = malloc(strlen(name) + 8);
    printf("This prints to the console when you Run Tests");
    strcpy(answer, "Hello, ");
    strcat(answer, name);
    return answer;
}

*/


char firstNotRepeatingCharacter(char * s)
{
    int L[26][2] = {0};
    int letter;
    
    for (int i = 0; i < strlen(s); i++)
    {
        letter = s[i] - 'a';
        if (!L[letter][0])
            L[letter][1] = i;
        L[letter][0]++;
    }
    
    char answer = '_';
    int index = strlen(s) + 1;
    for (int i = 0; i < 26; i++)
    {
        if (L[i][0] == 1 && L[i][1] < index)
        {
            index = L[i][1];
            answer = s[L[i][1]];
        }    
    }
    return answer;
}
