#include<iostream>
#include<vector>
#include<unordered_map>
#include<stdlib.h>
#include <random>
using namespace std;


// A simple solution is to create an array reservoir[] of maximum size k. 
// One by one randomly select an item from stream[0..n-1]. If the selected item is not previously selected, 
// then put it in reservoir[]. 
// To check if an item is previously selected or not, we need to search the item in unordered_map. 
// This can be costly if k is big. We can know from math, that the exceptions of chosen item would repeat a lot 
// after many items already been selected.
class Game {
public:
    vector<vector<char> > generateMine(int x, int y, int mineNum) {
        srand (time(NULL));
        vector<vector<char> > board(x, vector<char>(y, 'E'));
        unordered_map<int, char> occupide;
        int cnt = 0;
        while(cnt < mineNum) {
            int chosen = rand()% (x*y);
            if(occupide.count(chosen)) {
                continue;
            } else {
                cnt++;
                board[chosen/y][chosen%y] = 'M';
                occupide[chosen] = 'M';
            }
        }
        return board;
    }
};


// 1) Create an array reservoir[0..k-1] and copy first k items of stream[] to it.
// 2) Now one by one consider all items from (k+1)th item to nth item.
//    a. Generate a random number from 0 to i where i is index of current item in stream[]. 
//       Let the generated random number is j.
//    b. If j is in range 0 to k-1, replace reservoir[j] with arr[i]

// Mathematical Induction 
// we must prove that the probability that any item stream[i] where 0 <= i < n will 
// be in final reservoir[] is k/n.
// Let us divide the proof in two cases as first k items are treated differently.

// Case 1: For last n-k stream items, i.e., for stream[i] where k <= i < n
// For every such stream item stream[i], we pick a random index from 0 to i and 
// if the picked index is one of the first k indexes, we replace the element at 
// picked index with stream[i]

// To simplify the proof, let us first consider the last item. 
// The probability that the last item is in final reservoir = The probability that 
// one of the first k indexes is picked for last item = k/n (the probability of 
// picking one of the k items from a list of size n)

// Let us now consider the second last item. 
// The probability that the second last item is in final reservoir[] = [Probability
// that one of the first k indexes is picked in iteration for stream[n-2]] X 
// [Probability that the index picked in iteration for stream[n-1] is not same as 
// index picked for stream[n-2] ] = [k/(n-1)]*[(n-1)/n] = k/n.

// Similarly, we can consider other items for all stream items from stream[n-1] 
// to stream[k] and generalize the proof.

// Case 2: For first k stream items, i.e., for stream[i] where 0 <= i < k
// The first k items are initially copied to reservoir[] and may be removed 
// later in iterations for stream[k] to stream[n]. 
// The probability that an item from stream[0..k-1] is in final array = 
// Probability that the item is not picked when items stream[k], stream[k+1], …. stream[n-1] 
// are considered = [k/(k+1)] x [(k+1)/(k+2)] x [(k+2)/(k+3)] x … x [(n-1)/n] = k/n

class GameRS {
public:
vector<vector<char> > generateMine(int x, int y, int mineNum) {
    srand (time(NULL));
    vector<vector<char> > board(x, vector<char>(y, 'E'));
    vector<int> pool(x*y);
    vector<int> chosen(mineNum);
    for(int i=0; i<x*y; i++) pool[i] = i;
    for(int i=0; i<mineNum; i++) chosen[i] = i;
    for(int i=mineNum; i<x*y; i++) {
        int m = rand() % x*y;
        if(m < mineNum) chosen[m] = pool[i];
    }
    for(int i=0; i<mineNum; i++) {
        board[chosen[i]/y][chosen[i]%y] = 'M';
    }
    return board;
}
};

// vector<vector<char> > generateMine2(int x, int y, int mineNum) {
//     vector<vector<char> > board(x, vector<char>(y, 'E'));
//     for(int i=0; i<mineNum; i++) {
//         board[i/y][i%y] = 'M';
//     }
//     for(int i=mineNum; i<x*y; i++) {
//         srand (time(NULL));
//         int m = rand() % x*y;
//         if(i != m) swap(board[i/y][i%y], board[m/y][m%y]);
//     }
//     return board;
// }
// };

int main() {
    GameRS game;
    Game game1;
    //vector<vector<char> > board = game1.generateMine(4, 5, 8);
    vector<vector<char> > board = game.generateMine(4, 5, 8);
    for(int i=0; i<4; i++) {
        for(int j=0; j<5; j++) {
            cout<<board[i][j]<<", ";
        }
        cout<<endl;
    }
    return 1;
}

