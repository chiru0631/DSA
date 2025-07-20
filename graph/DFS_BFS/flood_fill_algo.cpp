//733. Flood Fill

/*
You are given an image represented by an m x n grid of integers image,
where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent 
(pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and 
modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
*/

/*

    i will use dfs traversal to solve this problem.
    Approach:
    i need 2 functions to solve this problem:
    1. floodFill function to perform the flood fill operation.
    2. dfs function to traverse the image and change the color of the pixels.

    floodFill function:
        1. take the initial colour of the image at the starting pixel (sr, sc).
        int initialColor = image[sr][sc];
        2. vector<vector<int>>ans = image; // create a copy of the image to store the modified image
        3. call the dfs function to traverse the image and change the color of the pixels.
        4. drow and dcol vectors to store the directions for 4-directional movement.
            vector<int> drow = {-1, 0, 1, 0};
            vector<int> dcol = {0, 1, 0, -1};
        5. dfs(sr, sc, image, ans, initialColor, color, drow, dcol);
        6. return ans; // return the modified image

    dfs function:
        1. image[sr][sc] = color; // change the color of the pixel at (sr, sc)
        2. itrate through the 4 directions using drow and dcol vectors.
        for(int i=0; i<4; i++){
            int newrow = sr + drow[i];
            int newcol = sc + dcol[i];
            if(newrow >= 0 && newrow < image.size() && newcol >= 0 && newcol < image[0].size() && 
               image[newrow][newcol] == initialColor && ans[newrow][newcol] != color) {
                dfs(newrow, newcol, image, ans, initialColor, color, drow, dcol); // recursively call dfs for the adjacent pixel
            }
        }
        3. return; // return from the dfs function
*/

/*
    time complexity: O(m * n) where m is the number of rows and n is the number of columns in the image
    space complexity: O(m * n) for the ans vector and recursion stack
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>>& ans, int initcolour, int color, vector<int>& drow, vector<int>& dcol){
    ans[sr][sc]=color;
    for(int i=0; i<4; i++){
        int newrow = sr + drow[i];
        int newcol = sc + dcol[i];
        if(newrow >= 0 && newrow < image.size() && newcol >=0 && newcol < image[0].size() && 
           image[newrow][newcol] == initcolour && ans[newrow][newcol] != color) {
            dfs(newrow, newcol, image, ans, initcolour, color, drow, dcol); // recursively call dfs for the adjacent pixel
        }
    }
}

vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initcolor=image[sr][sc];
    vector<vector<int>> ans = image; // create a copy of the image to store the modified image
    vector<int> drow = {-1, 0, 1, 0}; // directions for 4-directional movement
    vector<int> dcol = {0, 1, 0, -1}; // directions for 4-directional movement
    dfs(sr, sc, image, ans, initcolor, color, drow, dcol);
    return ans; // return the modified image
}

int main() {
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    
    vector<vector<int>> result = floodfill(image, sr, sc, color);
    
    // Output the modified image
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}