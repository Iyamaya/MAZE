#include<stdio.h>
int maze[127][127] = {0};
int n,min=50;
struct coordinate{								
	int x;
	int y;
}point[127];
void move(int step)							
{
	point[0].x = 1;
	point[0].y = 1;
	if(maze[point[step].y + 1][point[step].x] == 0){
		point[step + 1].x = point[step].x;
		point[step + 1].y = point[step].y + 1;
		maze[point[step].y][point[step].x] = 1;
		move(step + 1);
		maze[point[step].y][point[step].x] = 0; 
	}
	if(maze[point[step].y][point[step].x + 1] == 0){
		point[step + 1].x = point[step].x + 1;
		point[step + 1].y = point[step].y;
		maze[point[step].y][point[step].x] = 1;
		move(step + 1);
		maze[point[step].y][point[step].x] = 0; 
	}
	if(maze[point[step].y][point[step].x - 1] == 0){
		point[step + 1].x = point[step].x - 1;
		point[step + 1].y = point[step].y;
		maze[point[step].y][point[step].x] = 1;
		move(step + 1);
		maze[point[step].y][point[step].x] = 0; 
	}
	if(point[step].x == n-2 && point[step].y == n-2){
	if(min > step){
		min = step;
		}
		return;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	move(0);
	if(min == 50){
		printf("No solution");
	}else{
		printf("%d",min);
	}
}
