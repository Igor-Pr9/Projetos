#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// Definições de direções
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Definindo o tamanho máximo da cobra
#define MAX_SNAKE_LENGTH 100

// Estrutura para representar uma coordenada (x, y)
typedef struct {
    int x;
    int y;
} Position;

void init_ncurses() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(100);  // Tempo de espera para capturar tecla
}

void end_ncurses() {
    endwin();
}

Position generate_food(int max_width, int max_height) {
    Position food;
    food.x = rand() % max_width;
    food.y = rand() % max_height;
    return food;
}

void draw_snake(Position *snake, int snake_length) {
    for (int i = 0; i < snake_length; i++) {
        mvprintw(snake[i].y, snake[i].x, "#");
    }
}

void draw_food(Position food) {
    mvprintw(food.y, food.x, "O");
}

int check_collision(Position *snake, int snake_length, int max_width, int max_height) {
    // Verifica se a cobra colidiu com as paredes
    if (snake[0].x < 0 || snake[0].x >= max_width ||
        snake[0].y < 0 || snake[0].y >= max_height) {
        return 1;
    }

    // Verifica se a cobra colidiu com seu próprio corpo
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return 1;
        }
    }

    return 0;
}

void move_snake(Position *snake, int snake_length, int direction) {
    // Move o corpo da cobra
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // Move a cabeça da cobra de acordo com a direção
    switch (direction) {
        case UP:    snake[0].y--; break;
        case DOWN:  snake[0].y++; break;
        case LEFT:  snake[0].x--; break;
        case RIGHT: snake[0].x++; break;
    }
}

int main() {
    int ch, score = 0;
    int direction = RIGHT;
    Position snake[MAX_SNAKE_LENGTH];
    int snake_length = 5;

    // Inicializa a posição da cobra no centro da tela
    for (int i = 0; i < snake_length; i++) {
        snake[i].x = 10 - i;
        snake[i].y = 10;
    }

    // Inicializa o ncurses
    init_ncurses();
    
    // Define o tamanho máximo da tela
    int max_width, max_height;
    getmaxyx(stdscr, max_height, max_width);

    // Gera a primeira posição do alimento
    srand(time(NULL));
    Position food = generate_food(max_width, max_height);

    // Loop principal do jogo
    while (1) {
        clear();

        // Exibe o placar
        mvprintw(0, 0, "Score: %d", score);

        // Desenha a comida e a cobra
        draw_food(food);
        draw_snake(snake, snake_length);

        // Verifica se o jogador pressionou uma tecla
        ch = getch();
        switch (ch) {
            case KEY_UP:
                if (direction != DOWN) direction = UP; break;
            case KEY_DOWN:
                if (direction != UP) direction = DOWN; break;
            case KEY_LEFT:
                if (direction != RIGHT) direction = LEFT; break;
            case KEY_RIGHT:
                if (direction != LEFT) direction = RIGHT; break;
            case 'q':
                end_ncurses(); exit(0);  // Sai do jogo ao pressionar 'q'
        }

        // Move a cobra
        move_snake(snake, snake_length, direction);

        // Verifica se a cobra comeu o alimento
        if (snake[0].x == food.x && snake[0].y == food.y) {
            if (snake_length < MAX_SNAKE_LENGTH) {
                snake_length++;
            }
            score++;
            food = generate_food(max_width, max_height);
        }

        // Verifica colisão
        if (check_collision(snake, snake_length, max_width, max_height)) {
            break;
        }

        refresh();
    }

    end_ncurses();
    printf("Game Over! Score: %d\n", score);
    return 0;
}
