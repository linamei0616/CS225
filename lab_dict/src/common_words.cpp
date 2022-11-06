/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        [](int c) {return std::ispunct(c);});
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        /* Your code goes here! */
        
        map<string, unsigned int>word_freq;
        //iterate through every word
        for (std::string word : words) {
            // create a helper function lookup to see if the word already exists in our dict
            if (word_freq.find(word) == word_freq.end()) {
                word_freq[word] = 1;
            } else {
                word_freq[word]++;
            }
            // <map<string, unsigned int>>::iterator lookup = file_word_maps.find(word);
        }
        file_word_maps.push_back(word_freq);
    }
}

void CommonWords::init_common()
{
    /* Your code goes here! */
    for (map<string, unsigned int> word_maps : file_word_maps) { // for every file
        for (auto it = word_maps.begin(); it != word_maps.end(); it++) {
            if (common.find(it->first) == common.end()) {
                common[it->first] = 1;
            } else {
                common[it->first]++;
            }
        }
    } 
}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    /* Your code goes here! */
    map<string, unsigned int> freq; // string = word, unsigned int = # of docs it appeared in
    for (map<string, unsigned int> word_maps : file_word_maps) {
        for (auto it = word_maps.begin(); it != word_maps.end(); it++) {
            if (it->second >= n) {
                freq[it->first]++;
            }
        }
    }
    for (auto it = freq.begin(); it != freq.end(); it++) { // compare the local freq to see if it matches the common, 
                                                           // if so, then all files contain the word >= n times
        if (it->second == common.find(it->first)->second) { 
            out.push_back(it->first);
        }
    }
    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}
