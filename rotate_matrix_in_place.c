/*
Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

Example

For

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]
Input/Output

[time limit] 500ms (c)

[input] array.array.integer a

Guaranteed constraints:
1 ≤ a.length ≤ 100,
a[i].length = a.length,
1 ≤ a[i][j] ≤ 104.

[output] array.array.integer

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
// Definition for arrays:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//
//
arr_arr_integer rotateImage(arr_arr_integer a) {

    int temp;
    for (int i = 0; i < a.size - 1; i++)
    {
        for (int j = i + 1; j < a.size; j++)
        {
            temp = a.arr[i].arr[j];
            a.arr[i].arr[j] = a.arr[j].arr[i];
            a.arr[j].arr[i] = temp;
        }
    }

    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < a.size / 2; j++)
        {
            temp = a.arr[i].arr[j];
            a.arr[i].arr[j] = a.arr[i].arr[a.size - j - 1];
            a.arr[i].arr[a.size - j - 1] = temp;
        }
    }

    return a;
}