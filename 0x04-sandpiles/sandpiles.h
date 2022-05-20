#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>


void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

void copy(int grid_result[3][3], int grid_sum[3][3]);

void toppling(int grid1[3][3]);

#endif /* SANDPILES_H */
