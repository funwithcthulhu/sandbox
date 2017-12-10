// Problem from codefights.com
// checks a sudoku puzzle for validity

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
void transpose(arr_arr_char grid);
bool valid(arr_arr_char grid);
bool valid_subgrids(arr_arr_char grid);
    
bool sudoku2(arr_arr_char grid)
{
    if (!valid(grid))
    {
        return false;
    }
    if (!valid_subgrids(grid))
    {
        return false;
    }
    transpose(grid);
    if (!valid(grid))
    {
        return false;
    }
    return true;
}

bool valid(arr_arr_char grid)
{
    char table[256] = {0};
    for (int i = 0; i < grid.size; i++)
    {
        memset(table, 0, 256);
        for (int j = 0; j < 9; j++)
        {
            if (grid.arr[i].arr[j] != '.')
            {
                table[grid.arr[i].arr[j]]++;
            }
        }
        for (int k = 0; k < 256; k++)
        {
            if (table[k] > 1)
            {
                return false;
            }
        }
    }
    return true;
}

void transpose(arr_arr_char grid)
{
    char temp;
    for (int i = 0; i < grid.size - 1; i++)
    {
        for (int j = i + 1; j < grid.size; j++)
        {
            temp = grid.arr[i].arr[j];
            grid.arr[i].arr[j] = grid.arr[j].arr[i];
            grid.arr[j].arr[i] = temp;
        }
    }
}

bool valid_subgrids(arr_arr_char grid)
{
	char table[256] = {0};
	for (int k = 0; k < grid.size; k += 3)
	{
        int j = 0;
		for (int t = 0; t < 3; t++)
		{
			memset(table, 0, 256);
			for (int i = k; i < k + 3; i++)
			{
				for (int q = j; q < j + 3; q++)
				{
					if (grid.arr[i].arr[q] != '.')
					{
						table[grid.arr[i].arr[q]]++;
						if (table[grid.arr[i].arr[q]] > 1)
						{
                            printf("%c\n", grid.arr[i].arr[q]);
							return false;
						}
					}
				}
			}
			j += 3;
		}
	}
	return true;
}