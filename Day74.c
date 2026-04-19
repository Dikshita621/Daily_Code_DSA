/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.**/
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];   // stores unique names
    int count[MAX] = {0};        // stores vote counts
    int unique = 0;

    // Input votes
    for(int i = 0; i < n; i++) {
        char temp[NAME_LEN];
        scanf("%s", temp);

        int found = -1;

        // Check if name already exists
        for(int j = 0; j < unique; j++) {
            if(strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        // If found → increment count
        if(found != -1) {
            count[found]++;
        } 
        // Else → add new name
        else {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[NAME_LEN];

    for(int i = 0; i < unique; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if(count[i] == maxVotes) {
            // Lexicographically smaller
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
