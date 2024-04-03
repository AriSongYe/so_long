## Subject Summary

## Code Flow Chart

![image](https://github.com/AriSongYe/so_long/assets/82326075/798a2c40-ea1a-4f2d-883c-f08a7dea6f17)

---

## Demands subject wants

You must use the miniLibX. Either the version that is available on the operating
system, or from its sources. If you choose to work with the sources, you will
need to apply the same rules for your libft as those written above in Common
Instructions part.
• The management of your window must remain smooth: changing to another window, minimizing, etc.
• examples are given with a dolphin theme but you can use anything you want.

- The map will be constructed with 3 components walls, collectibles, and free space.
• The player’s goal is to collect all collectibles present on the map then escape with
minimal movement.
• At every move the current number of movements must be displayed in the shell.
• The player must be able to move: up, down, left, right.
• You will use a 2D view (top-down or profile).
• The game doesn’t need to be real-time.
• player cannot move into walls.
• The program displays the image in a window and respects the following rules:
◦ The W, A, S, and D keys will be used to move the main character.
◦ Pressing ESC must close the window and quit the program cleanly.
◦ Clicking on the red cross on the window’s frame must close the window and
quit the program cleanly.
◦ The use of images of the minilibX is strongly recommended.
• Your program must take as a first argument a map description file with the .ber
extension.
◦ The map must be composed of only 5 possible characters: 0 for an empty
space, 1 for a wall, C for a collectible, E for map exit and P for the player’s
starting position.
◦ The map must be closed/surrounded by walls, if not the program must return
an error.
◦ Map must have at least one exit, one collectible, and one starting position.
◦ You don’t need to check if there’s a valid path in the map.
◦ The map must be rectangular.
◦ You must be able to parse any kind of map, as long as it respects the rules of
the map.
- 

If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.

## Map Parsing

- `argv[1]` 값으로 들어온 파일을 `open` 및 `read` 하고
- 1차원 배열로 전부 다 결합 후 `split`함수를 통해  `game` 이라는 구조체 안에 `**map` 에 넣어준다!

```c
void	read_map(t_game *game, char *file)
{
	char	*temp;
	char	buff[11];
	int		n;
	int		fd;

	temp = NULL;
	fd = open(file, O_RDONLY);
	while (1)
	{
		n = read(fd, buff, 10);
		if (n <= 0)
			break ;
		buff[n] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	game->map = ft_split(temp, '\n');
	free(temp);
}
```

## Checking Valid map

- 입력 받은 `File`이 `Subject`에서 요구하는 유효한 `Map` 인지 확인하는 과정

1. 읽어들인 맵이 직사각형인지 확인!
2. 벽으로 둘러싸여 있는가?
3. 0,1,C,E,P 다음과 같은 구성요소들이 다 들어가 있는가?

ex)

![image](https://github.com/AriSongYe/so_long/assets/82326075/2c6a5dca-c3d2-4e50-ba57-be6b043f9440)

## Map Set

읽어 들인 `Map`을 `Window`에 띄우는 과정

- 이중 `while` 문을 사용하여 2차 배열을 순서대로 읽는다.
- 읽은 문자에 부합한 image를 계산한 위치에 맞게 출력한다.
- 반복한다.

```c
void	put_image_to_window(int i, int j, t_game *g)
{
	if (g->map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->i_1, P * j, P * i);
	else if (g->map[i][j] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->i_1, P * j, P * i);
		mlx_put_image_to_window(g->mlx, g->win, g->i_2, P * j, P * i);
	}
	else if (g->map[i][j] != '0' && g->map[i][j] != '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->i_1, P * j, P * i);
		if (g->map[i][j] == 'P')
			mlx_put_image_to_window(g->mlx, g->win, g->i_3, P * j, P * i);
		else if (g->map[i][j] == 'C')
			mlx_put_image_to_window(g->mlx, g->win, g->i_4, P * j, P * i);
		else if (g->map[i][j] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->i_5, P * j, P * i);
		else if (g->map[i][j] == 'N')
		{
			mlx_put_image_to_window(g->mlx, g->win, g->i_5, P * j, P * i);
			mlx_put_image_to_window(g->mlx, g->win, g->i_3, P * j, P * i);
		}
	}
}
```

## Loop (EVENT)

EVENT, KEY 입력 혹은 MOUSE 로 인한 INPUT 을 받았을 때 처리

```c
int	keyhook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_program(game);
	else if (keycode == 13)
		move_p(game, 1, 0);
	else if (keycode == 0)
		move_p(game, 0, 1);
	else if (keycode == 1)
		move_p(game, -1, 0);
	else if (keycode == 2)
		move_p(game, 0, -1);
	return (0);
}
```

- hook 함수를 통해 keyhook 함수 혹은 자신이 넣어 놓은 함수가 실행이 된다.
- 입력된 keycode 값을 참고하여 함수를 실행시켜 원하는 동작을 구현한다.

### KeyCode
![image](https://github.com/AriSongYe/so_long/assets/82326075/2d73b019-b2db-4155-9edc-8d33f2d6a4b1)


- Memory leak 확인
    
    leaks 명령어 + ps 명령어 + shell scripts while do 구문으로 계속확인
    
    ```bash
    while :; do leaks ps_number; done
    ```
