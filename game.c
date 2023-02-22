#include "game.h"

int map[MAP_WIDTH][MAP_HEIGHT];
int passedTime = 0;

void random_init(){
    for(int y = MAP_HEIGHT - 1;y >= 0; y--){
        for(int x = MAP_WIDTH - 1;x >= 0; x--){
            map[x][y] = get_rand_i(0, 2);
        }
    }
}

void init_map(){
    for(int y = MAP_HEIGHT - 1;y >= 0; y--){
        for(int x = MAP_WIDTH - 1;x >= 0; x--){
            map[x][y] = 0;
        }
    }
    map[9][8] = 1;
    map[8][9] = 1;
    map[7][8] = 1;
}

void start(){
    srand(time(NULL));
    random_init();
}

void print_map(){
    int debug = 0;

    printf("\nTime: %d\n", passedTime);
    for(int y = MAP_HEIGHT - 1; y >= 0; y--){
        for(int x = MAP_WIDTH - 1; x >= 0; x--){
            if(debug == 1){
                printf("(%d)[%d; %d]", map[x][y], x, y);
            }
            else
            {
                if(map[x][y] == 1){
                    printf("%s", CELL_GREEN);
                }else{
                    printf("%s", CELL_BROWN);
                }
            }
        }
        printf("\n");
    }
}

int update_map_state(){
    int aliveExist = 0;
    int newMap[MAP_WIDTH][MAP_HEIGHT];

    for(int y = MAP_HEIGHT - 1; y >= 0; y--){
        for(int x = MAP_WIDTH - 1; x >= 0; x--){
            int neighbours = get_alive_neighbours(x, y);
            //printf("\nCell [%d][%d] has %d neighbours", x, y, neighbours);
            // set cell new status
            if(map[x][y] == 1){
                if(neighbours != 2 && neighbours != 3)
                {
                    newMap[x][y] = 0;
                }else{
                    newMap[x][y] = 1;
                }
                aliveExist = 1;
            }else{
                if(neighbours == 3)
                {
                    newMap[x][y] = 1;
                }
                else
                {
                    newMap[x][y] = 0;
                }
            }
        }
    }

    if(aliveExist == 0){
        return 0;
    }
    passedTime++;

    for(int y = MAP_HEIGHT - 1; y >= 0; y--){
        for(int x = MAP_WIDTH - 1; x >= 0; x--){
            map[x][y] = newMap[x][y];
        }
    }
    //update_cells(&newMap[0][0]);
    return 1;
}

void update_cells(int* newMap){
    int size = MAP_HEIGHT * MAP_WIDTH;
    int x = 0, y = 0;
    for(int i = 0; i < size; i++){
        map[x][y] = *(newMap + i);
        x++;
        if(x == MAP_WIDTH - 1){
            y++;
            x = 0;
        }
    }
}

int get_alive_neighbours(int x, int y){
    int count = 0;
    //printf("\nCheck neighbours for [%d][%d]:", x, y);
    for(int i = y - 1; i <= y + 1; i++){
        for(int j = x - 1; j <= x + 1; j++){
            int cellY = i;
            int cellX = j;
            if(i < 0){
                cellY = MAP_HEIGHT;
            }else if(i > MAP_HEIGHT){
                cellY = 0;
            }
            if(j < 0){
                cellX = MAP_WIDTH;
            }else if(j > MAP_WIDTH){
                cellX = 0;
            }
            if(cellX == x && cellY == y) continue;
            if(map[cellX][cellY] == 1){
                //printf("\n > neighbour at [%d][%d]", cellX, cellY);
                count++;
            }else{
                //printf("\n > nothing at [%d][%d]%d", cellX, cellY, map[cellX][cellY]);
            }
        }
    }
    return count;
}

int update(){
    for(;;){
        clear_console();
        print_map();
        if (update_map_state() == 0) break;
        usleep(UPDATE_TIME);
    }
    printf("No alive left. End.");
}