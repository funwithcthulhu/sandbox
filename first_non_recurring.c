//  problem from codefights.com
// find the first non recurring character in a string
// constraints: only iterate over string once and uses 
// no more than O(1) additional memory


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
