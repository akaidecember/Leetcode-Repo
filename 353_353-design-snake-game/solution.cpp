// Link: https://leetcode.com/problems/design-snake-game/description
// Description
// Design a
// Snake game
// that is played on a device with screen size
// height x width
// .
// Play the game online
// if you are not familiar with the game.
// The snake is initially positioned at the top left corner
// (0, 0)
// with a length of
// 1
// unit.
// You are given an array
// food
// where
// food[i] = (r
// i
// , c
// i
// )
// is the row and column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by
// 1
// .
// Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.
// When a piece of food appears on the screen, it is
// guaranteed
// that it will not appear on a block occupied by the snake.
// The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies
// after
// moving (i.e. a snake of length 4 cannot run into itself).
// Implement the
// SnakeGame
// class:
// SnakeGame(int width, int height, int[][] food)
// Initializes the object with a screen of size
// height x width
// and the positions of the
// food
// .
// int move(String direction)
// Returns the score of the game after applying one
// direction
// move by the snake. If the game is over, return
// -1
// .
// Example 1:
// Input
// ["SnakeGame", "move", "move", "move", "move", "move", "move"]
// [[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
// Output
// [null, 0, 0, 1, 1, 2, -1]
// Explanation
// SnakeGame snakeGame = new SnakeGame(3, 2, [[1, 2], [0, 1]]);
// snakeGame.move("R"); // return 0
// snakeGame.move("D"); // return 0
// snakeGame.move("R"); // return 1, snake eats the first piece of food. The second piece of food appears at (0, 1).
// snakeGame.move("U"); // return 1
// snakeGame.move("L"); // return 2, snake eats the second food. No more food appears.
// snakeGame.move("U"); // return -1, game over because snake collides with border
// Constraints:
// 1 <= width, height <= 10
// 4
// 1 <= food.length <= 50
// food[i].length == 2
// 0 <= r
// i
// < height
// 0 <= c
// i
// < width
// direction.length == 1
// direction
// is
// 'U'
// ,
// 'D'
// ,
// 'L'
// , or
// 'R'
// .
// At most
// 10
// 4
// calls will be made to
// move
// .

class SnakeGame {
private:
    deque<pair<int, int>> dq;
    set<pair<int,int>> st;
    int score, height, width;
    vector<vector<int>> grid;
    vector<vector<int>> food;
    pair<int,int> snake_pos;

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) : score(0), height(height), width(width) {
        this->food = vector<vector<int>>(food.begin(), food.end());
        grid = vector<vector<int>>(height, vector<int>(width, 0));

        if(this->food.size() != 0){
            grid[this->food[0][0]][this->food[0][1]] = 1;
        }

        snake_pos = {0,0};

        dq.push_back(snake_pos);
        st.insert({0,0});
    }
    
    int move(string dir) {
        if(dir == "L"){
            snake_pos = {snake_pos.first, snake_pos.second - 1};
        }
        else if(dir == "R"){
            snake_pos = {snake_pos.first, snake_pos.second + 1};
        }
        else if(dir == "U"){
            snake_pos = {snake_pos.first - 1, snake_pos.second};
        }
        else if(dir == "D"){
            snake_pos = {snake_pos.first + 1, snake_pos.second};
        }

        int col = snake_pos.first, row = snake_pos.second;

        if(col < 0 || col >= height || row < 0 || row >= width || st.find({col, row}) != st.end()){
            return -1;
        }

        if(grid[col][row] == 1){
            score++;
            grid[col][row] = 0;

            if(food.size() != 0){
                food.erase(food.begin());
                if(!food.empty()){
                    grid[food[0][0]][food[0][1]] = 1;
                }
            }
        }

        st.insert({col, row});
        dq.push_back({col, row});

        while(dq.size() > score){
            auto temp = dq.front();
            st.erase(temp);
            dq.pop_front();
        }
        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
