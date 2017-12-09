// Problem from codefights.com
// Find the first repeating element of an array in O(n) time and
// O(1) space

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
int firstDuplicate(arr_integer a) {
    for (int i = 0; i < a.size; i++)
    {
        if (a.arr[abs(a.arr[i]) - 1] < 0) 
        {
            return abs(a.arr[i]);
        }
        else
        {
            a.arr[abs(a.arr[i]) - 1] = -a.arr[abs(a.arr[i]) - 1];
        }
    }
    return -1;
}