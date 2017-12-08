// code for rotating a 2D array by 90 degrees in place (O(1) space)
// problem from codefights.com interview prep section
// constraints: arrays are square

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