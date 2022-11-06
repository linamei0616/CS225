/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;

// helper function
std::map<char, unsigned int> check_word(std::string word) { // returns a map which is a list of words and their count
    std::map<char, unsigned int> map;
    for (char letter : word) {
        map[letter]++;
    }
    return map;
}

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    std::vector<std::string> vect_words;
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
        /* Reads a line from `wordsFile` into `word` until the file ends. */
        while (getline(wordsFile, word)) {
            vect_words.push_back(word);
        }
    }
    for (std::string w : vect_words) {
        if (dict.find(w) == dict.end()) { // if the dict doesn't have w yet
            dict[w] = std::vector<std::string>(); // intiialize with no anagrams
        } else {
            for (auto it = dict.begin(); it != dict.end(); it++) { // run thru existing dict
                if (check_word(w) == check_word(it->first)) { // if they return the same char maps
                    dict[it->first].push_back(w); // they are anagrams so update dict
                    dict[w] = dict[it->first];
                }
            }
        }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for (std::string w : words) {
        if (dict.find(w) == dict.end()) { // if the dict doesn't have w yet
            dict[w] = std::vector<std::string>(); // intiialize with no anagrams
        }
        for (auto it = dict.begin(); it != dict.end(); it++) { // run thru existing dict
            if (check_word(w) == check_word(it->first)) { // if they return the same char maps
                dict[it->first].push_back(w); // they are anagrams so update dict
                dict[w] = dict[it->first];
        }
        }
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    if (dict.find(word) == dict.end()) {
        return vector<string>();
    }
    return dict.find(word)->second;
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> vect;
    for (auto it = dict.begin(); it != dict.end(); it++) {
        if ((it->second).size() >= 2) {
            vect.push_back(it->second);
        }
    }
    return vect;
}
