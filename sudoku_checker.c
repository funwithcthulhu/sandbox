/*
Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above. Note that the puzzle represented by grid does not have to be solvable.

Example

For

grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
the output should be
sudoku2(grid) = true;

For

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
the output should be
sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

Input/Output

[time limit] 500ms (c)

[input] array.array.char grid

A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.

[output] boolean

Return true if grid represents a valid Sudoku puzzle, otherwise return false.

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