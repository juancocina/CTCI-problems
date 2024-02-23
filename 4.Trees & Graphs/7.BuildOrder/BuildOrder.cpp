/*
    This is a re-do of the problem because my original attempt had too many issues and 
    did not properly answer the question. I also got a little help to better understand the problem.
    It technically did work, but I was prebuilding my input and i could not detect loops.

    4.7 Build Order: You are a given a list of projects and a list of dependencies
    (which is a list of pairs of projects, where th esecond project is dependent on 
    the first project)
    All of a project's dependencies must be built before the project is.

    Find a build order that will allow the projects to be built.
    IF there is no valid build order, return an error.
*/

#include<vector>
#include<unordered_map>
#include<iostream>
#include<list>
#include<cstdlib>
#include<utility>
#include<unordered_set>

void dfs(char c, std::unordered_map<char,std::vector<char>>& graph, std::vector<char>& result, 
std::unordered_map<char, int>& indegree) {
    result.push_back(c);

    indegree[c] -=1;

    for(auto it : graph[c]){ // visit children
        if(--indegree[it] == 0) // subtract indegree from child, pass to dfs if 0
            dfs(it, graph, result, indegree);
    }

    return;
}

std::vector<char> buildOrder(std::vector<char> projects, std::vector<std::pair<char, char>> dependencies){
    // establish adjacency list for DFS, using a 2d vector
    std::unordered_map<char, std::vector<char>> graph;
    std::vector<char> result;
    std::unordered_map<char, int> indegree;

    // create the first dimension of the graph
    for(int i = 0; i < projects.size(); i++){
        graph[projects[i]];
    }
    
    // establish indegree
    for(int i = 0; i < projects.size(); i++){
        indegree[projects[i]] = 0;
    }

    // insert the dependencies
    for(auto it = dependencies.begin(); it != dependencies.end(); ++it) {
        graph[it->first].push_back(it->second);
        indegree[it->second]++;
    }

    for(int i = 0; i < projects.size(); i++){ // iterate through projects
        if(indegree[projects[i]] == 0) { // pass projects with no dependencies
            dfs(projects[i], graph, result, indegree);
        }
    }

    if(result.size() == projects.size()) return result; // if no loops, return results

    return {}; // else return empty array
}

int main() {
    // example 1
    std::vector<char> projects1 = {'a', 'b', 'c', 'd', 'e', 'f'};

    std::vector<std::pair<char, char>> dependencies1 = { {'a', 'd'}, {'f', 'b'}, {'b', 'd'},
    {'f', 'a'}, {'d', 'c'} };
    // example output: f, e, a, b, d, c
    std::vector<char> output1 = buildOrder(projects1, dependencies1);
    for(int i = 0; i < output1.size(); i++){
        std::cout << output1[i] << " ";
    } std::cout << "\n\n";

    //example 2
    std::vector<char> projects2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::vector<std::pair<char, char>> dependencies2 = { {'f', 'c'}, {'f', 'b'}, {'f', 'a'}, {'c', 'a'}, 
    {'b', 'a'}, {'b', 'e'}, {'a', 'e'}, {'d', 'g'} };
    // example output: f, d, c, b, g, a, e
    std::vector<char> output2 = buildOrder(projects2, dependencies2);
    for(int i = 0; i < output2.size(); i++) {
        std::cout << output2[i] << " ";
    } std::cout << "\n\n";

    return 0;
}